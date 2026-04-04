/**
 * filename: USART.h
 * author: Benen Crombie
 *
 * Header for UART.c
 */

#include "main.h"

#define USART2_TX_BUFFER_SIZE (255) // 255 bytes should cover everything I need to send

// Circular buffer struct to grab and transmit bytes for a USART queue
// Bytes will fill up this buffer and loop after the max buffer size.
// Head tracks the position to write data to the queue
// Tail tracks the position to transmit data from the queue through USART
typedef struct
{
    uint8_t buffer[USART2_TX_BUFFER_SIZE];
    volatile uint16_t head_write;
    volatile uint16_t tail_tx;
} s_USART2_TxBuffer;

// Prototypes
void USART_Initialize(void);
void USART2_SendString(char *str);
void USART_USART2_IRQHandler(void);