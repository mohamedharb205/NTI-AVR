/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	TIMER0				**************************/
/***********************		DATE	:	OCT 27, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"


#ifndef NULL
#define 	NULL		 				(void*)0
#endif

static void (*Global_pvCallbackFuncTimer0)(void) = NULL;


void Timer0_voidInit()
{
	/* 1- Select TIMER0_MODE */
	#if 	TIMER0_MODE == NORMAL_MODE
			CLR_BIT(TCCR0 , TCCR0_WGM00);
			CLR_BIT(TCCR0 , TCCR0_WGM01);

	#elif	TIMER0_MODE == PWM_PHASE_CORRECT
			SET_BIT(TCCR0 , TCCR0_WGM00);
			CLR_BIT(TCCR0 , TCCR0_WGM01);

	#elif	TIMER0_MODE == CTC_MODE
			CLR_BIT(TCCR0 , TCCR0_WGM00);
			SET_BIT(TCCR0 , TCCR0_WGM01);

	#elif	TIMER0_MODE == FAST_PWM
			SET_BIT(TCCR0 , TCCR0_WGM00);
			SET_BIT(TCCR0 , TCCR0_WGM01);

	#else
		#error	"INVALID TIMER0 MODE CONFIGURATION !!!"
	#endif


	/* 2- Select Prescaller */
	#if 	TIMER0_PRESCALLER == PRESCALAR_8
			TCCR0 &= 0b11111000;
			TCCR0 |= 0b00000010;

//	#elif	TIMER0_PRESCALLER == PWM_PHASE_CORRECT
//			SET_BIT(TCCR0 , TCCR0_WGM00);
//			CLR_BIT(TCCR0 , TCCR0_WGM01);
//
//	#elif	TIMER0_PRESCALLER == CTC_MODE
//			CLR_BIT(TCCR0 , TCCR0_WGM00);
//			SET_BIT(TCCR0 , TCCR0_WGM01);
//
//	#elif	TIMER0_PRESCALLER == FAST_PWM
//			SET_BIT(TCCR0 , TCCR0_WGM00);
//			SET_BIT(TCCR0 , TCCR0_WGM01);

	#else
		#error	"INVALID TIMER0 PRESCALLER CONFIGURATION !!!"
	#endif


	/*3- Set Preload value*/
	//TCNT0 = 192;

	/*4- Enable Timer interrupt*/
	SET_BIT(TIMSK , TIMSK_TOIE0);
}


void Timer0_voidSetTCNT(u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload;
}


u8 	 Timer0_u8GetTCNT()
{
	return TCNT0;
}


void Timer0_voidSetOCR(u8 Copy_u8Preload)
{
	OCR0 = Copy_u8Preload;
}



void Timer0_voidCallBack(void (*Copy_pvCallBack)(void))
{
	Global_pvCallbackFuncTimer0 = Copy_pvCallBack;
}



void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void)
{
	static u8 Local_u8Counter;

	if(Local_u8Counter == 5)
	{
		/* Excute the action */
		if(Global_pvCallbackFuncTimer0 != NULL)
		{
			Global_pvCallbackFuncTimer0(); /*Calling*/
		}

		/* Counter = 0 */
		Local_u8Counter = 0;

		/* Set the TCNT with Preload Value */
		//TCNT0 = 192;
	}
}
