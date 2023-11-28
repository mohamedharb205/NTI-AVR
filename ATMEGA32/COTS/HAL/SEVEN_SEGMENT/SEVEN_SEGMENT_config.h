/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	SEVEN SEGMENT		**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/



#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CONFIG_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CONFIG_H_



/* BCD PORT*/
#define 		BCD_PORT								DIO_u8PORTB

/* ENABLE PORTS */
#define 		ENABLE_PORT1							DIO_u8PORTA
#define 		ENABLE_PORT2							DIO_u8PORTB



/* Seven Segments */
#define 		FIRST_SEVEN_SEGMENT						1		// First Seven Segment
#define 		SECOND_SEVEN_SEGMENT					2		// Second Seven Segment
#define 		THIRD_SEVEN_SEGMENT						3
#define 		FOURTH_SEVEN_SEGMENT					4



/* Enable Pins */
#define 		FIRST_SEVEN_SEGMENT_ENABLE_PIN			DIO_u8PIN3
#define 		SECOND_SEVEN_SEGMENT_ENABLE_PIN			DIO_u8PIN2
#define 		THIRD_SEVEN_SEGMENT_ENABLE_PIN			DIO_u8PIN5
#define 		FOURTH_SEVEN_SEGMENT_ENABLE_PIN			DIO_u8PIN6

/* BCD Pins of BCD Seven Segment  */
#define 		BCD_PIN_D0								DIO_u8PIN0
#define 		BCD_PIN_D1								DIO_u8PIN1
#define 		BCD_PIN_D2								DIO_u8PIN2
#define 		BCD_PIN_D3								DIO_u8PIN4



#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CONFIG_H_ */
