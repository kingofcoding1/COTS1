/*
 * main.c
 *
 * Created: 3/10/2024 9:09:56 PM
 *  Author: miro
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "TIMER_INTER.h"
#include "DIO_PRIVATE.h"
#include "USART_INTER.h"
#include "USART_PRIV.h"
#include "USART_CONFG.h"
#define F_CPU 16000000UL
#include <util/delay.h>


u16 fun(u8 angle);


int main(void)
{
    	TIMER1_Init();
        UART_INIT();
       u8 Rec_data = 0;
   
	while(1)
    {
		Rec_data = UART_Recieve();
		if (Rec_data == 1)
		{
          SET_OCR(fun(180));
		}
	   	if (Rec_data == 2)
	  		{
          SET_OCR(fun(0));
	     }
		//TODO:: Please write your application code 
    
	}
          SET_OCR(fun(80));


}

u16 fun(u8 angle)
{
	return (((((f32)angle / 180)+1))*1000);
}