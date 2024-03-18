#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "std_types.h" // Assuming you have a header file for standard types

/* DIO Constants */
#define DIO_LOW        0
#define DIO_HIGH       1
#define DIO_OUTPUT     1
#define DIO_INPUT      0

/* Port and Pin Macros */
#define PORTA      1
#define PORTB      2
#define PORTC      3
#define PORTD      4

#define PIN_0      0
#define PIN_1      1
#define PIN_2      2
#define PIN_3      3
#define PIN_4      4
#define PIN_5      5
#define PIN_6      6
#define PIN_7      7

/* Register Definitions */
#define PORTA_reg      (*((volatile u8 *)0x3B))
#define DDRA_reg       (*((volatile u8 *)0x3A))
#define PINA_reg       (*((volatile u8 *)0x39))

#define PORTB_reg      (*((volatile u8 *)0x38))
#define DDRB_reg       (*((volatile u8 *)0x37))
#define PINB_reg       (*((volatile u8 *)0x36))

#define PORTC_reg      (*((volatile u8 *)0x35))
#define DDRC_reg       (*((volatile u8 *)0x34))
#define PINC_reg       (*((volatile u8 *)0x33))

#define PORTD_reg      (*((volatile u8 *)0x32))
#define DDRD_reg       (*((volatile u8 *)0x31))
#define PIND_reg       (*((volatile u8 *)0x30))

#endif /* DIO_PRIVATE_H_ */
