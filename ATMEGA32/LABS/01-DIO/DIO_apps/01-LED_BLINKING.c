/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	DIO					**************************/
/***********************		DATE	:	OCT 17, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "00-main.h"

#include "../DIO_driver/DIO_interface.h"
#include "util/delay.h"




void Led_Blinking()
{
	// Configuration
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_OUTPUT);	//Green led
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_OUTPUT);	//Blue led
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_OUTPUT);	//yellow led
	DIO_voidSetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_OUTPUT);	//Red led

	while(1)
	{
		DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_LOW);
		DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_LOW);
		DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_LOW);
		DIO_voidSetPinValue(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_LOW);
		_delay_ms(200);

		DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_HIGH);
		DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_HIGH);
		DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_HIGH);
		DIO_voidSetPinValue(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_HIGH);
		_delay_ms(200);		// it is very important to show that it turn on and off
	}
}
