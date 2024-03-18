/*
 * main.c
 *
 * Created: 2/17/2024 1:25:16 PM
 *  Author: miro
 */ 


#include "bit_math.h"
#include "std_types.h"
#include "ADC_PRIV.h"
#include "ADC_CONFG.h"
#include "ADC_INTER.h"
#include "DIO_PRIVATE.h"

int main()
{
	SET_BIT(DDRD_reg,3);
	u16 data = 0 ;
	ADC_INIT(1);
	while(1){
		data  = ADC_READ() ; 
		if(data > 100)
		{
			SET_BIT(PORTD_reg,3);
		}
		else{
			CLEAR_BIT(PORTD_reg,3);
		}
	}
	
	return 0 ; 
}