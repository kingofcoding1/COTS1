/*
 * DIO_private.h
 *
 * Created: 11/10/2023 9:20:53 AM
 *  Author: Youssef Ehab
 */ 

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#define MDIO_PORTA	0
#define MDIO_PORTB	1
#define MDIO_PORTC	2
#define MDIO_PORTD	3

#define MDIO_PIN0	0
#define MDIO_PIN1	1
#define MDIO_PIN2	2
#define MDIO_PIN3	3
#define MDIO_PIN4	4
#define MDIO_PIN5	5
#define MDIO_PIN6	6
#define MDIO_PIN7	7

#define MDIO_INPUT	0
#define MDIO_OUTPUT	1

#define MDIO_HIGH	1
#define MDIO_LOW	0

#define PORTA	*((volatile u8 *)0x3B)
#define DDRA	*((volatile u8 *)0x3A)
#define PINA	*((volatile u8 *)0x39)
#define PORTB	*((volatile u8 *)0x38)
#define DDRB	*((volatile u8 *)0x37)
#define PINB	*((volatile u8 *)0x36)
#define PORTC	*((volatile u8 *)0x35)
#define DDRC	*((volatile u8 *)0x34)
#define PINC	*((volatile u8 *)0x33)
#define PORTD	*((volatile u8 *)0x32)
#define DDRD	*((volatile u8 *)0x31)
#define PIND	*((volatile u8 *)0x30)



#endif /* DIO_PRIVATE_H_ */