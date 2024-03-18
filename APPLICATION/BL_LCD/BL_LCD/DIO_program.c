/*
* DIO_program.c
*
* Created: 11/10/2023 9:21:15 AM
*  Author: Youssef Ehab
*/

#include "std_types.h"
#include "bit_math.h"

#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"


u8 MDIO_u8SetPinDirection(u8 MDIO_u8PortName, u8 MDIO_u8PinNumber, u8 MDIO_u8PinMode){
	
	u8 lu8state_error = STD_OK;
	
	
	if ((MDIO_u8PortName <= MDIO_PORTD) && (MDIO_u8PinNumber <= MDIO_PIN7) && ((MDIO_u8PinMode == MDIO_OUTPUT) || (MDIO_u8PinMode == MDIO_INPUT)))
	{
		switch(MDIO_u8PortName){
			case MDIO_PORTA :
			switch (MDIO_u8PinMode){
				case MDIO_OUTPUT: SET_BIT(DDRA,MDIO_u8PinNumber);	break;
				case MDIO_INPUT	: CLEAR_BIT(DDRA,MDIO_u8PinNumber);	break;
			}
			break;
			case MDIO_PORTB :
			switch (MDIO_u8PinMode){
				case MDIO_OUTPUT: SET_BIT(DDRB,MDIO_u8PinNumber);	break;
				case MDIO_INPUT	: CLEAR_BIT(DDRB,MDIO_u8PinNumber);	break;
			}
			break;
			case MDIO_PORTC :
			switch (MDIO_u8PinMode){
				case MDIO_OUTPUT: SET_BIT(DDRC,MDIO_u8PinNumber);	break;
				case MDIO_INPUT	: CLEAR_BIT(DDRC,MDIO_u8PinNumber);	break;
			}
			break;
			case MDIO_PORTD :
			switch (MDIO_u8PinMode){
				case MDIO_OUTPUT: SET_BIT(DDRD,MDIO_u8PinNumber);	break;
				case MDIO_INPUT	: CLEAR_BIT(DDRD,MDIO_u8PinNumber);	break;
			}
			break;
		}
	}
	else
	{
		lu8state_error = STD_NOK;
	}
	return lu8state_error;
}


u8 MDIO_u8SetPinValue(u8 MDIO_u8PortName, u8 MDIO_u8PinNumber, u8 MDIO_u8PinValue){
		
	u8 lu8state_error = STD_OK;
	
	
	if ((MDIO_u8PortName <= MDIO_PORTD) && (MDIO_u8PinNumber <= MDIO_PIN7) && ((MDIO_u8PinValue == MDIO_HIGH) || (MDIO_u8PinValue == MDIO_LOW)))
	{
		switch(MDIO_u8PortName){
			case MDIO_PORTA :
			switch (MDIO_u8PinValue){
				case MDIO_HIGH	: SET_BIT(PORTA,MDIO_u8PinNumber);		break;
				case MDIO_LOW	: CLEAR_BIT(PORTA,MDIO_u8PinNumber);	break;
			}
			break;
			case MDIO_PORTB :
			switch (MDIO_u8PinValue){
				case MDIO_HIGH	: SET_BIT(PORTB,MDIO_u8PinNumber);		break;
				case MDIO_LOW	: CLEAR_BIT(PORTB,MDIO_u8PinNumber);	break;
			}
			break;
			case MDIO_PORTC :
			switch (MDIO_u8PinValue){
				case MDIO_HIGH	: SET_BIT(PORTC,MDIO_u8PinNumber);		break;
				case MDIO_LOW	: CLEAR_BIT(PORTC,MDIO_u8PinNumber);	break;
			}
			break;
			case MDIO_PORTD :
			switch (MDIO_u8PinValue){
				case MDIO_HIGH	: SET_BIT(PORTD,MDIO_u8PinNumber);		break;
				case MDIO_LOW	: CLEAR_BIT(PORTD,MDIO_u8PinNumber);	break;
			}
			break;
		}
	}
	else
	{
		lu8state_error = STD_NOK;
	}
	return lu8state_error;
}


u8 MDIO_u8GetPinValue(u8 MDIO_u8PortName, u8 MDIO_u8PinNumber, u8* MDIO_u8PinValue){
	
	u8 lu8state_error = STD_OK;
	
	
	if ((MDIO_u8PortName <= MDIO_PORTD) && (MDIO_u8PinNumber <= MDIO_PIN7) && (MDIO_u8PinValue != NULL))
	{
		switch(MDIO_u8PortName){
			case MDIO_PORTA :
			*MDIO_u8PinValue = GET_BIT(PINA,MDIO_u8PinNumber);
			break;
			case MDIO_PORTB :
			*MDIO_u8PinValue = GET_BIT(PINB,MDIO_u8PinNumber);
			break;
			case MDIO_PORTC :
			*MDIO_u8PinValue = GET_BIT(PINC,MDIO_u8PinNumber);
			break;
			case MDIO_PORTD :
			*MDIO_u8PinValue = GET_BIT(PIND,MDIO_u8PinNumber);
			break;
		}
	}
	else
	{
		lu8state_error = STD_NOK;
	}
	return lu8state_error;
}