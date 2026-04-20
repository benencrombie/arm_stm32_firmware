/**
 * filename: Comms.c
 * author: Benen Crombie
 *
 * This module contains all serial comms received over USART (from desktop or raspberry pi)
 */

#include "FSM.h"
#include "GPIO.h"
#include "MotorDriver.h"
#include "USART.h"
#include "main.h"

// Prototypes
static void Command_16(uint8_t *data);
static void Command_17(uint8_t *data);

/**
 * USART Comms TODO move this to a separate module like Comms.c/h, make this FSM module cleaner
 *
 * Big Endian Payload strucutre is as follows:
 * Bytes 0:1 is preamble: 0x1111
 * Bytes 2 is the command type
 * Bytes 3 is the number of data bytes, not including this
 * Bytes 4:N-3 is the command data
 * Bytes N-2:N-1 is postable: 0x9999
 */

/**
 * @brief Decode payload, this is like the middleware of the system. From USART1 (eventually). This
 * function is probably going to be extra beefy so might split it into specific processors depending
 * on the command... like put all start motor commands into their own function, etc.
 * @param *command_buffer pointer to the command data
 * @param number_of_bytes the total number of bytes in the command
 * @return true if commmand successfully processed false if not
 */
bool Command_ProcessPayload(uint8_t *command_buffer, uint8_t number_of_bytes)
{
    // Bytes 0:1 is the preamble
    uint16_t preamble = ((uint16_t)command_buffer[0] << 8) | (uint16_t)command_buffer[1];

    // Bytes N-2:N-1 is the postamble (last two)
    uint16_t postamble = ((uint16_t)(command_buffer[number_of_bytes - 2]) << 8) |
                         (uint16_t)command_buffer[number_of_bytes - 1];

    // If the preamble is garbo, exit and log
    if (preamble != COMMAND_PREAMBLE)
    {
#if DEBUG_COMMS
        USART2_SendString("Trash command preamble");
#endif
        return false;
    }

    // If the postamble is garbo, exit and log
    if (postamble != COMMAND_POSTAMBLE)
    {
#if DEBUG_COMMS
        USART2_SendString("Trash command postamble");
#endif
        return false;
    }

    // Now start cooking with specific commands.
    // Byte 2 is the specific command
    uint8_t command = command_buffer[2];

    // Byte 3 is the number of data bytes, not including this byte
    uint8_t num_data_bytes = command_buffer[3];

    // Bytes 4 through N-3 is the command data, just pass a pointer of index 4 along
    uint8_t *command_data = &command_buffer[4];

    // Check if we are getting the expected number of bytes.
    // 6 overhead bytes: preamble (2), command ID (1), num data bytes (1) and postamble (2)
    // This doesn't have much use other than error checking since commands are set numbers of bytes
    if (num_data_bytes != number_of_bytes - 6)
    {
#if DEBUG_COMMS
        USART2_SendString("Command num data bytes mismatch");
#endif
        return false;
    }

    // Dispatch functions for handling different things
    switch (command)
    {
        /**
         * Commands 0-15 are not used (no reason tbh, bad vibes)
         */

        /**
         * Commands 16-31 are motor related
         */

        // CMD 16: Single Motor Start
        case 16:
            Command_16(command_data);
#if DEBUG_COMMS
            USART2_SendString("CMD16 received");
#endif
            break;

        // CMD 17: Multi Motor Start
        case 17:
            Command_17(command_data);
#if DEBUG_COMMS
            USART2_SendString("CMD17 received");
#endif
            break;

        /**
         * Commands 240-255 are not used (no reason tbh, bad vibes)
         */

        // Command not accounted for here
        default:
        {
#if DEBUG_COMMS
            USART2_SendString("Unexpected command type:");
            USART2_SendInt32((uint32_t)command);
#endif
            return false;
        }
    }

    // Fallthrough, return true because nothing bad happened
    return true;
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
static void Command_17(uint8_t *data)
{
    // TODO later
}