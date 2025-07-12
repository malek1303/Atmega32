/*
 ___ __ __   ________   ______   ______        _______   __  __     ___ __ __   ________   __       ______   ___   ___     
/__//_//_/\ /_______/\ /_____/\ /_____/\     /_______/\ /_/\/_/\   /__//_//_/\ /_______/\ /_/\     /_____/\ /___/\/__/\    
\::\| \| \ \\::: _  \ \\:::_ \ \\::::_\/_    \::: _  \ \\ \ \ \ \  \::\| \| \ \\::: _  \ \\:\ \    \::::_\/_\::.\ \\ \ \   
 \:.      \ \\::(_)  \ \\:\ \ \ \\:\/___/\    \::(_)  \/_\:\_\ \ \  \:.      \ \\::(_)  \ \\:\ \    \:\/___/\\:: \/_) \ \  
  \:.\-/\  \ \\:: __  \ \\:\ \ \ \\::___\/_    \::  _  \ \\::::_\/   \:.\-/\  \ \\:: __  \ \\:\ \____\::___\/_\:. __  ( (  
   \. \  \  \ \\:.\ \  \ \\:\/.:| |\:\____/\    \::(_)  \ \ \::\ \    \. \  \  \ \\:.\ \  \ \\:\/___/\\:\____/\\: \ )  \ \ 
    \__\/ \__\/ \__\/\__\/ \____/_/ \_____\/     \_______\/  \__\/     \__\/ \__\/ \__\/\__\/ \_____\/ \_____\/ \__\/\__\/ 
  */  
#include "STD_TYPES.h"
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


void DIO_voidSetPinDirection(u8 port, u8 pin, u8 dir);
void DIO_voidSetPinValue(u8 port, u8 pin, u8 value);
u8   DIO_u8GetPinValue(u8 port, u8 pin);
void DIO_voidTogglePinValue(u8 port, u8 pin);

void DIO_voidSetPortDirection(u8 port, u8 dir);
void DIO_voidSetPortValue(u8 port, u8 value);
u8   DIO_u8GetPortValue(u8 port);
void DIO_voidTogglePortValue(u8 port);



#endif // DIO_INTERFACE_H