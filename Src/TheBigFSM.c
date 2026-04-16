/**
 * filename: TheBigFSM.c
 * author: Benen Crombie
 *
 * This module will dictate what goes on for high level events or triggers. This module will bridge
 * the smaller fsms together
 */

#include "TheBigFSM.h"
#include "GPIO.h"
#include "MotorDriver.h"
#include "USART.h"
#include "main.h"

// Prototypes
static void Command_16(uint8_t *data, uint8_t number_of_data_bytes);
static void Command_17(uint8_t *data, uint8_t number_of_data_bytes);

/**
 * USART Comms
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
static bool Command_ProcessPayload(uint8_t *command_buffer, uint8_t number_of_bytes)
{
    // Bytes 0:1 is the preamble
    uint16_t preamble = ((uint16_t)command_buffer[0] << 8) | (uint16_t)command_buffer[1];

    // Bytes N-2:N-1 is the postamble (last two)
    uint16_t postamble = ((uint16_t)(command_buffer[number_of_bytes - 2]) << 8) |
                         (uint16_t)command_buffer[number_of_bytes - 1];

    // If the preamble is garbo, exit and log
    if (preamble != COMMAND_PREAMBLE)
    {
#ifdef DEBUG_FSM
        USART2_SendString("Trash command preamble");
#endif
        return false;
    }

    // If the postamble is garbo, exit and log
    if (postamble != COMMAND_POSTAMBLE)
    {
#ifdef DEBUG_FSM
        USART2_SendString("Trash command postamble");
#endif
        return false;
    }

    // Now start cooking with specific commands.
    // Byte 2 is the specific command
    uint8_t command = command_buffer[2];

    // Byte 3 is the number of data bytes, inot including this byte
    uint8_t num_data_bytes = command_buffer[3];

    // Bytes 4 through N-3 is the command data, just pass a pointer of index 4 along
    uint8_t *command_data = &command_buffer[4];

    // Check if we are getting the expected number of bytes.
    // 6 overhead bytes: preamble (2), command ID (1), num data bytes (1) and postamble (2)
    if (num_data_bytes != number_of_bytes - 6)
    {
#ifdef DEBUG_FSM
        USART2_SendString("Command num data bytes mismatch");
#endif
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
            // Call CMD 16 with pointer to command data
            Command_16(command_data, num_data_bytes);
#ifdef DEBUG_FSM_VERBOSE
            USART2_SendString("CMD16 received");
#endif
            break;

        // CMD 17: Multi Motor Start
        case 17:
#ifdef DEBUG_FSM_VERBOSE
            USART2_SendString("CMD17 received");
#endif
            break;

        /**
         * Commands 240-255 are not used (no reason tbh, bad vibes)
         */

        // Command not accounted for here
        default:
        {
#ifdef DEBUG_FSM
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
static void Command_16(uint8_t *data, uint8_t number_of_data_bytes)
{
    // TODO now
}

/**
 * @brief Command 17: MultiMotorStart
 * @param data command data
 * @param number_of_bytes self explanatory
 * @return void
 */
static void Command_17(uint8_t *data, uint8_t number_of_data_bytes)
{
    // TODO later
}

/**
 * FSM
 *
 * Handles high level decisions of the system. Mainly coming from USART comms for now, but maybe
 * will incorporate some sensors, LEDs, screens, etc. in the future. Decisions requiring higher
 * levels of processing (e.g., voice commands/vision) will be handled by the pi, so this could be
 * pretty minimal.
 */

void FSM_Initialize(void)
{
}

void FSM_Tick1000Hz(void)
{
}