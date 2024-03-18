/*
 * KEYPAD_program.c
 *
 * Created: 11/11/2023 12:09:15 PM
 *  Author: Youssef Ehab
 */ 

#include "std_types.h"
#include "bit_math.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

#include "KEYPAD_private.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"

/*
void HKEYPAD_vInit(void)
{
	for (int i = 0; i<ROWS; i++)
	{
		SET_BIT(Keypad_PORT,Rows[i]);
		CLEAR_BIT(Keypad_DIRECTORY,Rows[i]);
	}
	for (int j = 0; j<COLOMNS; j++)
	{
/ *		SET_BIT(Keypad_PORT,Colomns[j]);* /
		SET_BIT(Keypad_DIRECTORY,Colomns[j]);
	}
	
}*/

void HKEYPAD_vGetKey(u8 value[])
{
	u8 Keypad[4][4]	= KEYPAD_VALUES;
	u8 Colomns[4]	= COLOMNS_PIN_VALUES;
	u8 Rows[4]		= ROWS_PIN_VALUES;
	for (int i = 0; i < COLUMN_NUMBER;i++)
	{
		CLEAR_BIT(Keypad_PORT,Colomns[i]);
		for (int j = 0; j < ROW_NUMBER;j++)
		{
			if(GET_BIT(Keypad_PIN,Rows[j]) == 0)
			{
 			    while (GET_BIT(Keypad_PIN,Rows[j]) == 0)
				 {
					 *value = Keypad[j][i];
				 }
			}
		}
		SET_BIT(Keypad_PORT,Colomns[i]);
	}
}
/*
u8 HKEYPAD_vGetKey(void)
{
	u8 Local_u8ColIdx, Local_u8RowIdx;
	u8 Local_u8PressedKey = NULL;
	u8 Local_u8PinState;

	u8 Local_KPDArr[COLUMN_NUMBER][ROW_NUMBER] = KeypadValues;

	u8 Local_u8ColArr[COLUMN_NUMBER] = Colomns;

	u8 Local_u8RowArr[ROW_NUMBER] = Rows;

	for(Local_u8ColIdx=0; Local_u8ColIdx < COLUMN_NUMBER; Local_u8ColIdx++)
	{
		//1- Activate the current column
		MDIO_u8SetPinValue(Keypad_PORT, Local_u8ColArr[Local_u8ColIdx], MDIO_LOW);

		for(Local_u8RowIdx=0; Local_u8RowIdx < ROW_NUMBER; Local_u8RowIdx++)
		{
			//2- Read the current Row
			MDIO_u8GetPinValue(Keypad_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);

			if(Local_u8PinState == MDIO_LOW)
			{
				Local_u8PressedKey = Local_KPDArr[Local_u8RowIdx][Local_u8ColIdx];

				//wait until the key is released (polling with blocking)
				while(Local_u8PinState == MDIO_LOW)
				{
					MDIO_u8GetPinValue(Keypad_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}

		//3- DeActivate the current column
		MDIO_u8SetPinValue(Keypad_PORT, Local_u8ColArr[Local_u8ColIdx], MDIO_HIGH);
	}
	return Local_u8PressedKey;
}*/