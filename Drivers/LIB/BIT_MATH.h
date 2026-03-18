 #pragma once

#define SET_BIT(reg,bit)        reg|=(1<<bit)
#define CLR_BIT(reg,bit)        reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)        reg^=(1<<bit)
#define GET_BIT(reg,bit)        (reg&(1<<bit))>>bit

#define IS_BIT_SET(reg,bit)     (reg&(1<<bit))>>bit     //returns a boolen
#define IS_BIT_CLR(reg,bit)     !((reg&(1<<bit))>>bit)  //returns a boolen



typedef char arr[16];