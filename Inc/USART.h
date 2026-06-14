/**
 * filename: USART.h
 * author: Benen Crombie
 *
 * Header for UART.c
 */

#include "main.h"

#define USART1_TX_BUFFER_SIZE (255) // TODO idk
#define USART2_TX_BUFFER_SIZE (255) // 255 bytes should cover everything I need to send
#define USART1_RX_BUFFER_SIZE (255)
#define USART2_RX_BUFFER_SIZE (255)

// I'm defining a endian payload
#define COMMAND_PREAMBLE_HIGH (0x11) // High byte of peamble
#define COMMAND_PREAMBLE_LOW  (0x11) // Low byte of premable

#define COMMAND_POSTAMBLE_HIGH (0x99) // High byte of postamble
#define COMMAND_POSTAMBLE_LOW  (0x99) // Low byte of postamble

// Enum for usart rx sm. Different phases of receiving a command
typedef enum
{
    WAIT_PREAMBLE1,  // waiting for the first premable byte
    WAIT_PREAMBLE2,  // waiting for the second preamble byte
    RECEIVING,       // receiving command data
    WAIT_POSTAMBLE2, // waiting for the last postamble byte, there is a first postamble byte but
                     // that tracked during the receiving state as well in case it's actual command
                     // data
} e_usart2_rx_state;

// Circular buffer struct to grab and transmit bytes for a USART queue
// Bytes will fill up this buffer and loop after the max buffer size.
// Head tracks the position to write data to the queue
// Tail tracks the position to transmit data from the queue through USART
typedef struct
{
    uint8_t buffer[USART1_TX_BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} s_USART1_TxBuffer;

// Circular buffer struct to grab and transmit bytes for a USART queue
// Bytes will fill up this buffer and loop after the max buffer size.
// Head tracks the position to write data to the queue
// Tail tracks the position to transmit data from the queue through USART
typedef struct
{
    uint8_t buffer[USART2_TX_BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} s_USART2_TxBuffer;

// Circular buffer struct to grab the received bytes through ISR
typedef struct
{
    uint8_t buffer[USART1_RX_BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} s_USART1_RxBuffer;

// Circular buffer struct to grab the received bytes through ISR
typedef struct
{
    uint8_t buffer[USART1_RX_BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} s_USART2_RxBuffer;

// Prototypes
void USART_Initialize(void);
void USART2_SendString(char *str);
void USART2_SendInt32(uint32_t value);
void USART2_TickSys(void);
void USART2_InterruptHandler(void);
