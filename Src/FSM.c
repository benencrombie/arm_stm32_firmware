/**
 * filename: FSM.c
 * author: Benen Crombie
 *
 * This module will dictate what goes on for high level events or triggers. This module will bridge
 * the smaller fsms together
 *
 * Architecture:
 * Tick at 1 Hz: drives sub fsms
 * Tick at 1000 Hz: drives sub fsms and handles state transitions
 * Tick at System Hz (84 MHz): drives sub fsms
 */

#include "FSM.h"
#include "GPIO.h"
#include "MotorDriver.h"
#include "USART.h"
#include "main.h"

// Inits
e_fsm_state curr_fsm_state = STATE_IDLE;
e_fsm_event curr_fsm_event = EVENT_NONE;

// Set up the fsm context, for broader use, any module can add an event to the queue. I'll try to
// document where stuff is called though since this can get messy. Most events will probably be
// generated from USART comms (incoming payloads from the raspberry pi), so a lot of this should be
// contained. Other modules that I can think of are events being generated from the motors when
// stuff breaks.
fsm_context fsm;

/**
 * FSM
 *
 * Handles high level decisions of the system. Mainly coming from USART comms for now, but maybe
 * will incorporate some sensors, LEDs, screens, etc. in the future. Decisions requiring higher
 * levels of processing (e.g., voice commands/vision) will be handled by the pi, so this could be
 * pretty minimal.
 */

/**
 * @brief Public API to post an event to the FSM queue, this can be called anywhere, in the system.
 * @param evt an event to add to the queue
 * @return void
 */
void FSM_AddEventToQueue(e_fsm_event evt)
{
    // If the event queue is full, don't do anything and just log it
    if (fsm.queue.count >= FSM_EVENT_QUEUE_SIZE)
    {
        USART2_SendString("Event queue full");
        return;
    }

    // Add the event to the queue
    fsm.queue.buf[fsm.queue.tail] = evt;

    // Loop the ring buffer if needed
    fsm.queue.tail = (fsm.queue.tail + 1) % FSM_EVENT_QUEUE_SIZE;

    // Increment the tracked buf size
    fsm.queue.count++;
}

/**
 * @brief Function to pop an event from the fifo queue
 * @param event_out pointer to the popped event, used when calling this function
 * @return false for no event grabbed, true for an event was grabbed
 */
static bool FSM_GrabEventFromQueue(e_fsm_event *event_out)
{
    // If the queue is empty, there are no events to be grabbed
    if (fsm.queue.count == 0)
    {
        return false;
    }

    // Pop an event from the head of the queue (fifo)
    *event_out = fsm.queue.buf[fsm.queue.head];

    // Advance the queue indexing (ring buffer)
    fsm.queue.head = (fsm.queue.head + 1) % FSM_EVENT_QUEUE_SIZE;

    // Decrement the tracked buf size
    fsm.queue.count--;

    return true;
}

/**
 * @brief Function to transition states, raising the entry flag
 * @param next_state the state to transition to
 * @return void
 */
static void FSM_TransitionState(e_fsm_state next_state)
{
    // Set the next state
    fsm.state = next_state;

    // Reset the state timer
    fsm.stateCounter = 0;

    // Set the entry flag to true, handlers should clear this flag
    fsm.entryFlag = true;

#if DEBUG_FSM
    USART2_SendString("Entering State: ");
    USART2_SendInt32(next_state);
    USART2_SendString("\r\n");
#endif
}

/**
 * @brief Initialize the finite state machine
 * @param void
 * @return void
 */
void FSM_Initialize(void)
{
    // Start off idle
    fsm.state = STATE_IDLE;

    // Start off with an entry flag to fire up the init sequence
    fsm.entryFlag = true;

    // Set the state timer to 0
    fsm.stateCounter = 0;
}

/**
 * @brief Tick the FSM every second
 * @param void
 * @return void
 */
void FSM_Tick1Hz(void)
{
    switch (fsm.state)
    {
        case STATE_IDLE:
        {
            break;
        }
        case STATE_RUNNING:
        {
            /**
             * Handle all sub fsms
             */

            // Toggle an LED to show that teh system is running.
            GPIO_ToggleTestPin();

            break;
        }
        case STATE_DISABLED:
        {
            break;
        }
        case STATE_FAULT:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

/**
 * @brief Tick the FSM every millisecond, note that all state transitions are handled here
 * @param void
 * @return void
 */
void FSM_Tick1000Hz(void)
{
    switch (fsm.state)
    {
        case STATE_IDLE:
        {
            // Handle IDLE entry actions, don't think anything needed here
            if (fsm.entryFlag)
            {
                // Set flag to false
                fsm.entryFlag = false;

                // Just start a motor here, but this will eventually be event driven
                Motors_StartMotor(
                    M0, 0, 599,
                    1000); // NOTE I cant drive the beefy NEMA17 that fast.
                           // Maybe cap this in raspberry pi/desktop. I THINK THIS THE MAX LOWKEY

                // I think I want this to be a pushbutton or something in the future, but just go to
                // running off rip
                FSM_TransitionState(STATE_RUNNING);
            }

            break;
        }
        case STATE_RUNNING:
        {
            if (fsm.entryFlag)
            {
                // Set the flag to false
                fsm.entryFlag = false;

                // TODO any actions?
            }

            /**
             * Handle all sub fsms
             */

            // Update motors
            Motors_FSM_Tick1000Hz();

            break;
        }
        case STATE_DISABLED:
        {
            if (fsm.entryFlag)
            {
                // Set the flag to false
                fsm.entryFlag = false;

                // TODO any actions?
            }

            break;
        }
        case STATE_FAULT:
        {
            if (fsm.entryFlag)
            {
                // Set the flag to false
                fsm.entryFlag = false;

                // TODO any actions?
            }

            break;
        }
        default:
        {
            break;
        }
    }

    // Increment state coutner
    fsm.stateCounter++;
}

/**
 * @brief Tick the FSM at system tick (84 MHz)
 * @param void
 * @return void
 */
void FSM_TickSys(void)
{
    switch (fsm.state)
    {
        case STATE_IDLE:
        {

            break;
        }
        case STATE_RUNNING:
        {
            /**
             * Handle all sub fsms
             */
            break;
        }
        case STATE_DISABLED:
        {
            break;
        }
        case STATE_FAULT:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}