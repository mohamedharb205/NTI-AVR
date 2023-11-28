/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	EXTI				**************************/
/***********************		DATE	:	OCT 22, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"






// Global Pointers to Functions
//void (*CallBackPtr0)(void) = NULL;		//#define NULL (void*)0     in TYPES.h
//void (*CallBackPtr1)(void) = NULL;
//void (*CallBackPtr2)(void) = NULL;

static void (*EXTI_CallBackPtr[3])(void) = {NULL, NULL, NULL} ;   // ARRAY OF 3 POINTERS TO FUNCTION


/*External Interrupt Initialization*/
void EXTI_voidINTInit()
{
		/* Interrupt 0 Initialization*/
	#if		INT0_STATE == EXTI_ENABLED
			/*Enable INT0*/
			SET_BIT(GICR , GICR_INT0);

			/*Configure Sense Control Option*/
			#if		INT0_SENSE_CONTROL_OPTION == EXTI_LOW_LEVEL
					CLR_BIT(MCUCR , MCUCR_ISC00);
					CLR_BIT(MCUCR , MCUCR_ISC01);

			#elif	INT0_SENSE_CONTROL_OPTION == EXTI_LOGICAL_CHANGE
					SET_BIT(MCUCR , MCUCR_ISC00);
					CLR_BIT(MCUCR , MCUCR_ISC01);

			#elif	INT0_SENSE_CONTROL_OPTION == EXTI_FALLING_EDGE
					CLR_BIT(MCUCR , MCUCR_ISC00);
					SET_BIT(MCUCR , MCUCR_ISC01);

			#elif	INT0_SENSE_CONTROL_OPTION == EXTI_RISING_EDGE
					SET_BIT(MCUCR , MCUCR_ISC00);
					SET_BIT(MCUCR , MCUCR_ISC01);

			#else
				#error "Wrong SENSE_CONTROL_OPTION_INT0 configuration option"
			#endif

	#elif	INT0_STATE == EXTI_DISABLED
			/*Disable INT0*/
			CLR_BIT(GICR , GICR_INT0);

	#else
		#error "Wrong EXTI_STATE_INT0 configuration option"
	#endif



		/*Interrupt 1 Initialization */
	#if		INT1_STATE == EXTI_ENABLED
			/*Enable INT1*/
			SET_BIT(GICR , GICR_INT1);

			/*Configure Sense Control Option*/
			#if		INT1_SENSE_CONTROL_OPTION == EXTI_LOW_LEVEL
					CLR_BIT(MCUCR , MCUCR_ISC10);
					CLR_BIT(MCUCR , MCUCR_ISC11);

			#elif	INT1_SENSE_CONTROL_OPTION == EXTI_LOGICAL_CHANGE
					SET_BIT(MCUCR , MCUCR_ISC10);
					CLR_BIT(MCUCR , MCUCR_ISC11);

			#elif	INT1_SENSE_CONTROL_OPTION == EXTI_FALLING_EDGE
					CLR_BIT(MCUCR , MCUCR_ISC10);
					SET_BIT(MCUCR , MCUCR_ISC11);

			#elif	INT1_SENSE_CONTROL_OPTION == EXTI_RISING_EDGE
					SET_BIT(MCUCR , MCUCR_ISC10);
				    SET_BIT(MCUCR , MCUCR_ISC11);

			#else
				#error "Wrong SENSE_CONTROL_OPTION_INT1 configuration option"
			#endif

	#elif	INT1_STATE == EXTI_DISABLED
			/*Disable INT1*/
			CLR_BIT(GICR , GICR_INT1);

	#else
		#error "Wrong EXTI_STATE_INT1 configuration option"
	#endif



		/*Interrupt 2 Initialization */
	#if		INT2_STATE == EXTI_ENABLED
			/*Enable INT2*/
			SET_BIT(GICR , GICR_INT2);

			/*Configure Sense Control Option*/
			#if		INT2_SENSE_CONTROL_OPTION == EXTI_FALLING_EDGE
					CLR_BIT(MCUCSR , MCUCSR_ISC2);

			#elif	INT2_SENSE_CONTROL_OPTION == EXTI_RISING_EDGE
					SET_BIT(MCUCSR , MCUCSR_ISC2);

			#else
				#error "Wrong SENSE_CONTROL_OPTION_INT2 configuration option"
			#endif

	#elif	INT2_STATE == EXTI_DISABLED
			/*Disable INT2*/
			CLR_BIT(GICR , GICR_INT2);

	#else
		#error "Wrong EXTI_STATE_INT2 configuration option"
	#endif
}




