/*
 * main.c
 *
 * Created: 2/10/2024 11:35:29 AM
 *  Author: miro
 */ 

#include "bit_math.h"
# include "std_types.h"
# include "DIO_INTERFACE.h"
# include "LCD_INTER.h"
u8 heart[] = {
  0x00,
  0x00,
  0x0A,
  0x15,
  0x0A,
  0x04,
  0x00,
  0x00
};
u8 smile[] = {
  0x00,
  0x1B,
  0x1B,
  0x04,
  0x11,
  0x0E,
  0x00,
  0x00
};

int main(void)
{
	LCD_INT();
LCD_SaveCustomChar(0,smile);
 LCD_SaveCustomChar(1,heart);
  
 LCD_SEND_COMM(0x80);
  LCD_DisplayCustomChar(0);
  LCD_DisplayCustomChar(1);
//  move_character_up_down('A');


     while(1)
    {
	
        //TODO:: Please write your application code 
    }


}