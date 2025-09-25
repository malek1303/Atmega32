#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KPD_int.h"
#include "KPD_priv.h"
#include "KPD_config.h"

//initializes Keypad defaults. change the defaults from KPD_config.h 
void KPD_init(void)
{
    DIO_voidConnectPullup(KPD_PORT,KPD_R0,DIO_PIN_HIGH);
    DIO_voidConnectPullup(KPD_PORT,KPD_R1,DIO_PIN_HIGH);
    DIO_voidConnectPullup(KPD_PORT,KPD_R2,DIO_PIN_HIGH);
    DIO_voidConnectPullup(KPD_PORT,KPD_R3,DIO_PIN_HIGH);

    DIO_voidSetPinDirection(KPD_PORT,KPD_C0,DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_C1,DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_C2,DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_C3,DIO_PIN_OUTPUT);

    DIO_voidSetPinValue(KPD_PORT,KPD_C0,DIO_PIN_HIGH);
    DIO_voidSetPinValue(KPD_PORT,KPD_C1,DIO_PIN_HIGH);
    DIO_voidSetPinValue(KPD_PORT,KPD_C2,DIO_PIN_HIGH);
    DIO_voidSetPinValue(KPD_PORT,KPD_C3,DIO_PIN_HIGH);

}

// returns which keypad button is pressed as a u8 ascii
u8 KPD_u8GetPressed(void)
{
    u8 u8ReturnData = NOTPRESSED;
    u8 u8GetPressed;
    u8 u8row;
    u8 u8col;
    u8 u8FoundButton = 0;

    //makes each colmn low then checks each row if one has a low output
    for(u8col = 0 + KPD_COL_INIT; u8col < KPD_COL_END; u8col++)
    {
        DIO_voidSetPinValue(KPD_PORT, u8col, DIO_PIN_LOW);
        
        //checks if any row has a low input
        for(u8row = 0+ KPD_ROW_INIT; u8row < KPD_ROW_END ; u8row++)
        {
            u8GetPressed = DIO_u8GetPinValue(KPD_PORT, u8row);

            if(u8GetPressed == 0)
            {
                _delay_ms(50); //debouncing
                
                u8GetPressed = DIO_u8GetPinValue(KPD_PORT, u8row);
                
                if (u8GetPressed == 0)
                {
                    u8ReturnData = KPD_u8BUTTONS[u8row - KPD_ROW_INIT][u8col - KPD_COL_INIT];
                }
                
                while(DIO_PIN_LOW == DIO_u8GetPinValue(KPD_PORT, u8row));
                u8FoundButton == 1;
                break;
            }
        }

        DIO_voidSetPinValue (KPD_PORT, u8col , DIO_PIN_HIGH);//returns col pin to high
        
        if(u8FoundButton == 1)//to stop looping through the colmns even after the pressed button is found 
        {
            return u8ReturnData;
        }
    }
    return u8ReturnData;
}