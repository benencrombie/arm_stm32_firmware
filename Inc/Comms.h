/**
 * filename: Comms.h
 * author: Benen Crombie
 *
 * Header file for Comms.c
 */

#include "main.h"

// Payload defines
#define COMMAND_PREAMBLE  (0x1111)
#define COMMAND_POSTAMBLE (0x9999)

// Prototypes
void Command_ProcessPayload(s_fsm_event *evt);
