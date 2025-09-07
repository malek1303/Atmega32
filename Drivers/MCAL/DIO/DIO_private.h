#include "STD_TYPES.H"
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

// group A
#define PORTA *((volatile u8*)0x3b)
#define DDRA  *((volatile u8*)0x3a)
#define PINA  *((volatile u8*)0x39)

// group B
#define PORTB *((volatile u8*)0x38)
#define DDRB  *((volatile u8*)0x37)
#define PINB  *((volatile u8*)0x36)

// group C
#define PORTC *((volatile u8*)0x35)
#define DDRC  *((volatile u8*)0x34)
#define PINC  *((volatile u8*)0x33)

// group D
#define PORTD *((volatile u8*)0x32)
#define DDRD  *((volatile u8*)0x31)
#define PIND  *((volatile u8*)0x30)

#define SFIOR  *((volatile u8*)0x50)

#endif // DIO_PRIVATE_H