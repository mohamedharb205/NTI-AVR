/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	DIO					**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "00-main.h"

#include "../LCD_driver/DIO_interface.h"
#include "../LCD_driver/LCD_interface.h"
#include "util/delay.h"



void LCD_test()
{
	LCD_voidInit();

	LCD_voidWriteCharacter('M');
	LCD_voidWriteCharacter('o');
	LCD_voidWriteCharacter('h');
	LCD_voidWriteCharacter('a');
	LCD_voidWriteCharacter('m');
	LCD_voidWriteCharacter('e');
	LCD_voidWriteCharacter('d');
	_delay_ms(1000);
	LCD_voidClear();

	LCD_voidGoToXY(0,8);
	LCD_voidWriteString("Hello");

	LCD_voidGoToXY(1,8);
	LCD_voidWriteDecimal(123450);

	LCD_voidGoToXY(2,10);
	LCD_voidWriteDecimal(0);

	LCD_voidGoToXY(2,8);
	LCD_voidWriteDecimal(-54289);

	_delay_ms(1000);
	LCD_voidClear();

	while(1)
	{
		for(u8 i = 0; i < 4; i++)
		{
			for(u8 j = 0; j < 20; j++)
			{
				LCD_voidGoToXY(i,j);
				LCD_voidWriteCharacter('*');
				_delay_ms(10);
				LCD_voidClearXY(i,j);
			}
		}
	}
}
