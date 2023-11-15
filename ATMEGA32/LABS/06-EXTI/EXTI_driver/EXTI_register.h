/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	EXTI				**************************/
/***********************		DATE	:	OCT 22, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef MCAL_EXTI_EXTI_REGISTER_H_
#define MCAL_EXTI_EXTI_REGISTER_H_


/*Registers*/
#define MCUCR             	*((volatile u8*)0x55)
#define MCUCR_ISC00       	0
#define MCUCR_ISC01       	1
#define MCUCR_ISC10       	2
#define MCUCR_ISC11       	3

#define MCUCSR            	*((volatile u8*)0x54)
#define MCUCSR_ISC2       	6

#define GICR              	*((volatile u8*)0x5B)	//General Interrupt Control Register
#define GICR_INT2         	5
#define GICR_INT0         	6
#define GICR_INT1         	7

#define GIFR              	*((volatile u8*)0x5A)	//General Interrupt Flag Register
#define GIFR_INTF2        	5
#define GIFR_INTF0        	6
#define GIFR_INTF1      	7


#endif /* MCAL_EXTI_EXTI_REGISTER_H_ */
