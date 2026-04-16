/**
 * filename: TheBigFSM.h
 * author: Benen Crombie
 *
 * Header for TheBigFSM.c
 */

#include "main.h"

// Payload defines
#define COMMAND_PREAMBLE  (0x1111)
#define COMMAND_POSTAMBLE (0x9999)

// Enum FSM states

// Enum FSM events

// Prototypes
void FSM_Initialize(void);
void FSM_Tick1000Hz(void);