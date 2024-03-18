/*
 * library.c
 *
 * Created: 2/9/2024 9:17:13 AM
 *  Author: miro
 */ 


#include "bit_math.h"
#include "std_types.h"
#include "DIO_CONFIG.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"






void DIO_SETPINDIRECTION(u8 Port, u8 Pin ,u8 Value)
{
switch (Port)
{
case PORTA:
switch(Value){
	case DIO_OUTPUT : SET_BIT(DDRA_reg,Pin); break;
	case DIO_INPUT : CLEAR_BIT(DDRA_reg,Pin); break;
}
break;
case PORTB:
switch(Value){
	case DIO_OUTPUT : SET_BIT(DDRB_reg,Pin); break;
	case DIO_INPUT : CLEAR_BIT(DDRB_reg,Pin); break;
}
break;
case PORTC:
switch(Value){
	case DIO_OUTPUT : SET_BIT(DDRC_reg,Pin); break;
	case DIO_INPUT : CLEAR_BIT(DDRC_reg,Pin); break;
}
break;
case PORTD:
switch(Value){
	case DIO_OUTPUT : SET_BIT(DDRD_reg,Pin); break;
	case DIO_INPUT : CLEAR_BIT(DDRD_reg,Pin); break;
}
break;



}




}

 void DIO_SETPINVALUE(u8 Port, u8 Pin ,u8 Value)
 {
	 switch (Port)
	 {
		 
		 case PORTA:
		 switch(Value){
			 case DIO_OUTPUT : SET_BIT(PORTA_reg,Pin); break;
			 case DIO_INPUT : CLEAR_BIT(PORTA_reg,Pin); break;
		 }
		 break;
		 case PORTB:
		 switch(Value){
			 case DIO_OUTPUT : SET_BIT(PORTB_reg,Pin); break;
			 case DIO_INPUT : CLEAR_BIT(PORTB_reg,Pin); break;
		 }
		 break;
		 case PORTC:
		 switch(Value){
			 case DIO_OUTPUT :  SET_BIT(PORTC_reg,Pin); break;
			 case DIO_INPUT : CLEAR_BIT(PORTC_reg,Pin); break;
		 }
		 break;
		 case PORTD:
		 switch(Value){
			 case DIO_OUTPUT :  SET_BIT(PORTD_reg,Pin); break;
			 case DIO_INPUT : CLEAR_BIT(PORTD_reg,Pin); break;
		 }
		 break;
		 
		 
	 }
 }
 
 
 u8 DIO_GETPINVALUE(u8 Port, u8 Pin)
 {
 	u8 Temp = 0;
 	switch(Port)
    {
 	   case PORTA: Temp = GET_BIT(PINA_reg,Pin); break;
 	   case PORTB: Temp = GET_BIT(PINB_reg,Pin); break;
 	   case PORTC: Temp = GET_BIT(PINC_reg,Pin); break;
 	   case PORTD: Temp = GET_BIT(PIND_reg,Pin); break;
    }
 
 return Temp;
 
 
 
 }