void EXTI0_voidSetTriggerSource(u8 copy_u8SenseOption)
{
	switch(copy_u8SenseOption)
	{
		case EXTI_LOW_LEVEL			:	CLR_BIT(MCUCR , MCUCR_ISC00);
										CLR_BIT(MCUCR , MCUCR_ISC01);
										break;

		case EXTI_LOGICAL_CHANGE	:	SET_BIT(MCUCR , MCUCR_ISC00);
										CLR_BIT(MCUCR , MCUCR_ISC01);
										break;

		case EXTI_FALLING_EDGE		:	CLR_BIT(MCUCR , MCUCR_ISC00);
										SET_BIT(MCUCR , MCUCR_ISC01);
										break;

		case EXTI_RISING_EDGE		:	SET_BIT(MCUCR , MCUCR_ISC00);
										SET_BIT(MCUCR , MCUCR_ISC01);
										break;

		default       				:  	break;
	}
}

void EXTI1_voidSetTriggerSource(u8 copy_u8SenseOption)
{
	switch(copy_u8SenseOption)
	{
		case EXTI_LOW_LEVEL			:	CLR_BIT(MCUCR , MCUCR_ISC10);
										CLR_BIT(MCUCR , MCUCR_ISC11);
										break;

		case EXTI_LOGICAL_CHANGE	:	SET_BIT(MCUCR , MCUCR_ISC10);
										CLR_BIT(MCUCR , MCUCR_ISC11);
										break;

		case EXTI_FALLING_EDGE		:	CLR_BIT(MCUCR , MCUCR_ISC10);
										SET_BIT(MCUCR , MCUCR_ISC11);
										break;

		case EXTI_RISING_EDGE		:	SET_BIT(MCUCR , MCUCR_ISC10);
										SET_BIT(MCUCR , MCUCR_ISC11);
										break;

		default       				:  	break;
	}
}

void EXTI2_voidSetTriggerSource(u8 copy_u8SenseOption)
{
	switch(copy_u8SenseOption)
	{
		case EXTI_FALLING_EDGE		:	CLR_BIT(MCUCSR , MCUCSR_ISC2);
										break;

		case EXTI_RISING_EDGE		:	SET_BIT(MCUCSR , MCUCSR_ISC2);
										break;

		default       				:  	break;
	}
}





void EXTI_voidCallBackINT0(void (*Copy_pvFunction) (void))		//Make "Copy_pvFunction" as global to be seen by ISR functions.
{
	EXTI_CallBackPtr[0] = Copy_pvFunction;
	//CallBackPtr0 = Copy_pvFunction;
}

void EXTI_voidCallBackINT1(void (*Copy_pvFunction) (void))		//Make "Copy_pvFunction" as global to be seen by ISR functions.
{
	EXTI_CallBackPtr[1] = Copy_pvFunction;
	//CallBackPtr1 = Copy_pvFunction;
}

void EXTI_voidCallBackINT2(void (*Copy_pvFunction) (void))		//Make "Copy_pvFunction" as global to be seen by ISR functions.
{
	EXTI_CallBackPtr[2] = Copy_pvFunction;
	//CallBackPtr2 = Copy_pvFunction;
}



/*To handle ISR  of INT0 */
void __vector_1(void) __attribute__((signal));		//Save this form "void __vector_no(void) __attribute__((signal));".		// to prevent the compiler optimization
void __vector_1(void)
{
	if(EXTI_CallBackPtr[0] != NULL)
	{
		/*Clear INT0 Flag*/
		SET_BIT(GIFR , GIFR_INTF0);

		EXTI_CallBackPtr[0]( );			// We put () because this is pointer to call function.
	}
	else
	{
		// DO NOTHING
	}
}


/*To handle ISR  of INT1*/
void __vector_2(void) __attribute__((signal));		//Save this form "void __vector_no(void) __attribute__((signal));".
void __vector_2(void)
{
	if(EXTI_CallBackPtr[1] != NULL)
	{
		/*Clear INT1 Flag*/
		SET_BIT(GIFR , GIFR_INTF1);

		EXTI_CallBackPtr[1]( );			// We put () because this is pointer to call function.
	}
	else
	{
		// DO NOTHING
	}
}


/*To handle ISR  of INT2*/
void __vector_3(void) __attribute__((signal));		//Save this form "void __vector_no(void) __attribute__((signal));".
void __vector_3(void)
{
	if(EXTI_CallBackPtr[2] != NULL)
	{
		/*Clear INT2 Flag*/
		SET_BIT(GIFR , GIFR_INTF2);

		EXTI_CallBackPtr[2]();			// We put () because this is pointer to call function.
	}
	else
	{
		// DO NOTHING
	}
}




