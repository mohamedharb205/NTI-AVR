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

#include "../PORT_driver/PORT_interface.h"
#include "util/delay.h"




void Led_ON()
{
	// Configuration
	PORT_voidInit();

	while(1)
	{
		asm("NOP");
	}
}