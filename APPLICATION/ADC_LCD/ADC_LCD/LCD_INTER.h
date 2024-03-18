/*
 * LCD_INTER.h
 *
 * Created: 2/10/2024 10:04:43 AM
 *  Author: miro
 */ 


#ifndef LCD_INTER_H_
#define LCD_INTER_H_

void LCD_SEND_COMM(u8 command);
void LCD_SEND_DATA(u8 data);
void LCD_INIT();
void LCD_SaveCustomChar(u8 location,u8 custom[]);
void LCD_DisplayCustomChar(u8 location);
void move_character_cursor(u8 character[]);
void move_character_up_down(u8 character);
#endif /* LCD_INTER_H_ */