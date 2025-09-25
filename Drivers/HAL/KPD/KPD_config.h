#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H
#include "DIO_interface.h"

#define KPD_ROW_INIT DIO_PIN0
#define KPD_ROW_END DIO_PIN3

#define KPD_COL_INIT DIO_PIN4
#define KPD_COL_END DIO_PIN7

                        // c0  c1  c2  c3
u8 KPD_u8BUTTONS[4][4]= { {'7','8','9','/'}, //r0
                          {'4','5','6','*'}, //r1
                          {'1','2','3','-'}, //r2
                          {'?','0','=','+'}  //r3
                        }; //buttons depending on your physical keypad

#define KPD_PORT DIO_PORTD

#define KPD_R0 DIO_PIN0
#define KPD_R1 DIO_PIN1
#define KPD_R2 DIO_PIN2
#define KPD_R3 DIO_PIN3

#define KPD_C0 DIO_PIN4
#define KPD_C1 DIO_PIN5
#define KPD_C2 DIO_PIN6
#define KPD_C3 DIO_PIN7

#endif