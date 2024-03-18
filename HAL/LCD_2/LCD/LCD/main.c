/*
 * main.c
 *
 * Created: 11/11/2023 9:49:41 AM
 *  Author: Youssef Ehab
 */ 

#include "std_types.h"
#include "bit_math.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

int main()
{
	DDRA = 0xff;
	DDRB = 0xff;
/*
	u8 str1[8] = {0X00,0x00,0x0A,0X15,0X11,0X0A,0X04,0X00};
	u8 str2[8] = {0x04,0x1f,0X11,0X11,0X1f,0X1f,0X1f,0X1f};
	u8 str3[8] = {0x04,0x0e,0x0e,0x0e,0X1f,0X00,0X04,0X00};*/
/*
	u32 number = 1234;
	u8 data[] = {'0','1','2'};*/
	HLCD_vInit();


/*	HLCD_vSendData('0'+(number%10));*/
	HLCD_vShowInt(10256);


	while(1)
	{
		

	}
}