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

        // CMD 19: Multi Motor Start. Hex is 0x13
        // Used for multimotor motion planning
        case 19:
            Command_19(evt->data);
#if DEBUG_COMMS
            USART2_SendString("CMD19 received\r\n");
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
 * @brief Command 17: MultiMotorStart, start all motors all in one go
 * @param data command data
 * @param number_of_bytes self explanatory
 * @return void
 */
static void Command_19(uint8_t *data)
{
    // Motor selection: first byte is packed with which motors to start (Bits 0:5 for motors 0-5)
    uint8_t first_byte = data[0];

    // Parse each bit to see what motors to start
    bool start_m0 = first_byte & 0x04; // 0000 0100
    bool start_m1 = first_byte & 0x08; // 0000 1000
    bool start_m2 = first_byte & 0x10; // 0001 0000
    bool start_m3 = first_byte & 0x20; // 0010 0000
    bool start_m4 = first_byte & 0x40; // 0100 0000
    bool start_m5 = first_byte & 0x80; // 1000 0000

    // DIR: second byte is packed with the motor DIRs (Bits 0:5 for Motors 0-5)
    uint8_t second_byte = data[1];

    // Inits
    uint8_t motor_dir;
    uint16_t target_arr;
    uint16_t target_steps;

    //////////
    // Motor 0
    //////////

    if (start_m0)
    {
        // Grab the motor direction
        motor_dir = second_byte & 0x04;

        // Bytes 1:2 is the target arr
        target_arr = (data[1] << 8 | data[2]);

        // Bytes 3:4 is target steps
        target_steps = (data[3] << 8 | data[4]);

        // Start motor 0
        Motors_StartMotor(M0, motor_dir, target_arr, target_steps);
    }

    //////////
    // Motor 1
    //////////

    if (start_m1)
    {
        // Grab the motor direction
        motor_dir = second_byte & 0x08;

        // Bytes 5:6 is the target arr
        target_arr = (data[5] << 8 | data[6]);

        // Bytes 7:8 is target steps
        target_steps = (data[7] << 8 | data[8]);

        // Start motor 1
        Motors_StartMotor(M1, motor_dir, target_arr, target_steps);
    }

    //////////
    // Motor 2
    //////////

    if (start_m2)
    {
        // Grab the motor direction
        motor_dir = second_byte & 0x10;

        // Bytes 9:10 is the target arr
        target_arr = (data[9] << 8 | data[10]);

        // Bytes 11:12 is target steps
        target_steps = (data[11] << 8 | data[12]);

        // Start motor 2
        Motors_StartMotor(M2, motor_dir, target_arr, target_steps);
    }

    //////////
    // Motor 3
    //////////

    if (start_m3)
    {
        // Grab the motor direction
        motor_dir = first_byte & 0x20;

        // Bytes 13:14 is the target arr
        target_arr = (data[13] << 8 | data[14]);

        // Bytes 15:16 is target steps
        target_steps = (data[15] << 8 | data[16]);

        // Start motor 3
        Motors_StartMotor(M3, motor_dir, target_arr, target_steps);
    }

    //////////
    // Motor 4
    //////////

    if (start_m4)
    {
        // Grab the motor direction
        motor_dir = first_byte & 0x40;

        // Bytes 17:18 is the target arr
        target_arr = (data[17] << 8 | data[18]);

        // Bytes 19:20 is target steps
        target_steps = (data[19] << 8 | data[20]);

        // Start motor 4
        Motors_StartMotor(M4, motor_dir, target_arr, target_steps);
    }

    //////////
    // Motor 5
    //////////

    if (start_m5)
    {
        // Grab the motor direction
        motor_dir = first_byte & 0x80;

        // Bytes 21:22 is the target arr
        target_arr = (data[21] << 8 | data[22]);

        // Bytes 23:24 is target steps
        target_steps = (data[23] << 8 | data[24]);

        // Start motor 5
        Motors_StartMotor(M5, motor_dir, target_arr, target_steps);
    }
}