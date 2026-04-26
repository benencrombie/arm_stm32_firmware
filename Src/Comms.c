/**
 * filename: Comms.c
 * author: Benen Crombie
 *
 * This module contains all serial comms received over USART (from desktop or raspberry pi).
 * This should end with adding an event to the queue
 */

#include "FSM.h"
#include "GPIO.h"
#include "MotorDriver.h"
#include "USART.h"
#include "main.h"

// Prototypes
static void Command_16(uint8_t *data);
static void Command_19(uint8_t *data);

/**
 * USART Comms TODO move this to a separate module like Comms.c/h, make this FSM module cleaner
 *
 * Big Endian Payload strucutre is as follows:
 * Bytes 0:1 is preamble: 0x1111
 * Bytes 2 is the command type
 * Bytes 3 is the number of data bytes, not including this
 * Bytes 4:N-3 is the command data
 * Bytes N-2:N-1 is postable: 0x9999
 *
 * The preamble and postamble are tackled within the USART module so dont worry about that
 */

/**
 * @brief Decode payload, this is like the middleware of the system. From USART1 (eventually). This
 * function is probably going to be extra beefy so might split it into specific processors depending
 * on the command.
 * @param *evt the fsm event struct with data
 * @return true if commmand successfully processed false if not
 */
void Command_ProcessPayload(s_fsm_event *evt)
{
    // Preamble and postamble already packed, nothing makes it here without those being good.
    if (evt->type != EVENT_PAYLOAD)
    {
        // Shouldn't be called elsewhere
        USART2_SendString("Non payload event passed into command processor");
        return;
    }

    // Dispatch functions for handling different things
    switch (evt->command_id)
    {
        /**
         * Commands 0-15 are not used (no reason tbh, bad vibes)
         */

        /**
         * Commands 16-31 are motor related
         */

        // CMD 16: Single Motor Start. Hex is 0x10
        case 16:
            Command_16(evt->data);
#if DEBUG_COMMS
            USART2_SendString("CMD16 received\r\n");
#endif
            break;

        // Don't use 16 (0x11) because it mighttttt get confused with preamble, idk

        /**
         * Commands 240-255 are not used (no reason tbh, bad vibes)
         */

        // Command not accounted for here
        default:
        {
#if DEBUG_COMMS
            USART2_SendString("Unexpected command type:");
            USART2_SendInt32((uint32_t)evt->command_id);
            USART2_SendString("\r\n");
#endif
            return;
        }
    }

    // Fallthrough, return true because nothing bad happened
    return;
}

/**
 * @brief Command 16: Single Motor Start
 * @param data command data
 * @param number_of_data_bytes self explanatory
 * @return void
 */
static void Command_16(uint8_t *data)
{
    // Byte 0 is packed with the motor to start and direction
    uint8_t first_byte     = data[0];
    uint8_t motor_to_start = (first_byte >> 4) & 0x0F; // Upper bits are motor number
    uint8_t dir            = first_byte & 0x0F;        // Lower bits are direction

    // Bytes 1:2 is the target arr. Motor function calls for 32b to cap upper bounds. This was
    // before I thought that the motor speed would be controlled by the raspberry pi/desktop. I
    // don't think it's worth refactoring right now.
    uint16_t target_arr = (data[1] << 8 | data[2]);

    // Bytes 3:4 are the target steps
    uint16_t target_steps = (data[3] << 8 | data[4]);

    // Start the motor
    Motors_StartMotor(motor_to_start, dir, target_arr, target_steps);

#if DEBUG_COMMS
    USART2_SendString("Start motor: ");
    USART2_SendInt32(motor_to_start);
    USART2_SendString("\r\nDIR: ");
    USART2_SendInt32(dir);
    USART2_SendString("\r\nARR: ");
    USART2_SendInt32(target_arr);
    USART2_SendString("\r\nTarget Steps: ");
    USART2_SendInt32(target_steps);
    USART2_SendString("\r\n");
#endif
}

/**
 * @brief Command 17: MultiMotorStart
 * @param data command data
 * @param number_of_bytes self explanatory
 * @return void
 */
static void Command_19(uint8_t *data)
{
    // TODO later
}