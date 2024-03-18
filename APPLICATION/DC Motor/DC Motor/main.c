/*
 * main.c
 *
 * Created: 3/9/2024 4:01:49 PM
 *  Author: miro
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "DIO_INTERFACE.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"
#include "TIMER_INTER.h"
#define F_CPU 800000000
#include <util/delay.h>


int main(void)
{
   
   u16 i=0;  
   DIO_SETPINDIRECTION(PORTC,PIN_2,DIO_OUTPUT);
   DIO_SETPINDIRECTION(PORTC,PIN_3,DIO_OUTPUT);
   DIO_SETPINDIRECTION(PORTD,PIN_5,DIO_OUTPUT);
   DIO_SETPINVALUE(PORTC,PIN_2,DIO_HIGH);
   DIO_SETPINVALUE(PORTC,PIN_3,DIO_LOW);
      TIMER1_Init();

    while(1)
     {
		 
	    //TODO:: Please write your application code 
    		for ( i =0; i< 19999; i +=1000)
    		{
	    		SET_OCR(i);
	    		_delay_ms(1000);
    		}
	
	 }

}