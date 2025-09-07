#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"

void SW_voidInit (SW_Type sw_config) //before init you must create a switch config from a SW_Type struct
{
    DIO_voidSetPinDirection(sw_config.Port, sw_config.Pin, DIO_PIN_INPUT);
    DIO_voidConnectPullup(sw_config.Port, sw_config.Pin, sw_config.PullState);
}

//checks if switch is pressed then returns a u8 as a boolean
u8 SW_u8Pressed (SW_Type sw_config)
{
    u8 PinValue = DIO_u8GetPinValue(sw_config.Port, sw_config.Pin);

    if((sw_config.PullState == SW_INT_PULL_UP) || (sw_config.PullState == SW_EXT_PULL_UP))
    {
        if (PinValue == 0)
        {
            return SW_PRESSED;
        }
        else if (PinValue == 1)
        {
            return SW_NOT_PRESSED;
        }
    }
    
    else if (sw_config.PullState == SW_EXT_PULL_UP)
    {
        if (PinValue == 1)
        {
            return SW_PRESSED;
        }
        else if (PinValue == 0)
        {
            return SW_NOT_PRESSED;
        }
    }
}