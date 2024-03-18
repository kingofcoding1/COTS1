/*
 * USART_PRIV.h
 *
 * Created: 3/2/2024 10:49:42 AM
 *  Author: miro
 */ 


#ifndef USART_PRIV_H_
#define USART_PRIV_H_


#define UART_UDR              * ((volatile u8 *)0x2C)
#define UART_UCSRA            * ((volatile u8 *)0x2B)
#define UART_UCSRB            * ((volatile u8 *)0x2A)
#define UART_UCSRC            * ((volatile u8 *)0x40)
#define UART_UBRRH            * ((volatile u8 *)0x40)
#define UART_UBRRL            * ((volatile u8 *)0x29)

/////////////////////
#define RXC     7
#define TXC     6
#define UDRE    5

#endif /* USART_PRIV_H_ */