/**
 * filename: USART.c
 * author: Benen Crombie
 *
 * UART init and functions. Also includes some abstraction for grabbing Tx data and dumping decoded
 * data to an event queue
 */

#include "USART.h"
#include "Comms.h"
#include "GPIO.h"
#include "main.h"

// TODO eventually use USART1 for SBC comms

// Prototypes

// Inits
s_USART1_TxBuffer USART1_TxRingBuf; // USART1 for raspberry pi comms
s_USART2_TxBuffer USART2_TxRingBuf; // USART2 for debugging
s_USART1_RxBuffer USART1_RxRingBuf; // idk if this will be used
s_USART2_RxBuffer USART2_RxRingBuf; // Used for raspberry pi comms

// USRAT state machine
static e_usart2_rx_state state = WAIT_PREAMBLE1; // Init by waiting for the first preamble byte
static uint8_t usart2_frame_buf[USART2_RX_BUFFER_SIZE + 1];
static uint16_t usart2_frame_len = 0;

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

    // Reset buffer indicies
    USART2_TxRingBuf.head = 0;
    USART2_TxRingBuf.tail = 0;

    USART2_RxRingBuf.head = 0;
    USART2_RxRingBuf.tail = 0;

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

    // Set USART2 priority higher than timers
    NVIC_SetPriority(USART2_IRQn, 0); // 0 is highest

    // Configure NVIC for interrupts
    NVIC_EnableIRQ(USART2_IRQn);

    // CR1: Enable transmit, receive, and RX interrupt
    USART2->CR1 = USART_CR1_TE |    // Transmit enable
                  USART_CR1_RE |    // Receive enable
                  USART_CR1_RXNEIE; // Enable the RX interrupt

    // Claude suggestion, prevents spurious junk on power up
    volatile uint8_t dummy = USART2->DR;
    (void)dummy;

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
    uint16_t next_write_idx = (USART2_TxRingBuf.head + 1) % USART2_TX_BUFFER_SIZE;

    // If the next write index is the transmit index, the queue is full
    if (next_write_idx == USART2_TxRingBuf.tail)
    {
        return false;
    }

    // Update the ring buffer with the new byte if not full
    USART2_TxRingBuf.buffer[USART2_TxRingBuf.head] = data_byte;

    // Increment the write index because a new byte has been added
    USART2_TxRingBuf.head = next_write_idx;

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
 * @brief Tick the USART RX handler at system frequency. Reads rx bytes and picks up on command
 * payloads
 * @param void
 * @return void
 */
void USART2_TickSys(void)
{
    // If the buffer is not full, grab the next byte
    while (USART2_RxRingBuf.tail != USART2_RxRingBuf.head)
    {
        // Grab the byte from the buffer, this is added in interrupt
        uint8_t byte = USART2_RxRingBuf.buffer[USART2_RxRingBuf.tail];

        // Increment tail, looping ring buffer if necessary
        USART2_RxRingBuf.tail = (USART2_RxRingBuf.tail + 1) % USART2_RX_BUFFER_SIZE;

        switch (state)
        {
            // Before scanning for command, scan for the preamble byte.
            case WAIT_PREAMBLE1:
                // Big endian, so expect high byte first
                if (byte == COMMAND_PREAMBLE_HIGH)
                {
                    state = WAIT_PREAMBLE2;
                }
                else
                {
                    // Junk data log it?
                    USART2_SendString("Junk USART while waiting for first preamble\r\n");
                }
                break;

            case WAIT_PREAMBLE2:
                // Scan for second preamble byte
                if (byte == 0x11)
                {
                    // Start counting the length of the frame and swap to receiving state
                    state            = RECEIVING;
                    usart2_frame_len = 0;
                }
                // Unexpected byte, go back to waiting for the first again
                else
                {
                    // Junk data, log it?
                    USART2_SendString("Junk USART while waiting for second preamble\r\n");
                    state = WAIT_PREAMBLE1;
                }
                break;

            case RECEIVING:
                // This is the first postamble byte
                // TODO maybe it could be actual payload data, maybe just save this as a temp var
                if (byte == 0x99)
                {
                    // Wait for the second postamble byte
                    state = WAIT_POSTAMBLE2;
                }
                else
                {
                    // Try to add the byte to the frame buffer
                    if (usart2_frame_len < sizeof(usart2_frame_buf))
                    {
                        usart2_frame_buf[usart2_frame_len++] = byte;
                    }
                    else
                    {
                        // Overflow, log and reset/wait for new command
                        USART2_SendString("USART2 frame buf overflow\r\n");
                        state = WAIT_PREAMBLE1;
                    }
                }
                break;

            case WAIT_POSTAMBLE2:
                // After second postamble byte is comfirmed, just decode the payloads
                if (byte == 0x99)
                {
#if DEBUG_USART_RX
                    USART2_SendString("Received a full command, processing now!\r\n");
#endif
                    // Decode the payload, this function should unpack it and create an event with
                    // struct data appended
                    Command_ProcessPayload(usart2_frame_buf, usart2_frame_len);
                }
                // If teh second postamble byte isnt received, junk data
                else
                {
                    USART2_SendString("Junk USART waiting for second postamble byte\r\n");
                }

                // Either way reset
                state = WAIT_PREAMBLE1;
                break;
        }
    }
}

/**
 * @brief function to handle advancing the USART2 queue. This will go in the IRQ function.
 * @param void
 * @return void
 */
void USART2_InterruptHandler(void)
{
    // Receive byte
    if (USART2->SR & USART_SR_RXNE)
    {
        // Read the data register, this clears RXNE
        uint8_t rx_data = USART2->DR;

        // Get the next index of the ring buffer
        uint16_t next_idx = (USART2_RxRingBuf.head + 1) % USART2_RX_BUFFER_SIZE;

        // Check if the buffer is not full yet. I might also implement some control on the raspberry
        // pi side to not fire too many commands too fast
        if (next_idx != USART2_RxRingBuf.tail)
        {
            // Add byte to dat buffer
            USART2_RxRingBuf.buffer[USART2_RxRingBuf.head] = rx_data;

            // Increment the head
            USART2_RxRingBuf.head = next_idx;
        }

        // The RX buffer is full. I think I can just log it through TX lol
        else
        {
            USART2_SendString("USART2 Rx Buffer Full\r\n");
        }
    }

    // Transmit byte
    if (USART2->SR & USART_SR_TXE)
    {
        if (USART2_TxRingBuf.head != USART2_TxRingBuf.tail)
        {
            // Write directly here
            USART2->DR            = USART2_TxRingBuf.buffer[USART2_TxRingBuf.tail];
            USART2_TxRingBuf.tail = (USART2_TxRingBuf.tail + 1) % USART2_TX_BUFFER_SIZE;
        }

        // Disable if buffer now empty
        if (USART2_TxRingBuf.head == USART2_TxRingBuf.tail)
        {
            USART2->CR1 &= ~USART_CR1_TXEIE;
        }
    }

    if (USART2->SR & USART_SR_TC)
    {
        USART2->SR &= ~USART_SR_TC;
    }
}