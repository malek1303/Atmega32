#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H

#define CLCD_MODE 8

#define CLCD_DATA_PORT    DIO_PORTA
#define CLCD_CONTROL_PORT DIO_PORTC // rs rw en

#define CLCD_RS             DIO_PIN1
#define CLCD_RW             DIO_PIN2
#define CLCD_EN             DIO_PIN3

#endif