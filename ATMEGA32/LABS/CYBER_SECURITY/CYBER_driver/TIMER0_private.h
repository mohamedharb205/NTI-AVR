/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	TIMER0				**************************/
/***********************		DATE	:	OCT 27, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_


/* TIMER0 MODE CONFIGURATION */
#define 		NORMAL_MODE					0
#define 		PWM_PHASE_CORRECT			1
#define 		CTC_MODE					2
#define 		FAST_PWM					3


/* TIMER0 PRESCALLER CONFIGURATION */
#define 		NO_CLK_SOURCE				0
#define 		NO_PRESCALAR				1
#define 		PRESCALAR_8					2
#define 		PRESCALAR_64				3
#define 		PRESCALAR_256				4
#define 		PRESCALAR_1024				5
#define 		COUNTER_FALLING_EDGE		6
#define 		COUNTER_RISING_EDGE			7


#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
