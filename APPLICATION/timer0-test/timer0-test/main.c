/*
 * main.c
 *
 * Created: 2/23/2024 11:37:20 AM
 *  Author: miro
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "TIMER_INTER.h"
#include "DIO_PRIVATE.h"
#define F_CPU 16000000UL
#include <util/delay.h>

u16 fun(u8 angle);


void led(void){
	
	Toggle_BIT(PORTD_reg,3);

}
int main(void)
{
	// set led aas output 
	DDRD_reg = 0xff;
	
// 	TIMER0_Init();
	TIMER1_Init();

	//TIMER0_CALLBACK(&led);
			 SET_OCR(fun(0));

    while(1)
    {
		            _delay_ms(1000);
		            SET_OCR(fun(30));
		            _delay_ms(1000);
		            SET_OCR(fun(60));
		            _delay_ms(1000);
		            SET_OCR(fun(90));
		           _delay_ms(1000);
		              
		}
        //TODO:: Please write your application code 
    
}


		 
u16 fun(u8 angle)
{	
	return (((((f16)angle / 180)+1))*1000);	
}
