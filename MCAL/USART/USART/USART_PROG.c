/*
 * library.c
 *
 * Created: 3/2/2024 10:48:28 AM
 *  Author: miro
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "USART_CONFG.h"
#include "USART_INTER.h"
#include "USART_PRIV.h"



void UART_Transmit(u8 Data)
{
	
while(GET_BIT(UART_UCSRA,5)==0);	
UART_UDR = Data
}

u8 UART_Recieve(void)
{
	
	while(GET_BIT(UART_UCSRA,7)==0);	
	return UART_UDR;
	

}


void UART_INIT(void)
{
	u8 temp = 0;
	
	SET_BIT(temp,7);
	
	//Select Data Size
	SET_BIT(temp,1);
	SET_BIT(temp,0);
	CLEAR_BIT(UART_UCSRB,2);
	UART_UCSRC = temp;
	
	#if UART_E_TX == 1
	SET_BIT(UART_UCSRB,3);
	#endif
	#if UART_E_RX == 1
	SET_BIT(UART_UCSRB,4);
	#endif
 
	
	#if UART_EN_DS == 1
	SET_BIT(UART_UCSRA,1);
	#endif

	#if UART_SMMS_MODE == 1
	SET_BIT(UART_UCSRA,0);
	#endif
UART_UBRRL = UART_UBRR_VAL;

}


 /* Replace with your library code */
