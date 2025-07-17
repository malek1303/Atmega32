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
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_int.h"

void LED_voidInit (LED_Type LED_config)
{
    DIO_voidSetPinDirection(LED_config.Port, LED_config.Pin, DIO_PIN_OUTPUT);
}

void LED_voidOn(LED_Type LED_config)
{
    if(LED_config.Active_State == ACTIVE_HIGH)
    {
        DIO_voidSetPinValue(LED_config.Port, LED_config.Pin, DIO_PIN_HIGH);
    }
    else if(LED_config.Active_State == ACTIVE_LOW)
    {
        DIO_voidSetPinValue(LED_config.Port, LED_config.Pin, DIO_PIN_LOW);
    }
}

void LED_voidOff(LED_Type LED_config)
{
    if(LED_config.Active_State == ACTIVE_HIGH)
    {
        DIO_voidSetPinValue(LED_config.Port, LED_config.Pin, DIO_PIN_LOW);
    }
    else if(LED_config.Active_State == ACTIVE_LOW)
    {
        DIO_voidSetPinValue(LED_config.Port, LED_config.Pin, DIO_PIN_HIGH);
    }
}

void LED_voidToggle(LED_Type LED_config)
{
    DIO_voidTogglePinValue(LED_config.Port, LED_config.Pin);
}
