/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	EXTI				**************************/
/***********************		DATE	:	OCT 22, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "STD_TYPES.h"


#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


/*CONFIGURE INT TRIGGER SOURCE , OPTIONS */
#define 	EXTI_LOW_LEVEL				1
#define 	EXTI_LOGICAL_CHANGE			2
#define 	EXTI_FALLING_EDGE			3
#define 	EXTI_RISING_EDGE			4



/*External Interrupt Initialization*/
void  EXTI_voidINTInit();

void EXTI0_voidSetTriggerSource(u8 Copy_u8SenseOption);
void EXTI1_voidSetTriggerSource(u8 Copy_u8SenseOption);
void EXTI2_voidSetTriggerSource(u8 Copy_u8SenseOption);

/* returnType (*NamePtr) (Argument) */
void EXTI_voidCallBackINT0(void (*Copy_pvFunction) (void));		//Pointer to function.
void EXTI_voidCallBackINT1(void (*Copy_pvFunction) (void));
void EXTI_voidCallBackINT2(void (*Copy_pvFunction) (void));


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
