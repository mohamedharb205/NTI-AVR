/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		DATE	:	OCT 22, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "00-main.h"

#include "../EXTI_driver/DIO_interface.h"
#include "../EXTI_driver/GIE_interface.h"
#include "../EXTI_driver/EXTI_interface.h"
#include "util/delay.h"


void EXTI_nesting(void)
{
	//Set INT0 Directions -> Pull up
	DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_HIGH);

	//Set INT1 Directions -> Pull up
	DIO_voidSetPinDirection(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8PIN_HIGH);


	//Set Led1 Directions -> Output
	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_LOW);

	//Set Led2 Directions -> Output
	DIO_voidSetPinDirection(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_LOW);


	GIE_voidEnableGlobal();
	EXTI_voidINTInit();
	EXTI0_voidSetTriggerSource(EXTI_FALLING_EDGE);
	EXTI1_voidSetTriggerSource(EXTI_RISING_EDGE);		// Don't to enable the interrupt 1 from config file

	EXTI_voidCallBackINT0(LedON);
	EXTI_voidCallBackINT1(LedOFF);


	while(1)
	{
		DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_HIGH);
		_delay_ms(200);
		DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_LOW);
		_delay_ms(200);
	}
}




void LedON()
{
	DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_LOW);
}

void LedOFF()
{
	DIO_voidSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_HIGH);
}
