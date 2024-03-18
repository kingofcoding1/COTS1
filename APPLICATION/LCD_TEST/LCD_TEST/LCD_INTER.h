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
void LCD_INT();



#endif /* LCD_INTER_H_ */