#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SEG_interface.h"
#include "SEG_private.h"
#include "SEG_config.h"

static u8 Local_SEGNumbers[10] = SEG_NUMBER_ARR;

void SEG_voidInitialDataPort (SEG_Type structconfig)
{
    DIO_voidSetPortDirection(structconfig.DataPort, 0xff);
}

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