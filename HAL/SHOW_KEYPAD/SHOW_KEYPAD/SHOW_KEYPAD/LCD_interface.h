/*
 * LCD_interface.h
 *
 * Created: 11/10/2023 1:04:41 PM
 *  Author: Youssef Ehab
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void HLCD_vSendData(u8 LCD_Data);
void HLCD_vSendCommand(u8 LCD_Data);
void HLCD_vInit(void);
void HLCD_vShowString(u8 const *str);
void HLCD_vClearDisplay(void);
void HLCD_vSaveCustomChar(u8 location,u8 *custom);
void HLCD_vDisplayCustomChar(u8 location);
void HLCD_vGoTo(u8 X,u8 Y);
void HLCD_vContinousDisplay(u8 const str[]);

#endif /* LCD_INTERFACE_H_ */