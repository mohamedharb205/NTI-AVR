/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	USART				**************************/
/***********************		DATE	:	OCT 29, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_



/*******************************************************************/
/********	MODE OF OPERATION CONFIGURATION:				********/
/********					    		1- SYNCHRONOUS 		********/
/********					    		2- ASYNCHRONOUS 	********/
/*******************************************************************/
#define 		MODE_OF_OPERATION			ASYNCHRONOUS



/*******************************************************************/
/********	SPEED OPERATION CONFIGURATION:					********/
/********					    1- NORMAL_SPEED_MODE 		********/
/********					    2- DOUBLE_SPEED_MODE 		********/
/*******************************************************************/
#define 		SPEED_OPERATION				NORMAL_SPEED_MODE



/*******************************************************************/
/********	DATA FRAME SIZE CONFIGURATION:					********/
/********					    1- FIVE_BITS		 		********/
/********					    2- SIX_BITS		 			********/
/********					    3- SEVEN_BITS		 		********/
/********					    4- EIGHT_BITS		 		********/
/********					    5- NINE_BITS		 		********/
/*******************************************************************/
#define 		DATA_FRAME_SIZE				EIGHT_BITS




/*******************************************************************/
/********	PARITY MODE CONFIGURATION:						********/
/********					    1- DISABLED			 		********/
/********					    2- EVEN			 			********/
/********					    3- ODD				 		********/
/*******************************************************************/
#define 		PARITY_MODE					DISABLED




/*******************************************************************/
/********	STOP BIT SELECT CONFIGURATION:					********/
/********					    1- ONE_BIT			 		********/
/********					    2- TWO_BITs		 			********/
/*******************************************************************/
#define 		STOP_BIT_SELECT					ONE_BIT




/*******************************************************************/
/********	CLOCK POLARITY CONFIGURATION:					********/
/********					    1- RISING			 		********/
/********					    2- FALLING		 			********/
/*******************************************************************/
#define 		CLOCK_POLARITY					RISING




#endif /* USART_CONFIG_H_ */
