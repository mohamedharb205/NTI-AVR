/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	MAIN				**************************/
/***********************		DATE	:	OCT 29, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "../USART_driver/DIO_interface.h"
#include "../USART_driver/LCD_interface.h"
#include "../USART_driver/USART_interface.h"

int main()
{
	u8 Local_u8Data;
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_INPUT);
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);

	DIO_voidSetPinDirection(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	LCD_voidInit();

	USART_Init();

	while (1)
	{
		Local_u8Data = USART_Receive();

		LCD_voidGoToXY(0,0);
		LCD_voidWriteCharacter(Local_u8Data);

		if (Local_u8Data == '1')
		{
			DIO_voidSetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
		}
		else if (Local_u8Data == '2')
		{
			DIO_voidSetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
		}
		else
		{

		}

		USART_Transmit('D');
	}

	return 0;
}
