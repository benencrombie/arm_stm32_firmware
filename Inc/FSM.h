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
    STATE_IDLE,      // For debugging, this is 0
    STATE_READY,     // 1
    STATE_HOMING,    // 2
    STATE_FREEDRIVE, // 3
    STATE_DISABLED,  // 4
    STATE_FAULT,     // 5

} e_fsm_state;

// Enum FSM events
typedef enum
{
    EVENT_NONE,
    EVENT_HOMING_COMPLETE,
    EVENT_JEFFBUTTONPRESS,
    EVENT_TODDBUTTONPRESS,
    EVENT_BARTBUTTONPRESS,
} e_fsm_event;

// ENUM event struct, includes decoded payload junk

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
    uint32_t state_counter; // incorporating this for future timeouts/blinking status LEDs
    bool entry_flag;        // flipped on a state transitions, used to handle once per state actions
} fsm_context;

// Make this struct public
extern fsm_context fsm;

// Prototypes
void FSM_AddEventToQueue(e_fsm_event evt);
void FSM_Initialize(void);
void FSM_Tick1Hz(void);
void FSM_Tick1000Hz(void);
void FSM_TickSys(void);
