/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	DIO					**************************/
/***********************		DATE	:	OCT 17, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "STD_TYPES.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*PINS DIRECTIONS*/
#define 	DIO_u8PIN_INPUT			0
#define 	DIO_u8PIN_OUTPUT		1

/*PORTS DIRECTIONS*/
#define 	DIO_u8PORT_INPUT		0x00	//0b00000000
#define 	DIO_u8PORT_OUTPUT     	0xFF	//0b11111111


/*PINS VALUES*/
#define 	DIO_u8PIN_LOW			0
#define 	DIO_u8PIN_HIGH			1

/*PORTS VALUES*/
#define 	DIO_u8PORT_LOW 	    	0x00	//0b00000000
#define 	DIO_u8PORT_HIGH			0xFF	//0b11111111


/*****		PORTS 		*****/
#define 	DIO_u8PORTA       		0
#define 	DIO_u8PORTB       		1
#define 	DIO_u8PORTC       		2
#define 	DIO_u8PORTD       		3

/*****		 PINS		*****/
#define 	DIO_u8PIN0            	0
#define 	DIO_u8PIN1            	1
#define 	DIO_u8PIN2            	2
#define 	DIO_u8PIN3            	3
#define 	DIO_u8PIN4            	4
#define 	DIO_u8PIN5            	5
#define 	DIO_u8PIN6            	6
#define 	DIO_u8PIN7            	7



#define 	ENABLED					1
#define 	DISABLED				2



/*********************************************************************************/
/*****		 The Error State Notification Option can be configured as:		******/
/*****						1- ENABLED			2- DISABLED					******/
/*********************************************************************************/
#define 	DIO_ERRPR_STATE_NOTIFICATION_OPTION			DISABLED






/**********************************************************************************************/
/**************		FUNCTION PROTOTYPES WITHOUT ERROR STATE NOTIFICATION		***************/
/**********************************************************************************************/
#if		DIO_ERRPR_STATE_NOTIFICATION_OPTION == DISABLED

		void DIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);
		void DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);

		void DIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue);
		void DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue);

		u8 	 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);

		void DIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin);
		void DIO_voidTogglePort(u8 Copy_u8Port);

/**********************************************************************************************/
/**************		FUNCTION PROTOTYPES WITH ERROR STATE NOTIFICATION		*******************/
/**********************************************************************************************/
#elif	DIO_ERRPR_STATE_NOTIFICATION_OPTION == ENABLED

		u8 DIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);
		u8 DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);

		u8 DIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue);
		u8 DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue);

		u8 	 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value);

		u8 DIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin);
		u8 DIO_voidTogglePort(u8 Copy_u8Port);

#endif


#endif /* DIO_INTERFACE_H_ */
