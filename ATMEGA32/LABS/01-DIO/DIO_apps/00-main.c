/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	MAIN				**************************/
/***********************		DATE	:	OCT 17, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/





#ifndef F_CPU
#define F_CPU	16000000
#endif

#include "00-main.h"

#include "util/delay.h"



int main()
{
	#if		MAIN_APP == LED_BLINKING
			Led_Blinking();

	#elif	MAIN_APP == TOGGLE_LED
			Toggle_Leds();

	#elif	MAIN_APP == PUSH_BUTTON
			Push_Button();

	#else
	#endif



	return 0;
}