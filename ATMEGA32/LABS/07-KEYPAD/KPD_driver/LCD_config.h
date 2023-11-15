/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	LCD					**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/



#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/*******************************************************************************************/
/********		LCD Connection Mode Configuration :  								********/
/********											1- LCD_FOUR_BIT_MODE  			********/
/********											2- LCD_EIGHT_BIT_MODE 			********/
/*******************************************************************************************/
#define				CONNECTION_MODE					LCD_FOUR_BIT_MODE



/*******************************************************************************************/
/********		LCD Read Operation Enable Configuration  :  						********/
/********												1- LCD_ENABLED		  		********/
/********												2- LCD_DISABLED		 		********/
/*******************************************************************************************/
#define				READ_OPERATION_STATUS 			LCD_DISABLED


#if		CONNECTION_MODE == LCD_FOUR_BIT_MODE
		#define 	LCD_D4_PIN 						DIO_u8PIN0
		#define 	LCD_D5_PIN 						DIO_u8PIN1
		#define 	LCD_D6_PIN 						DIO_u8PIN2
		#define 	LCD_D7_PIN 						DIO_u8PIN4
#endif




#define 			LCD_CTRL_PORT	 				DIO_u8PORTA
#define 			LCD_DATA_PORT 					DIO_u8PORTB

#define 			LCD_EN_PIN 						DIO_u8PIN2
#define 			LCD_RS_PIN 						DIO_u8PIN3

#if 	READ_OPERATION_STATUS == LCD_ENABLED
		#define 	LCD_RW_PIN 						DIO_u8PIN1
#endif



#endif /* HAL_LCD_LCD_CONFIG_H_ */
