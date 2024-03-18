/*
 * TIMER_INTER.h
 *
 * Created: 2/23/2024 10:33:08 AM
 *  Author: miro
 */ 


#ifndef TIMER_INTER_H_
#define TIMER_INTER_H_

void TIMER0_Init();
void TIMER0_CALLBACK(void (*ptr)(void));
void SET_OCR(u16 value);
void TIMER1_Init();


#endif /* TIMER_INTER_H_ */