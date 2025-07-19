
#include "STD_TYPES.h"
#ifndef SEG_INTERFACE_H_
#define SEG_INTERFACE_H_

#define SEG_COMMON_CATHODE 0
#define SEG_COMMON_ANODE 1

#define SEG_PIN0 0
#define SEG_PIN1 1
#define SEG_PIN2 2
#define SEG_PIN3 3
#define SEG_PIN4 4
#define SEG_PIN5 5
#define SEG_PIN6 6
#define SEG_PIN7 7

#define SEG_PORTA 0
#define SEG_PORTB 1
#define SEG_PORTC 2
#define SEG_PORTD 3

typedef struct
{
    u8 Type;
    u8 DataPort;
    u8 EnablePort;
    u8 EnablePin;
}SEG_Type;

void SEG_voidInitialDataPort (SEG_Type structconfig);
void SEG_voidSendNumber(SEG_Type structconfig, u8 Number);
void SEG_voidEnable(SEG_Type segconfig);
void SEG_voidDisable(SEG_Type segconfig);

#endif