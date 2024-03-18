/*
 * main.c
 *
 * Created: 3/2/2024 1:04:36 PM
 *  Author: miro
 */ 


#include "bit_math.h"
#include "std_types.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
#include "USART_INTER.h"
#include "USART_PRIV.h"
#include "USART_CONFG.h"


int main()
{
   SET_BIT(	DDRD_reg,3);
   UART_INIT();
   u8 Rec_data = 0;
    while(1)
    {
		Rec_data = UART_Recieve();
		
		if (Rec_data == 1)
		{
		SET_BIT(PORTD_reg,3);		
		}
		if (Rec_data == 2)
		{
		CLEAR_BIT(PORTD_reg,3);
		}
    }
}