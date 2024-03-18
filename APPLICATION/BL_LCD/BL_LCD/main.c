/*
 * main.c
 *
 * Created: 3/11/2024 2:06:06 AM
 *  Author: miro
 */ 

#include "std_types.h"
#include "bit_math.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

#include "USART_INTER.h"
#include "USART_PRIV.h"
#include "USART_CONFG.h"

int main(void)
{
		HLCD_vInit();
	    UART_INIT();
	    u8 Rec_data = 0;
	HLCD_vSendData("A");
    while(1)
    {
		Rec_data = UART_Recieve();
// 	if (Rec_data != 0)
// 	{
// 	HLCD_vSendData(Rec_data);
// 	
// 	}

    }

}