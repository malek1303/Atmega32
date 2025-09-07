#include "CPU_Freq.h"
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_int.h"
#include "CLCD_private.h"
#include "CLCD_ExtraChar.h"

// automaic initialization based on info in CLCD_config.h
void CLCD_voidInit(void)
{
    #if CLCD_MODE == 8
    
    _delay_ms(50);
    DIO_voidSetPortDirection(CLCD_DATA_PORT, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_OUTPUT);

    CLCD_voidSendCommand(lcd_Home);
    _delay_ms(1);

    CLCD_voidSendCommand(EIGHT_BITS);
    _delay_ms(1);
    
    CLCD_voidSendCommand(lcd_DisplayOn_CursorOff);
    _delay_ms(1);

    CLCD_voidClearScreen();

    CLCD_voidSendCommand(lcd_EntryMode);
    _delay_ms(1);


    #elif CLCD_MODE == 4
    #endif
}

//sends char to lcd (input needs to be in ASCII)
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

//sends command (all commands are avalible as macros)
void CLCD_voidSendCommand(u8 Command)
{
    #if CLCD_MODE == 8 
    DIO_voidSetPortValue(CLCD_DATA_PORT , Command);
    DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_LOW);
    DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);
    CLCD_voidSendFallingEdge();
    #elif CLCD_MODE == 4
    
    #endif
    _delay_ms(1);
}

//sends string to lcd (input MUST be an pointer to array)
void CLCD_voidSendString(const u8 *stringptr)
{
    u8 loc_counter = 0;
    while (stringptr[loc_counter]!='\0')
    {
        CLCD_voidSendData(stringptr[loc_counter]);
        loc_counter++;
    }
    _delay_ms(1);
    
}

// sets position of the cursor (row,col)
void CLCD_voidSetPosition(u8 row, u8 col)
{
    u8 loc_data;

    if(row > 2 || row < 1 || col > 16 || col < 1)
    {
        loc_data = lcd_SetCursor;
    }
    
    else if (row == CLCD_ROW_1)
    {
        loc_data = ((lcd_SetCursor)+(col - 1));
    }
    
    else if (row == CLCD_ROW_2)
    {
        loc_data = ((lcd_SetCursor)+ (64) +(col - 1));
    }
    CLCD_voidSendCommand(loc_data);
    _delay_ms(1);
}

//sends extra char from CLCD_ExtraChar.h 
void CLCD_voidSendExtraChar( u8 Row , u8 Col )
{
	u8 loc_counter = 0 ;

	CLCD_voidSendCommand( lcd_CGRAM );

	for( loc_counter = 0 ; loc_counter < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) ; loc_counter++){

		CLCD_voidSendData( CLCD_u8ExtraChar[loc_counter] );

	}
}

//sends falling edge to lcd
static void CLCD_voidSendFallingEdge(void)
{
    DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_LOW);
    _delay_ms(1);
}

//cleares the clcd
void CLCD_voidClearScreen(void)
{
    CLCD_voidSendCommand(lcd_Clear);
    _delay_ms(10);
}