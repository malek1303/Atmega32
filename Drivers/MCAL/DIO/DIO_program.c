/*
 ___ __ __   ________   ______   ______        _______   __  __     ___ __ __   ________   __       ______   ___   ___     
/__//_//_/\ /_______/\ /_____/\ /_____/\     /_______/\ /_/\/_/\   /__//_//_/\ /_______/\ /_/\     /_____/\ /___/\/__/\    
\::\| \| \ \\::: _  \ \\:::_ \ \\::::_\/_    \::: _  \ \\ \ \ \ \  \::\| \| \ \\::: _  \ \\:\ \    \::::_\/_\::.\ \\ \ \   
 \:.      \ \\::(_)  \ \\:\ \ \ \\:\/___/\    \::(_)  \/_\:\_\ \ \  \:.      \ \\::(_)  \ \\:\ \    \:\/___/\\:: \/_) \ \  
  \:.\-/\  \ \\:: __  \ \\:\ \ \ \\::___\/_    \::  _  \ \\::::_\/   \:.\-/\  \ \\:: __  \ \\:\ \____\::___\/_\:. __  ( (  
   \. \  \  \ \\:.\ \  \ \\:\/.:| |\:\____/\    \::(_)  \ \ \::\ \    \. \  \  \ \\:.\ \  \ \\:\/___/\\:\____/\\: \ )  \ \ 
    \__\/ \__\/ \__\/\__\/ \____/_/ \_____\/     \_______\/  \__\/     \__\/ \__\/ \__\/\__\/ \_____\/ \_____\/ \__\/\__\/ 
  */                                                                                                                         
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

// takes port address & pin number & direction then sets pin direction to out or in
void DIO_voidSetPinDirection(u8 port, u8 pin, u8 dir)
{
    if (dir == DIO_PIN_OUTPUT)
    {
        switch (port)
        {
        case DIO_PORTA:
            SET_BIT(DDRA,pin);
            break;
        case DIO_PORTB:
            SET_BIT(DDRB,pin);
            break;
        case DIO_PORTC:
            SET_BIT(DDRC,pin);
            break;
        case DIO_PORTD:
            SET_BIT(DDRD,pin);
            break;
        }
    }
    else if (dir == DIO_PIN_INPUT)
    {
        switch (port)
        {
        case DIO_PORTA:
            CLR_BIT(DDRA,pin);
            break;
        case DIO_PORTB:
            CLR_BIT(DDRB,pin);
            break;
        case DIO_PORTC:
            CLR_BIT(DDRC,pin);
            break;
        case DIO_PORTD:
            CLR_BIT(DDRD,pin);
            break;
        }

    }
}

// takes port addr & pin num & bin value and outputs it to the pin
void DIO_voidSetPinValue(u8 port, u8 pin, u8 value)
{
    if (value == DIO_PIN_HIGH)
    {
        switch (port)
        {
        case DIO_PORTA:
            SET_BIT(PORTA,pin);
            break;
        case DIO_PORTB:
            SET_BIT(PORTB,pin);
            break;
        case DIO_PORTC:
            SET_BIT(PORTC,pin);
            break;
        case DIO_PORTD:
            SET_BIT(PORTD,pin);
            break;
        }
    }
    else if (value == DIO_PIN_HIGH)
    {
        switch (port)
        {
        case DIO_PORTA:
            CLR_BIT(PORTA,pin);
            break;
        case DIO_PORTB:
            CLR_BIT(PORTB,pin);
            break;
        case DIO_PORTC:
            CLR_BIT(PORTC,pin);
            break;
        case DIO_PORTD:
            CLR_BIT(PORTD,pin);
            break;
        }

    }
}

// returns specified port as a u8 value
u8   DIO_u8GetPinValue(u8 port, u8 pin)
{
    switch (port)
        {
        case DIO_PORTA:
            return GET_BIT(PINA,pin);
            break;
        case DIO_PORTB:
            return GET_BIT(PINB,pin);
            break;
        case DIO_PORTC:
            return GET_BIT(PINC,pin);
            break;
        case DIO_PORTD:
            return GET_BIT(PIND,pin);
            break;
        }
}

