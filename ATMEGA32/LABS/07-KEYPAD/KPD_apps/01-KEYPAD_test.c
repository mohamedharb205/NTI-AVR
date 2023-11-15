/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	KPD					**************************/
/***********************		DATE	:	OCT 21, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "00-main.h"
#include "../KPD_driver/DIO_interface.h"
#include "../KPD_driver/KEYPAD_interface.h"
#include "../KPD_driver/LCD_interface.h"
#include "util/delay.h"



u8 Button = KEYPAD_NOT_PRESSED;

void KeyPad_test(void)
{
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	KeyPad_voidInit();
	LCD_voidInit();

	while(1)
	{
		Get_Button();
	}
}


void Get_Button()
{
	do
	{
		Button = KeyPad_u8GetPress();
	}while(Button == '\0');

	LCD_voidWriteCharacter(Button);
	_delay_ms(200);
}

