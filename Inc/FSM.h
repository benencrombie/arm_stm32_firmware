/**
 * filename: FSM.h
 * author: Benen Crombie
 *
 * Header for FSM.c
 */

#include "main.h"

// Defines
#define FSM_EVENT_QUEUE_SIZE (16)

// Payload defines
#define COMMAND_PREAMBLE  (0x1111)
#define COMMAND_POSTAMBLE (0x9999)

// Enum FSM states
typedef enum
{
    STATE_IDLE,
    STATE_RUNNING,
    STATE_DISABLED,
    STATE_FAULT,

} e_fsm_state;

// Enum FSM events
typedef enum
{
    EVENT_NONE,
    EVENT_STARTSYS,
    EVENT_ENABLEMOTORS,
} e_fsm_event;

// Event queue, ring buffer
typedef struct
{
    e_fsm_event buf[FSM_EVENT_QUEUE_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} s_fsm_event_queue;

// FSM context used in the broader system
typedef struct
{
    e_fsm_state state;
    s_fsm_event_queue queue;
    uint32_t stateCounter; // incorporating this for future timeouts/blinking status LEDs
    bool entryFlag;        // flipped on a state transitions, used to handle once per state actions
} fsm_context;

// Make this struct public
extern fsm_context fsm;

// Prototypes
void FSM_AddEventToQueue(e_fsm_event evt);
void FSM_Initialize(void);
void FSM_Tick1Hz(void);
void FSM_Tick1000Hz(void);
void FSM_TickSys(void);
