/*
 * main.c
 *
 * Created: 11/11/2023 12:43:48 PM
 *  Author: Youssef Ehab
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

#include "KEYPAD_private.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"

int main(void)
{
	
	DDRA = 0xff;
	DDRB = 0xff;
	PORTC = 0xff; 
	DDRC = 0x0f;
	
	HLCD_vInit();
	HLCD_vSendData('a');
	/*HKEYPAD_vInit();*/
	HLCD_vSendData('x');
	u8 x = 0;
    while(1)
    {

			HKEYPAD_vGetKey(&x);
			HLCD_vSendData(x);
		
        
    }
}