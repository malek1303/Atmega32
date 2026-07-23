#pragma once

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define EXTI_LINE0 6
#define EXTI_LINE1 7
#define EXTI_LINE2 5

#define EXTI_FALLING_EDGE 0
#define EXTI_RISING_EDGE  1
#define EXTI_LOW_LEVEL    2
#define EXTI_ON_CHANGE  3

#define NULL 0

void EXTI_voidInit              ( void                                                  );
void EXTI_voidSetSignalLatch    ( u8 Copy_u8SenseMode , u8 Copy_u8Line                  );
u8   EXTI_voidDisableInterrupt  ( u8 Copy_u8Line                                        );
u8   EXTI_voidEnableInterrupt   ( u8 Copy_u8Line                                        );
void EXTI_voidClearFlag         ( u8 Copy_u8Line                                        );
void EXTI_voidSetCallBack       ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine );