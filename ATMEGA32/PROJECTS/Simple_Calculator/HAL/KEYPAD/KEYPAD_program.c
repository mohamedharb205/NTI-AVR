/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	KEYPAD				**************************/
/***********************		DATE	:	OCT 21, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include <util/delay.h>



u8 Rows[4] = {KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN, KEYPAD_ROW4_PIN};
u8 Cols[4] = {KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN, KEYPAD_COL4_PIN};



void KeyPad_voidInit(void)
{
	for(u8 RowCounter = 0; RowCounter < ROWS_NUM; RowCounter++)
	{
		DIO_voidSetPinDirection(KEYPAD_ROWS_PORT, Rows[RowCounter], DIO_u8PIN_OUTPUT);
		DIO_voidSetPinValue(KEYPAD_ROWS_PORT, Rows[RowCounter], DIO_u8PIN_HIGH);
	}

	for(u8 ColCounter = 0; ColCounter < COLS_NUM; ColCounter++)
	{
		DIO_voidSetPinDirection(KEYPAD_COLS_PORT, Cols[ColCounter], DIO_u8PIN_INPUT);
		DIO_voidSetPinValue(KEYPAD_COLS_PORT, Cols[ColCounter], DIO_u8PIN_HIGH);	// PULL UP
	}
}



u8 KeyPad_u8GetPress(void)
{
	u8 Local_u8Col;
	u8 Local_u8Index = KEYPAD_NOT_PRESSED;

	for(u8 RowCounter = 0; RowCounter < ROWS_NUM; RowCounter++)
	{
		Select_voidLine(Rows[RowCounter]);
		Local_u8Col = Read_u8Button(Rows[RowCounter]);
		if(Local_u8Col != KEYPAD_NOT_PRESSED)
			Local_u8Index = (RowCounter*4) + Local_u8Col;
		_delay_ms(2);
	}
	return KeyPad_Char[Local_u8Index];
}



u8 Read_u8Button(u8 Copy_u8Line)
{

	for(u8 ColCounter = 0; ColCounter < 4; ColCounter++)
	{
		if(DIO_u8GetPinValue(KEYPAD_COLS_PORT, Cols[ColCounter]) == DIO_u8PIN_LOW)
		{
			DIO_voidSetPinValue(KEYPAD_ROWS_PORT, Copy_u8Line, DIO_u8PIN_HIGH);
			return ColCounter;
		}
	}

	DIO_voidSetPinValue(KEYPAD_ROWS_PORT, Copy_u8Line, DIO_u8PIN_HIGH);
	return KEYPAD_NOT_PRESSED;


}
void Select_voidLine(u8 Copy_u8Line)
{
	DIO_voidSetPinValue(KEYPAD_ROWS_PORT, Copy_u8Line, DIO_u8PIN_LOW);
}
