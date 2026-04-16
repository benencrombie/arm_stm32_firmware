/**
 * filename: USART.c
 * author: Benen Crombie
 *
 * UART init and functions.
 * NOTE: Claude made most of this since USART is a common bare metal module
 * My design choice was to use a ring buffer since I don't expect our comms to be 1) a lot or 2)
 * overflow often.
 */

#include "USART.h"
#include "GPIO.h"
#include "main.h"

// TODO eventually use USART1 for SBC comms

// Prototypes

// Inits
s_USART1_TxBuffer USART1_TxRingBuf; // USART1 for raspberry pi comms
s_USART2_TxBuffer USART2_TxRingBuf; // USART2 for debugging

/**
 * USART1
 *
 * Used for comms with the raspberry pi
 */

// TODO should be more or less copy and paste from USART2 modules

/**
 * USART2
 *
 * Used for debugging. Temporarily used for comms with the desktop application through USB, but will
 * later be replaced by wired connections for the raspberry pi's UART
 */

/**
 * @brief Initialize USART2 for debug, TX only
 * @param void
 * @return void
 */
static void USART2_Initialize(void)
{
    // NOTE USART is on the APB1 bus clock (PCLK), which is the low speed peripheral clock.
    // I prescale by 16, making this clock 5.25 MHz

    // Set buffer indices
    USART2_TxRingBuf.head_write = 0;
    USART2_TxRingBuf.tail_tx    = 0;

    // Enable USART2 clock on the APB1
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    (void)RCC->APB1ENR; // read back

    // Refer to 38.8, page 1260, USART registers. Reset value is all registers cleared, but am
    // redundantly clearing pins just to make sure nothing weird happens if I re-init
    USART2->CR1 = 0;
    USART2->CR2 = 0;
    USART2->CR3 = 0;

    // [39.8.4] Configure baud rate
    // PCLK1 is 84 MHz / 16, so 5.25 MHz. OVER8 is cleared
    // I'm targetting a baud of 115200
    // Baud = PCLK1 / USARTDIV -> USARTDIV = PCLK1 / Baud
    // NOTE if I swap to oversampling by 8, Baud = 2 * PCLK1 / USARTDIV
    // Therefore, the BRR register should be set to 5250000 / 115200
    // NOTE: Don't overthink or change this, this works fine and it's tested
    USART2->BRR = 5250000 / 115200;

    // Configure NVIC for interrupts
    NVIC_EnableIRQ(USART2_IRQn);

    // Bit 3: TE, enable the TX
    USART2->CR1 = USART_CR1_TE;

    // [39.8.1] Enable USART again
    USART2->CR1 |= USART_CR1_UE;
}

/**
 * @brief initializes all USART modules
 * @param void
 * @return void
 */
void USART_Initialize(void)
{
    // Init USART1
    // Init USART2
    USART2_Initialize();
    /// Init USART3?
}

/**
 * @brief function to write a byte to teh USART2 circular queue
 * @param data_byte the data to write
 * @return 0 for failed op, 1 for successful op
 */
static bool USART2_AddByteToQueue(uint8_t data_byte)
{
    // Queueing rules:
    // If head equals tail, that means the buffer is empty because write has caught up to tx
    // If head + 1  equals tail, that means the buffer is full because tx can't keep up with write

    // Determine the next write index is, wrapping around the max index
    uint16_t next_write_idx = (USART2_TxRingBuf.head_write + 1) % USART2_TX_BUFFER_SIZE;

    // If the next write index is the transmit index, the queue is full
    if (next_write_idx == USART2_TxRingBuf.tail_tx)
    {
        return false;
    }

    // Update the ring buffer with the new byte if not full
    USART2_TxRingBuf.buffer[USART2_TxRingBuf.head_write] = data_byte;

    // Increment the write index because a new byte has been added
    USART2_TxRingBuf.head_write = next_write_idx;

    // [39.8.1], Bit 7: TXEIE, enable the ineterrupt so TX starts firing stuff
    USART2->CR1 |= USART_CR1_TXEIE; // 1 is enable

    // fall back in case I build out more
    return true;
}

/**
 * @brief function to send a string through USART2 (debug) tx
 * @param void
 * @return voifd
 */
void USART2_SendString(char *str)
{
    while (*str)
    {
        // Add the byte to the queue and go the the next one
        USART2_AddByteToQueue((uint8_t)*str);
        str++;
    }
}

/**
 * @brief Send a uint32_t as ASCII over USART2
 * @param value the number to send
 * @return void
 */
void USART2_SendInt32(uint32_t value)
{
    char buf[11];
    int i = 0;

    // Special case for 0
    if (value == 0)
    {
        USART2_AddByteToQueue('0');
        return;
    }

    // Convert number to string (reverse order)
    while (value > 0)
    {
        buf[i++] = '0' + (value % 10);
        value /= 10;
    }

    // Send in correct order
    while (i > 0)
    {
        USART2_AddByteToQueue(buf[--i]);
    }
}

/**
 * @brief function to handle advancing the USART2 queue. This will go in the IRQ function.
 * @param void
 * @return void
 */
void USART_USART2_IRQHandler(void)
{
    // Claude generated. This works
    if (USART2->SR & USART_SR_TXE)
    {
        if (USART2_TxRingBuf.head_write != USART2_TxRingBuf.tail_tx)
        {
            // Write directly here
            USART2->DR               = USART2_TxRingBuf.buffer[USART2_TxRingBuf.tail_tx];
            USART2_TxRingBuf.tail_tx = (USART2_TxRingBuf.tail_tx + 1) % USART2_TX_BUFFER_SIZE;
        }

        // Disable if buffer now empty
        if (USART2_TxRingBuf.head_write == USART2_TxRingBuf.tail_tx)
        {
            USART2->CR1 &= ~USART_CR1_TXEIE;
        }
    }

    if (USART2->SR & USART_SR_TC)
    {
        USART2->SR &= ~USART_SR_TC;
    }
}