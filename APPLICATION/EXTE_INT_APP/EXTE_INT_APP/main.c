/*
 * main.c
 *
 * Created: 2/16/2024 12:02:10 PM
 *  Author: miro
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "DIO_INTERFACE.h"
#include "EXTERN_INT_INTER.h"
#include "DIO_PRIVATE.h"
void toggle(){
	Toggle_BIT(PORTD_reg,3);
}

int main(void)
{
	SET_BIT(DDRD_reg,3);
	EXTI_INIT();
	Call_Back(toggle);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}








