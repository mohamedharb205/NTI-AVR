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




void Push_Button()
{
	// Configuration
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_OUTPUT);	//Green led
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_OUTPUT);	//Blue led
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_OUTPUT);	//yellow led
	DIO_voidSetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_OUTPUT);	//Red led

	//PORT_voidInit();
	DIO_voidSetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_HIGH);	// PULL UP

	while(1)
	{
		while(DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN0) == 0 && DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN1) == 1)
		{
			Led_ON();
		}
		while(DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN0) == 1 && DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN1) == 0)
		{
			Led_OFF();
		}
		Led_OFF();
	}
}



void Led_ON()
{
	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_HIGH);
	_delay_ms(200);		// it is very important to show that it turn on and off
}


void Led_OFF()
{
	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_LOW);
	_delay_ms(200);
}
