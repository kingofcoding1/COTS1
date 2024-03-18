/*
 * main.c
 *
 * Created: 2/18/2024 10:55:17 PM
 *  Author: miro
 */ 

#include "bit_math.h"
#include "std_types.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
#include "ADC_INTER.h"
#include "ADC_PRIV.h"
#include "LCD_INTER.h"
#include "LCD_PRIV.h"

int main(void)
{
   LCD_INT();
   	SET_BIT(DDRD_reg,3);
   	u16 data = 0 ;
   	ADC_INIT(1);
    
	while(1)
    {
        //TODO:: Please write your application code 
        data  = ADC_READ() ; 
		float voltage = data * 5.0 / 1024.0; // Convert to voltage (assuming 5V reference)

        // Clear LCD line (optional)
        LCD_SEND_COMM(0x01);

        // Display voltage (adjust format as needed)
        LCD_SEND_DATA('V');
        LCD_SEND_DATA('o');
        LCD_SEND_DATA('l');
        LCD_SEND_DATA('t');
        LCD_SEND_DATA(':');
        LCD_SEND_DATA(' ');
        LCD_SEND_DATA((int)(voltage * 10) / 10 + '0'); // Display integer part
        LCD_SEND_DATA('.');
        LCD_SEND_DATA((int)(voltage * 100) % 10 + '0'); // Display decimal part

        _delay_ms(500);
		
	
	}
}