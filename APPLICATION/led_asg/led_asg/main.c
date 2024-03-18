/*
 * main.c
 *
 * Created: 2/24/2024 7:22:37 PM
 *  Author: miro
 */ 

#include "bit_math.h"
#include "std_types.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <xc.h>


int main(void)
{
    DDRD = 0xff;	
	while(1)
    {
           Toggle_BIT(PORTD,3);
           _delay_ms(1000);
			CLEAR_BIT(PORTD,3);
			_delay_ms(1000);
        //TODO:: Please write your application code 
    }


}