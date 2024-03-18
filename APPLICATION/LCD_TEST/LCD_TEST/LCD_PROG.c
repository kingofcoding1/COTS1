/*
 * library.c
 *
 * Created: 2/10/2024 10:02:13 AM
 *  Author: miro
 */ 

#include "bit_math.h"
#include "std_types.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"

void LCD_SEND_COMM(u8 command)
{
	    PORTA_reg =  (PORTA_reg & 0x0f)| (command & 0xf0);

    DIO_SETPINVALUE(PORTB, PIN_1, DIO_LOW);
    DIO_SETPINVALUE(PORTB, PIN_2, DIO_LOW);


    DIO_SETPINVALUE(PORTB, PIN_3, DIO_HIGH);
    _delay_us(1);
    DIO_SETPINVALUE(PORTB, PIN_3, DIO_LOW);

    PORTA_reg =  (PORTA_reg & 0x0f)|(command << 4) ;

    DIO_SETPINVALUE(PORTB, PIN_1, DIO_LOW);
    DIO_SETPINVALUE(PORTB, PIN_2, DIO_LOW);


    DIO_SETPINVALUE(PORTB, PIN_3, DIO_HIGH);
    _delay_us(1);
    DIO_SETPINVALUE(PORTB, PIN_3, DIO_LOW);
		_delay_ms(2);

}

void LCD_SEND_DATA(u8 data)
{
	  PORTA_reg =(PORTA_reg & 0x0f)| (data & 0xf0)  ;

    DIO_SETPINVALUE(PORTB, PIN_1, DIO_HIGH);
    DIO_SETPINVALUE(PORTB, PIN_2, DIO_LOW);

  
    DIO_SETPINVALUE(PORTB, PIN_3, DIO_HIGH);
    _delay_us(1);
    DIO_SETPINVALUE(PORTB, PIN_3, DIO_LOW);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
      PORTA_reg =  (PORTA_reg & 0x0f)|(data << 4) ;
	DIO_SETPINVALUE(PORTB, PIN_2, DIO_LOW);
    DIO_SETPINVALUE(PORTB, PIN_1, DIO_HIGH);

  

    DIO_SETPINVALUE(PORTB, PIN_3, DIO_HIGH);
    _delay_us(1);
    DIO_SETPINVALUE(PORTB, PIN_3, DIO_LOW);
	_delay_ms(2);
}

void LCD_INT()
{
	DDRA_reg = 0xFF;  // Configure PORTA as output for data
	DDRB_reg |= 0x0f; // Configure lower 4 bits of PORTB as output for control

	_delay_ms(40);
	LCD_SEND_COMM(0x28);
	_delay_us(40);
	LCD_SEND_COMM(0x02);
	_delay_us(2);
	LCD_SEND_COMM(0x06);
	_delay_us(40);
	LCD_SEND_COMM(0x0F);
	LCD_SEND_COMM(0x14);
	_delay_ms(40);
	LCD_SEND_COMM(0x01);
	_delay_ms(2);
}


void LCD_SaveCustomChar(u8 location,u8 custom[])
{
	
	if (location<8)
	{
		LCD_SEND_COMM(0x40 +(location*8));
		for (int i = 0; i < 8; i++)
		{
			LCD_SEND_DATA(custom[i]);
		}
	}
}

void LCD_DisplayCustomChar(u8 location)
{
	
	LCD_SEND_DATA(location);
}
void move_character_cursor(u8 character[]) {
	LCD_SEND_COMM(0x80); // Set cursor to beginning
	while (1) {
		LCD_SEND_DATA(character);
		LCD_SEND_COMM(0x14 | (1 << 1)); // Shift cursor right
		_delay_ms(1000); // Adjust delay for desired speed
	}
}
void move_character_up_down(u8 character) {
	u8 position = 0;

  while (1) {
	  LCD_SEND_COMM(0x01); // Clear LCD
	  LCD_SEND_COMM(0x80 + position * 0x40); // Set cursor to position
	  LCD_SEND_DATA(character);

	  if (position == 0) {
		  position = 1; // Move down from top
		  } else {
		  position = 0; // Move up from bottom
	  }

	  _delay_ms(2000); // Adjust delay for desired speed
  }
  }