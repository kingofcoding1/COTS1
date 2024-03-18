/*
 * main.c
 *
 * Created: 2/9/2024 10:58:48 AM
 *  Author: miro
 */ 


#include "bit_math.h"
#include "std_types.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
int main(void)
{   
       DIO_SETPINDIRECTION(PORTC,PIN_2,DIO_OUTPUT);
       DIO_SETPINDIRECTION(PORTB,PIN_2,DIO_INPUT);

    while(1)
    {
         if (DIO_GETPINVALUE(PORTB,PIN_0) == 0)
         {
	         DIO_SETPINVALUE(PORTC,PIN_2,DIO_HIGH);
	         
         }
         else  {	 DIO_SETPINVALUE(PORTC,PIN_2,DIO_LOW); }
	    //TODO:: Please write your application code 
    }
}