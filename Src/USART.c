/**
 * filename: USART.c
 * author: Benen Crombie
 *
 * UART init and functions
 */

#include "USART.h"
#include "GPIO.h"
#include "main.h"

/**
 * @brief Initialize gpios for UART
 * @param void
 * @return void
 */
void USART_Initialize(void)
{
    // Enable USART2 clock on the APB1 bus
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // Refer to 38.8, page 1260, USART registers. Reset value is all registers cleared, but am
    // redundantly clearing pins just to make sure nothing weird happens if I re-init

    // [39.8.1] UE, first ensure that USART is disabled to config baud rate, enable later
    USART->CR1 &= ~USART_CR1_UE; // 0 is disabled

    // [38.9.1] OVER8, overasampling
    USART->CR1 &= ~USART_CR1_OVER8; // 0 is oversample by 16

    // [39.8.4] Configure baud rate
    // SYSCLK is 84 MHz. OVER8 is cleared
    // I'm targetting a baud of 115200
    // Baud = SYSCLK / USARTDIV -> USARTDIV = SYSCLK / Baud
    // NOTE if I swap to oversampling by 8, Baud = 2 * SYSCLK / USARTDIV
    // Therefore, the BRR register should be set to 84000000 / 115200 = 729.166 (repeating)
    // USARTDIV = Mantissa + (frac/16)
    USART2->BRR |= (729 << 4); // Bits 15:4 is the mantissa
    USART2->BRR |= (3);        // Bits 3:0 is the fraction (x16 since OVER8 is cleared)

    // [38.9.1], CR1

    // Bit 7: TXEIE, enable the ineterrupt
    USART->CR1 |= USART_CR1_TXEIE; // 1 is enable

    // Bit 6, do I need TCIE, transmit complete interrupt? Idk

    // Bit 3: TE, enable the TX
    USART2->CR1 |= USART_CR1_TE;

    // No need to touch CR2 or CR3?

    // [39.8.1] Enable USART again
    USART->CR1 |= USART_CR1_UE; // 1 is enable
}

void USART2

    /**
     * @brief function to handle advancing the UART queue
     * @param void
     * @return void
     */
    void
    UART_USART2_IRQHandler(void)
{
    // TODO make this. idk how yet
}

// typedef struct
// {
//     __IO uint32_t SR;
//     __IO uint32_t DR;
//     __IO uint32_t BRR;
//     __IO uint32_t CR1;
//     __IO uint32_t CR2;
//     __IO uint32_t CR3;
//     __IO uint32_t GTPR;
// } USART_TypeDef;