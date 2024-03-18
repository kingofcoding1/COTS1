/*
 * TIMER_PRIV.h
 *
 * Created: 2/23/2024 10:32:42 AM
 *  Author: miro
 */ 


#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_


#define NORMAL_MODE     1
#define CTC_MODE        2
#define FAST_PWM        3
#define PHASE_PWM       4

//////////////////////////////////////////////////////////////

#define SREG             * ((volatile u8 *)0x5F)
#define TIMER0_TCCR0     * ((volatile u8 *)0x53)
#define TIMER0_TIMSK     * ((volatile u8 *)0x59)
#define TIMER0_TCNT0     * ((volatile u8 *)0x52)
#define TIMER0_OCR0      * ((volatile u8 *)0x5C)

/////////////////////////////////////////////////////////////

#define TIMER1_TCCR1A    * ((volatile u8 *)0x4F)
#define TIMER1_TCCR1B    * ((volatile u8 *)0x4E)
#define TIMER1_ICR       * ((volatile u16 *)0x46)
#define TIMER1_OCR1A     * ((volatile u16 *)0x4A)



#endif /* TIMER_PRIV_H_ */