#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H

// adjust based on Hardware connections
#define CLCD_MODE 8  //number of bits mode (4 or 8)

#define CLCD_DATA_PORT    DIO_PORTA
#define CLCD_CONTROL_PORT DIO_PORTC // rs rw en

#define CLCD_RS             DIO_PIN0
#define CLCD_RW             DIO_PIN1
#define CLCD_EN             DIO_PIN2

#endif