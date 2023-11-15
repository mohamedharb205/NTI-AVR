/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP				**************************/
/***********************		DATE	:	OCT 22, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "00-main.h"

#include "../EXTI_driver/DIO_interface.h"
#include "../EXTI_driver/GIE_interface.h"
#include "../EXTI_driver/EXTI_interface.h"
#include "util/delay.h"



#include "00-main.h"

#include "../EXTI_driver/DIO_interface.h"
#include "../EXTI_driver/GIE_interface.h"
#include "../EXTI_driver/EXTI_interface.h"
#include "util/delay.h"



void EXTI_test(void)
{
	//Set INT0 Directions -> Pull up
	DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_HIGH);

	//Set INT1 Directions -> Pull up
	DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8PIN_HIGH);
	//Set INT2 Directions -> Pull up
	DIO_voidSetPinDirection(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_INPUT);	//PULL UP Button 2
	DIO_voidSetPinValue(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_HIGH);


	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_OUTPUT);	//LED
	DIO_voidSetPortDirection(DIO_u8PORTC, DIO_u8PORT_OUTPUT);				//LEDS


	GIE_voidEnableGlobal();
	EXTI_voidINTInit();
	EXTI0_voidSetTriggerSource(EXTI_RISING_EDGE);
	EXTI1_voidSetTriggerSource(EXTI_RISING_EDGE);		// Don't to enable the interrupt 1 from config file
	EXTI2_voidSetTriggerSource(EXTI_RISING_EDGE);		// Don't to enable the interrupt 2 from config file

	EXTI_voidCallBackINT0(Led3456);
	EXTI_voidCallBackINT1(Led12);
	EXTI_voidCallBackINT2(Led0);


	while(1)
	{

		DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_HIGH);
		_delay_ms(100);
		DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_LOW);
		_delay_ms(100);
	}
}



void Led0(void)
{
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN0 , DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN1 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN3 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN4 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN5 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN6 , DIO_u8PIN_LOW);
	_delay_ms(500);
}

void Led12(void)
{
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN0 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN1 , DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN3 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN4 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN5 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN6 , DIO_u8PIN_LOW);
	_delay_ms(500);
}


void Led3456(void)
{
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN0 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN1 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN3 , DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN4 , DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN5 , DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTC , DIO_u8PIN6 , DIO_u8PIN_HIGH);
	_delay_ms(500);
}

