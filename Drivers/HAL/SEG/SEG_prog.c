#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SEG_interface.h"
#include "SEG_private.h"
#include "SEG_config.h"

static u8 Local_SEGNumbers[10] = SEG_NUMBER_ARR; // numbers from 0 -- 9 to be used on the 7SEG

// takes initial hardware config as a SEG_Type struct
void SEG_voidInitialDataPort (SEG_Type structconfig)
{
    DIO_voidSetPortDirection(structconfig.DataPort, 0xff);
}

//outputs the desiered num on the 7SEG
void SEG_voidSendNumber(SEG_Type structconfig, u8 Number)
{
    if(structconfig.Type == SEG_COMMON_CATHODE)
    {
        DIO_voidSetPortValue(structconfig.DataPort, Local_SEGNumbers[Number]);
    }
    else if(structconfig.Type == SEG_COMMON_ANODE)
    {
        DIO_voidSetPortValue(structconfig.DataPort, ~ Local_SEGNumbers[Number]);
    } 
}

// enables the 7SEG display by outputing on the 7seg enable pin according to the config in the SEG_Type struct
void SEG_voidEnable(SEG_Type segconfig)
{
    if(segconfig.Type == SEG_COMMON_CATHODE)
    {
        DIO_voidSetPinDirection(segconfig.EnablePort,segconfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_voidSetPinValue(segconfig.EnablePort,segconfig.EnablePin,DIO_PIN_LOW);
    }
    if(segconfig.Type == SEG_COMMON_ANODE)
    {
        DIO_voidSetPinDirection(segconfig.EnablePort,segconfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_voidSetPinValue(segconfig.EnablePort,segconfig.EnablePin,DIO_PIN_HIGH);
    }
}

// Disables the 7SEG display by outputing on the 7seg enable pin according to the config in the SEG_Type struct
void SEG_voidDisable(SEG_Type segconfig)
{
    if(segconfig.Type == SEG_COMMON_CATHODE)
    {
        DIO_voidSetPinDirection(segconfig.EnablePort,segconfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_voidSetPinValue(segconfig.EnablePort,segconfig.EnablePin,DIO_PIN_HIGH);
    }
    if(segconfig.Type == SEG_COMMON_ANODE)
    {
        DIO_voidSetPinDirection(segconfig.EnablePort,segconfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_voidSetPinValue(segconfig.EnablePort,segconfig.EnablePin,DIO_PIN_LOW);
    }
}