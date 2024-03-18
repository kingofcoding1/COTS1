/*
 * library.c
 *
 * Created: 2/23/2024 10:30:45 AM
 *  Author: miro
 */ 
#include "bit_math.h"
#include "std_types.h"
#include "TIMER_CONFG.h"
#include "TIMER_INTER.h"
#include "TIMER_PRIV.h"

TIMER0_Init(){
	TIMER0_TCNT0 = 216  ; 
	//enable interrupt 
	SET_BIT(TIMER0_TIMSK,0);
	#if Timer0_Mode == NORMAL_MODE
	// Normal Mode
	CLEAR_BIT(TIMER0_TCCR0,3);
	CLEAR_BIT(TIMER0_TCCR0,6);
	
	#elif Timer0_Mode == CTC_MODE
	SET_BIT(TIMER0_TCCR0,6);
	CLEAR_BIT(TIMER0_TCCR0,3);
	
	#elif Timer0_Mode == FAST_PWM
	SET_BIT(TIMER0_TCCR0,3);
	CLEAR_BIT(TIMER0_TCCR0,6);
	
	
	#elif Timer0_Mode == PHASE_PWM
	SET_BIT(TIMER0_TCCR0,3);
	SET_BIT(TIMER0_TCCR0,6);
	
	#endif 
	// non-inverting mode
	SET_BIT(TIMER0_TCCR0,5);
	CLEAR_BIT(TIMER0_TCCR0,4);
	
	TIMER0_OCR0 = OCR_VAL ; 
	// Prescaler 8
	CLEAR_BIT(TIMER0_TCCR0,0);
	SET_BIT(TIMER0_TCCR0,1)  ; 
	CLEAR_BIT(TIMER0_TCCR0,2);
	
}

void (*gptr) (void) = NULL ;  
void TIMER0_CALLBACK(void (*ptr)(void)){
	gptr = ptr  ;
}
	


void __vector_11(void) __attribute__((signal)) ; 

void __vector_11(void){
	
	static u16 counter = 0 ;
	counter ++ ; 
	
	if (counter == 7813)
	{
		/// function
		gptr();
		counter = 0 ;
		TIMER0_TCNT0 = 153 ; 
		
	}


}

