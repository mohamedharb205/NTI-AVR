/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	MAIN				**************************/
/***********************		DATE	:	NOV 26, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/





#ifndef F_CPU
#define F_CPU	8000000
#endif

#include "../RTOS_driver/STD_TYPES.h"
#include "../RTOS_driver/GIE_interface.h"
#include "../RTOS_driver/DIO_interface.h"
#include "../RTOS_driver/TIMER0_interface.h"
#include "../RTOS_driver/RTOS_interface.h"
#include "util/delay.h"



void Led1();
void Led2();
void Led3();


int main(void)
{
	//Timer0_voidInit();

	// Configuration
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);	// Red led
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_OUTPUT);	// yellow led
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_OUTPUT);	// Green led

	DIO_voidSetPinDirection(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_OUTPUT);	// oscillescope pin


	//Timer0_voidCallBack(&Led1);

	//Led1();
	RTOS_voidCreateTask(0, 1000, 0, Led1);
	RTOS_voidCreateTask(1, 2000, 0, Led2);
	RTOS_voidCreateTask(2, 3000, 0, Led3);

	RTOS_voidStart();

	while (1)
	{

	}
	return 0;
}





void Led1()
{
	/* To measure the execution time */
	/* 1- set pin of oscilliscope as high */
	DIO_voidSetPinValue(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_HIGH);

	/* Task Implementation */
	DIO_voidTogglePin(DIO_u8PORTA, DIO_u8PIN0);

	/* 2- Set pin to Low */
	DIO_voidSetPinValue(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_LOW);

	//	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
//	_delay_ms(400);
//
//	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
//	_delay_ms(200);		// it is very important to show that it turn on and off
}



void Led2()
{
	DIO_voidTogglePin(DIO_u8PORTA, DIO_u8PIN1);
//	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_HIGH);
//	_delay_ms(400);
//
//	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_LOW);
//	_delay_ms(200);
}



void Led3()
{
	DIO_voidTogglePin(DIO_u8PORTA, DIO_u8PIN2);
//	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_HIGH);
//	_delay_ms(400);
//
//	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_LOW);
//	_delay_ms(200);
}
