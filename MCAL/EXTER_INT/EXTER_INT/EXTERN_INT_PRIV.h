/*
 * EXTERN_INT_PRIV.h
 *
 * Created: 2/16/2024 11:32:40 AM
 *  Author: miro
 */ 


#ifndef EXTERN_INT_PRIV_H_
#define EXTERN_INT_PRIV_H_




#define EXTI_MCUCR    *((volatile u8 *)0x55)
#define EXTI_MCUSCR   *((volatile u8 *)0x54)
#define EXTI_SREG     *((volatile u8 *)0x5F)
#define EXTI_GICR     *((volatile u8 *)0x5B)
#define EXTI_GIFR     *((volatile u8 *)0x5A)
/////////////////////////////////////////////////////////////////////////////////
#define LOW_LEVEL       1
#define RISING_EDGE     2
#define FALLING_EDGE    3
#define ANY_LOGICAL     4
/////////////////////////////////////////////////////////////////////////////////

#endif /* EXTERN_INT_PRIV_H_ */