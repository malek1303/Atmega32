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

#define CLCD_ROW_1                  1
#define CLCD_ROW_2                  2

#define CLCD_COL_1                  1
#define CLCD_COL_2                  2
#define CLCD_COL_3                  3
#define CLCD_COL_4                  4
#define CLCD_COL_5                  5
#define CLCD_COL_6                  6
#define CLCD_COL_7                  7
#define CLCD_COL_8                  8
#define CLCD_COL_9                  9
#define CLCD_COL_10                 10
#define CLCD_COL_11                 11
#define CLCD_COL_12                 12
#define CLCD_COL_13                 13
#define CLCD_COL_14                 14
#define CLCD_COL_15                 15
#define CLCD_COL_16                 16

void CLCD_voidInit(void);
void CLCD_voidSendData (u8 Data);
void CLCD_voidSendCommand(u8 Command);
void CLCD_voidSendString(const u8 *stringptr);
static void CLCD_voidSendFallingEdge(void);
void CLCD_voidClearScreen(void);


#endif