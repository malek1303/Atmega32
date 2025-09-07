#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_int.h"

// takes physical config info as a LED_Type struct
void LED_voidInit (LED_Type LED_config)
{
    DIO_voidSetPinDirection(LED_config.Port, LED_config.Pin, DIO_PIN_OUTPUT);
}

//turns on the led
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

// turns off the led
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

//toggles the led
void LED_voidToggle(LED_Type LED_config)
{
    DIO_voidTogglePinValue(LED_config.Port, LED_config.Pin);
}
