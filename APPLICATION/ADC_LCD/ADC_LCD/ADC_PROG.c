/*
 * library.c
 *
 * Created: 2/17/2024 11:34:02 AM
 *  Author: miro
 */ 


#include "bit_math.h"
#include "std_types.h"
#include "ADC_PRIV.h"
#include "ADC_CONFG.h"
#include "ADC_INTER.h"
#include "DIO_PRIVATE.h"

void ADC_INIT(u8 channel)
{
	
SET_BIT(ADMUX,6);
GET_BIT(ADMUX,7);	
	
ADMUX |= channel;	
	
SET_BIT(ADCSRA,2);	
SET_BIT(ADCSRA,1);
SET_BIT(ADCSRA,0);
	
SET_BIT(ADCSRA,7);
}

u16 ADC_READ()
{
	while(GET_BIT(ADCSRA,4) != 1)
	return ADCL+(ADCH<<8);
	
}