// toggles specified pin
void DIO_voidTogglePinValue(u8 port, u8 pin)
{
    switch (port)
        {
        case DIO_PORTA:
            return TOG_BIT(PINA,pin);
            break;
        case DIO_PORTB:
            return TOG_BIT(PINB,pin);
            break;
        case DIO_PORTC:
            return TOG_BIT(PINC,pin);
            break;
        case DIO_PORTD:
            return TOG_BIT(PIND,pin);
            break;
        }
}
// maps the directions of all pins of a port to a specified u8 value
void DIO_voidSetPortDirection(u8 port, u8 dir)
{
    switch (port)
    {
    case DIO_PORTA: DDRA = dir; break;
    case DIO_PORTB: DDRB = dir; break;
    case DIO_PORTC: DDRC = dir; break;
    case DIO_PORTD: DDRD = dir; break;
    }
}

// sets the value of the whole port
void DIO_voidSetPortValue(u8 port, u8 value)
{
    switch (port)
    {
    case DIO_PORTA: PORTA =value; break;
    case DIO_PORTB: PORTB =value; break;
    case DIO_PORTC: PORTC =value; break;
    case DIO_PORTD: PORTD =value; break;
    }
}

// returns the value of the port as a u8
u8   DIO_u8GetPortValue(u8 port)
{
    switch (port)
    {
    case DIO_PORTA: return PINA; break;
    case DIO_PORTB: return PINB; break;
    case DIO_PORTC: return PINC; break;
    case DIO_PORTD: return PIND; break;
    }
}

// toggles the value of the whole port
void DIO_voidTogglePortValue(u8 port)
{
    switch (port)
    {
    case DIO_PORTA: PINA^=0xff; break;
    case DIO_PORTB: PINB^=0xff; break;
    case DIO_PORTC: PINC^=0xff; break;
    case DIO_PORTD: PIND^=0xff; break;
    }
}

// configures the pin internal pull up config
// HINT: the pin must be an input pin else you would be changing the value of the output
    void DIO_voidConnectPullup (u8 port, u8 pin, u8 connectPullup)
    {
        switch(port)
        {
            case DIO_PORTA:
                if(connectPullup == DIO_PIN_HIGH)
                {
                    CLR_BIT(SFIOR, PUD);
                    CLR_BIT(DDRA, pin);
                    SET_BIT(PORTA, pin);
                }
                else
                {
                    CLR_BIT(PORTA, pin);
                }
                break;

                case DIO_PORTB:
                if(connectPullup == DIO_PIN_HIGH)
                {
                    CLR_BIT(SFIOR, PUD);
                    CLR_BIT(DDRB, pin);
                    SET_BIT(PORTB, pin);
                }
                else
                {
                    CLR_BIT(PORTB, pin);
                }
                break;

                case DIO_PORTC:
                if(connectPullup == DIO_PIN_HIGH)
                {
                    CLR_BIT(SFIOR, PUD);
                    CLR_BIT(DDRC, pin);
                    SET_BIT(PORTC, pin);
                }
                else
                {
                    CLR_BIT(PORTC, pin);
                }
                break;

                case DIO_PORTD:
                if(connectPullup == DIO_PIN_HIGH)
                {
                    CLR_BIT(SFIOR, PUD);
                    CLR_BIT(DDRD, pin);
                    SET_BIT(PORTD, pin);
                }
                else
                {
                    CLR_BIT(PORTD, pin);
                }
                break;
        }
        
    }

// sets the lower 4 pins value pin 0 --> 3
void DIO_voidSetLowerNibbleValue(u8 port, u8 value)
{
    value &= 0x0f;
    switch (port)
    {
        case DIO_PORTA:
        PORTA &= 0xf0
        PORTA |= value;
        break;
        case DIO_PORTB:
        PORTB &= 0xf0
        PORTB |= value;
        break;
        case DIO_PORTC:
        PORTC &= 0xf0
        PORTC |= value;
        break;
        case DIO_PORTD:
        PORTC &= 0xf0
        PORTC |= value;
        break;
    }
}

// sets the higher 8 pins value pin 4 --> 7
void DIO_voidSetHigherNibbleValue(u8 port, u8 value)
{
    value &= 0xf0;
    switch (port)
    {
        case DIO_PORTA:
        PORTA &= 0x0f
        PORTA |= value;
        break;
        case DIO_PORTB:
        PORTB &= 0x0f
        PORTB |= value;
        break;
        case DIO_PORTC:
        PORTC &= 0x0f
        PORTC |= value;
        break;
        case DIO_PORTD:
        PORTC &= 0x0f
        PORTC |= value;
        break;
    }

}