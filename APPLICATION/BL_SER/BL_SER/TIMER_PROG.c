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

void TIMER0_Init(){
	TIMER0_TCNT0 = NO_TICKS  ; 
	//enable global interrupt
	SET_BIT(SREG,7);
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
	SET_BIT(TIMER0_TCCR0,6);
	
	
	#elif Timer0_Mode == PHASE_PWM
	SET_BIT(TIMER0_TCCR0,3);
	SET_BIT(TIMER0_TCCR0,6);
	
	#endif 
	
	SET_BIT(TIMER0_TCCR0,5);
	CLEAR_BIT(TIMER0_TCCR0,4);

	
	// Prescaler 8
	CLEAR_BIT(TIMER0_TCCR0,0);
	SET_BIT(TIMER0_TCCR0,1)  ; 
	CLEAR_BIT(TIMER0_TCCR0,2);
	
}

/////////////////////////////////////

void TIMER1_Init(void)
{
	/*
	argument : Void 
	Return : Void
	Description : 
	This fun is used to Initialize Timer1 in Fast PWM & Phase correct
	*/
	// Choosing ICR Value 
	// ICR is special Reg in Timer1 That allows you to chose your freq
	TIMER1_ICR = NO_ICR ;
	// OCR_value to take acton At 
	
	#if Timer1_Mode == FAST_PWM
	
	// Wave Form Generatio mode
	SET_BIT(TIMER1_TCCR1B,4);
	SET_BIT(TIMER1_TCCR1B,3);
    SET_BIT(TIMER1_TCCR1A,1);
    CLEAR_BIT(TIMER1_TCCR1A,0);
    // NON-inverting mode 
    CLEAR_BIT(TIMER1_TCCR1A,4);
    CLEAR_BIT(TIMER1_TCCR1A,6);
    
   SET_BIT(TIMER1_TCCR1A,5);
   SET_BIT(TIMER1_TCCR1A,7);
	#endif

////prescaler8
	
	CLEAR_BIT(TIMER1_TCCR1B,0);
	SET_BIT(TIMER1_TCCR1B,1);
	CLEAR_BIT(TIMER1_TCCR1B,2);

}


void SET_OCR(u16 value){
		TIMER1_OCR1A = value ;
}

void (*gptr) (void) = NULL ;  

void TIMER0_CALLBACK(void (*ptr)(void)){
	gptr = ptr  ;
}
	


void __vector_11(void) __attribute__((signal)) ; 

void __vector_11(void){
	
	static u16 counter = 0 ;
	counter ++ ; 
	
	if (counter == NO_OVERFLOW)
	{
		/// function
		gptr();
		counter = 0 ;
		TIMER0_TCNT0 = NO_CR ; 
		
	}


}

