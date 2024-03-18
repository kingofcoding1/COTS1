/*
 * DIO_INTERFACE.h
 *
 * Created:  2/9/2024 9:19:31 AM
 *  Author:   miro
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_SETPINDIRECTION(u8 Port, u8 Pin ,u8 Value);
void DIO_SETPINVALUE(u8 Port, u8 Pin ,u8 Value);
u8 DIO_GETPINVALUE(u8 Port, u8 Pin);








#endif /* DIO_INTERFACE_H_ */