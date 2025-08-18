#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_int.h"
#include "CLCD_private.h"


void CLCD_voidSendData (u8 Data)
{
    #if CLCD_MODE == 8 
    DIO_voidSetPortValue(CLCD_DATA_PORT , Data);
    DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_HIGH);
    DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);
    CLCD_voidSendFallingEdge();
    #elif CLCD_MODE == 4
    
    #endif
    _delay_ms(1);
} 

static void CLCD_voidSendFallingEdge(void)
{
    DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_LOW);
    _delay_ms(1);
}