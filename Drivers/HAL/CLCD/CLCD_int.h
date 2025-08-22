#ifndef CLCD_INT_H
#define CLCS_INT_H

#include "CLCD_config.h"

#if CLCD_MODE == 4
#define FOUR_BITS   0X28
#elif CLCD_MODE == 8
#define EIGHT_BITS  0X38
#endif

#define lcd_DisplayOn_CursorOff     0x0c
#define lcd_DisplayOn_CursorOn      0x0e
#define lcd_DisplayOff_CursorOff    0x08
#define lcd_Clear                   0x01
#define lcd_EntryMode               0x06
#define lcd_Home                    0x02
#define lcd_CGRAM                   0x40
#define lcd_SetCursor               0x80
#define lcd_FunctionReset           0x30




void CLCD_voidInit(void);
void CLCD_voidSendData (u8 Data);
void CLCD_voidSendCommand(u8 Command);
void CLCD_voidSendString(const u8 *stringptr);
static void CLCD_voidSendFallingEdge(void);
void CLCD_voidClearScreen(void);


#endif