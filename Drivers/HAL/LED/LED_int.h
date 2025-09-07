#include "STD_TYPES.h"
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

//Config info about the led
typedef struct
{
    u8 Port;
    u8 Pin;
    u8 Active_State;
}LED_Type;

void LED_voidInit (LED_Type LED_config);
void LED_voidOn(LED_Type LED_config);
void LED_voidOff(LED_Type LED_config);
void LED_voidToggle(LED_Type LED_config);

#endif