/*
 * library.c
 *
 * Created: 2/16/2024 11:31:27 AM
 *  Author: miro
 */ 


#include "std_types.h"
#include "bit_math.h"
#include "EXTERN_INT_PRIV"


void EXTI_INIT(){

#if MODE == LOW_LEVEL	
CLEAR_BIT(EXTI_MCUCR,0);
CLEAR_BIT(EXTI_MCUCR,1);

#elif MODE == ANY_LOGICAL     
SET_BIT(EXTI_MCUCR,0);
CLEAR_BIT(EXTI_MCUCR,1);

#elif MODE == FALLING_EDGE
SET_BIT(EXTI_MCUCR,1);
CLEAR_BIT(EXTI_MCUCR,0);

#elif MODE == RISING_EDGE
SET_BIT(EXTI_MCUCR,0);
SET_BIT(EXTI_MCUCR,1);
#endif

SET_BIT(EXTI_GICR,6);
SET_BIT(EXTI_SREG,7);

}