/*
 * LCD_program.c
 * Software component: LCD
 *
 * Created: 11/10/2023 1:05:39 PM
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


void HLCD_vSendData(u8 LCD_Data){
	/*Send High Nipple*/
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0f) | (LCD_Data & 0xf0);
	SET_BIT(LCD_CONTROL_PORT,LCD_RS);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_RW);
	SET_BIT(LCD_CONTROL_PORT,LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_E);
	
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0f) | (LCD_Data << 4);
	SET_BIT(LCD_CONTROL_PORT,LCD_RS);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_RW);
	SET_BIT(LCD_CONTROL_PORT,LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_E);
}
void HLCD_vSendCommand(u8 LCD_Command)
{
	/*Send High Nipple*/
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0f) | (LCD_Command & 0xf0);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_RS);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_RW);
	SET_BIT(LCD_CONTROL_PORT,LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_E);
	
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0f) | (LCD_Command << 4);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_RS);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_RW);
	SET_BIT(LCD_CONTROL_PORT,LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT,LCD_E);
}

void HLCD_vInit(void)
{
	_delay_ms(40);
	HLCD_vSendCommand(0x28); // Function Set
	_delay_us(40);
	HLCD_vSendCommand(0x02); // Return Home
	_delay_ms(2);
	HLCD_vSendCommand(0x06); // Entry Mode
	_delay_us(40);
	HLCD_vSendCommand(0x0f); // Display on
	HLCD_vSendCommand(0x14); // Courser to the Right
	_delay_us(40);
	HLCD_vSendCommand(0x01); // CLear Display
	_delay_ms(2);
}

void HLCD_vShowString(u8 const str[])
{
	for (int i = 0;str[i] != '\0';i++)
	{
		HLCD_vSendData(str[i]);
/*		str++ ;*/

	}
}

void HLCD_vClearDisplay(void)
{
	HLCD_vSendCommand(0x01);
	HLCD_vSendCommand(0x02);
}

void HLCD_vSaveCustomChar(u8 location,u8 custom[])
{
	
	if (location<8)
	{
		HLCD_vSendCommand(LCD_CGRAM_ADDRESS+(location*8));
		for (int i = 0; i < 8; i++)
		{
			HLCD_vSendData(custom[i]);
		}
	}
}

void HLCD_vDisplayCustomChar(u8 location)
{
	
	HLCD_vSendData(location);
}


void HLCD_vGoTo(u8 X,u8 Y)
{
	switch (Y)
	{
	case 1: HLCD_vSendCommand(LCD_DDRAM_ADDRESS_LINE1+X);
		break;
	case 2: HLCD_vSendCommand(LCD_DDRAM_ADDRESS_LINE2+X);
		break;
	}
	
	
}

void HLCD_vContinousDisplay(u8 const str[])
{
	HLCD_vGoTo(0,LINE1);
	HLCD_vShowString(str);
	HLCD_vGoTo(17,LINE1);
	HLCD_vShowString(str);
	for (int i = 0;i <= DISPLAY_BITS; i++ )
	{
		_delay_ms(500);
		HLCD_vSendCommand(SHIFT_DISPLAY_LEFT);
	}
}