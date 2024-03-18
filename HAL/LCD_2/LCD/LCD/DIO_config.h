/*
 * DIO_config.h
 *
 * Created: 11/10/2023 9:20:30 AM
 *  Author: Youssef Ehab
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

u8 MDIO_u8SetPinDirection(u8 MDIO_u8PortName, u8 MDIO_u8PinNumber, u8 MDIO_u8PinDirection);
u8 MDIO_u8SetPinValue(u8 MDIO_u8PortName, u8 MDIO_u8PinNumber, u8 MDIO_u8PinValue);
u8 MDIO_u8GetPinValue(u8 MDIO_u8PortName, u8 MDIO_u8PinNumber, u8* MDIO_u8PinValue);




#endif /* DIO_CONFIG_H_ */