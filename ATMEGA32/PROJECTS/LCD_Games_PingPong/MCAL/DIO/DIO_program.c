/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	DIO					**************************/
/***********************		DATE	:	OCT 17, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/REG_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"





#if		DIO_ERRPR_STATE_NOTIFICATION_OPTION == DISABLED

		/********************************************************************************************************************/
		/*	Function: DIO_voidSetPinDirection																				*/
		/*	Description: Sets the direction (input/output) of a specific pin within a port.									*/
		/*	Parameters:																										*/
		/*		- Copy_u8Port: The port to set the pin direction for (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD).	*/
		/*		- Copy_u8Pin: The pin number (0-7) within the port.															*/
		/*		- Copy_u8Direction: The desired direction (DIO_u8PIN_OUTPUT or DIO_u8PIN_INPUT).							*/
		/********************************************************************************************************************/
		void DIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  SET_BIT(DDRA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  SET_BIT(DDRB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  SET_BIT(DDRC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  SET_BIT(DDRD , Copy_u8Pin); 	break;
						default       :  								break;
					}
				}
				else if(Copy_u8Direction == DIO_u8PIN_INPUT)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  CLR_BIT(DDRA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  CLR_BIT(DDRB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  CLR_BIT(DDRC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  CLR_BIT(DDRD , Copy_u8Pin); 	break;
						default       :  								break;
					}
				}
			}
		}



		/****************************************************************************************************************/
		/*   Function: DIO_voidSetPortDirection																			*/
		/*   Description: Sets the direction (input/output) of an entire port.											*/
		/*   Parameters:																								*/
		/*        - Copy_u8Port: The port to set the direction for (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD).*/
		/*        - Copy_u8Direction: The desired direction (DIO_PORT_OUTPUT or DIO_PORT_INPUT).						*/
		/****************************************************************************************************************/
		void DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
		{
			if( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT )
			{
				switch(Copy_u8Port)
				{
					case DIO_u8PORTA:  DDRA = Copy_u8Direction; 		break;
					case DIO_u8PORTB:  DDRB = Copy_u8Direction; 		break;
					case DIO_u8PORTC:  DDRC = Copy_u8Direction; 		break;
					case DIO_u8PORTD:  DDRD = Copy_u8Direction; 		break;
					default       :  									break;
				}
			}
		}



		/************************************************************************************************************************/
		/*    Function: DIO_voidSetPinValue																						*/
		/*    Description: Sets the value (high/low) of a specific pin within a port.											*/
		/*    Parameters:																										*/
		/*        - Copy_u8Port: The port to set the pin value for (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD).		*/
		/*        - Copy_u8Pin: The pin number (0-7) within the port.															*/
		/*        - Copy_u8PinValue: The desired value (DIO_u8PIN_HIGH or DIO_u8PIN_LOW).										*/
		/************************************************************************************************************************/
		void DIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				if(Copy_u8PinValue == DIO_u8PIN_HIGH)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  SET_BIT(PORTA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  SET_BIT(PORTB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  SET_BIT(PORTC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  SET_BIT(PORTD , Copy_u8Pin); 	break;
						default       	:  									break;
					}
				}
				else if(Copy_u8PinValue == DIO_u8PIN_LOW)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  CLR_BIT(PORTA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  CLR_BIT(PORTB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  CLR_BIT(PORTC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  CLR_BIT(PORTD , Copy_u8Pin); 	break;
						default       	:  									break;
					}
				}
			}
		}



		/****************************************************************************************************************/
		/*    Function: DIO_voidSetPortValue																			*/
		/*    Description: Sets the value (high/low) of an entire port.													*/
		/*    Parameters:																								*/
		/*        - Copy_u8Port: The port to set the value for (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD).	*/
		/*        - Copy_u8PortVALUE: The desired value (DIO_u8PORT_HIGH or DIO_u8PORT_LOW).							*/
		/****************************************************************************************************************/
		void DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue)
		{
			if( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT )
			{
				switch(Copy_u8Port)
				{
					case DIO_u8PORTA:  	PORTA = Copy_u8PortValue; 		break;
					case DIO_u8PORTB:  	PORTB = Copy_u8PortValue; 		break;
					case DIO_u8PORTC:  	PORTC = Copy_u8PortValue; 		break;
					case DIO_u8PORTD:  	PORTD = Copy_u8PortValue; 		break;
					default       	: 									break;
				}
			}
		}



		/********************************************************************************************************************/
		/*    Function: DIO_u8GetPinValue																					*/
		/*    Description: Reads the value of a specific pin within a port.													*/
		/*    Parameters:																									*/
		/*        - Copy_u8Port: The port to read the pin value from (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD).	*/
		/*        - Copy_u8Pin: The pin number (0-7) within the port.														*/
		/*    Returns: The value of the pin (DIO_u8PIN_HIGH or DIO_u8PIN_LOW).												*/
		/********************************************************************************************************************/
		u8 	 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				u8 Local_u8PinValue;

				switch(Copy_u8Port)
				{
					case DIO_u8PORTA: 	Local_u8PinValue = GET_BIT(PINA , Copy_u8Pin); 		break;
					case DIO_u8PORTB: 	Local_u8PinValue = GET_BIT(PINB , Copy_u8Pin); 		break;
					case DIO_u8PORTC: 	Local_u8PinValue = GET_BIT(PINC , Copy_u8Pin); 		break;
					case DIO_u8PORTD: 	Local_u8PinValue = GET_BIT(PIND , Copy_u8Pin); 		break;
					default      	: 														break;
				}

				return Local_u8PinValue;
			}

			else
			{
				return	-1;
			}
		}



		/****************************************************************************************************************************/
		/*    Function: DIO_voidTogglePin																							*/
		/*    Description: Toggles the value of a specific pin within a port.														*/
		/*    Parameters:																											*/
		/*        - Copy_u8Port: The port containing the pin to be toggled (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD).	*/
		/*        - Copy_u8Pin: The pin number (0-7) to be toggled.																	*/
		/****************************************************************************************************************************/
		void DIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				switch (Copy_u8Port)
				{
					case DIO_u8PORTA : 	TOG_BIT(PORTA , Copy_u8Pin); 		break ;
					case DIO_u8PORTB : 	TOG_BIT(PORTB , Copy_u8Pin); 		break ;
					case DIO_u8PORTC : 	TOG_BIT(PORTC , Copy_u8Pin); 		break ;
					case DIO_u8PORTD :	TOG_BIT(PORTD , Copy_u8Pin); 		break ;
					default 	   	 : 							 			break ;
				}
			}
		}



		/****************************************************************************************************************************/
		/*    Function: DIO_voidTogglePort																							*/
		/*    Description: Toggles the values of the entire port.																	*/
		/*    Parameters:																											*/
		/*        - Copy_u8Port: The port containing the pins to be toggled (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD).	*/
		/****************************************************************************************************************************/
		void DIO_voidTogglePort(u8 Copy_u8Port)
		{
			if( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT )
			{
				switch (Copy_u8Port)
				{
					case DIO_u8PORTA : 	TOG_REG(PORTA , DIO_u8PORT_HIGH); 		break ;
					case DIO_u8PORTB : 	TOG_REG(PORTB , DIO_u8PORT_HIGH); 		break ;
					case DIO_u8PORTC : 	TOG_REG(PORTC , DIO_u8PORT_HIGH); 		break ;
					case DIO_u8PORTD :	TOG_REG(PORTD , DIO_u8PORT_HIGH); 		break ;
					default 	     :	 										break ;
				}
			}
		}


#elif	DIO_ERRPR_STATE_NOTIFICATION_OPTION == ENABLED

		u8 DIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction)
		{
			u8 Local_u8ErrorState = OK;

			if(Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN )	// Check PINS
			{
				if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  SET_BIT(DDRA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  SET_BIT(DDRB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  SET_BIT(DDRC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  SET_BIT(DDRD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PINS
					}
				}
				else if(Copy_u8Direction == DIO_u8PIN_INPUT)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  CLR_BIT(DDRA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  CLR_BIT(DDRB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  CLR_BIT(DDRC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  CLR_BIT(DDRD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PORTS
					}
				}
				else /*Direction is not OUTPUT nor INPUT*/
				{
					Local_u8ErrorState = NOK;
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}


		u8 DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
		{
			u8 Local_u8ErrorState = OK;

			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:  DDRA = Copy_u8Direction; 	break;
				case DIO_u8PORTB:  DDRB = Copy_u8Direction; 	break;
				case DIO_u8PORTC:  DDRC = Copy_u8Direction; 	break;
				case DIO_u8PORTD:  DDRD = Copy_u8Direction; 	break;
				default       	:  Local_u8ErrorState = NOK;	break;	/*Wrong PORT*/
			}

			return Local_u8ErrorState;
		}


		u8 DIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue)
		{
			u8 Local_u8ErrorState = OK;

			if(Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN )	// Check PINS
			{
				if(Copy_u8PinValue == DIO_u8PIN_HIGH)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  SET_BIT(PORTA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  SET_BIT(PORTB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  SET_BIT(PORTC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  SET_BIT(PORTD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PINS
					}
				}
				else if(Copy_u8PinValue == DIO_u8PIN_LOW)
				{
					switch(Copy_u8Port)
					{
						case DIO_u8PORTA:  CLR_BIT(PORTA , Copy_u8Pin); 	break;
						case DIO_u8PORTB:  CLR_BIT(PORTB , Copy_u8Pin); 	break;
						case DIO_u8PORTC:  CLR_BIT(PORTC , Copy_u8Pin); 	break;
						case DIO_u8PORTD:  CLR_BIT(PORTD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PORTS
					}
				}
				else /*VALUE is not Valid*/
				{
					Local_u8ErrorState = NOK;
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}



		u8 DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue)
		{
			u8 Local_u8ErrorState = OK;

			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:  PORTA = Copy_u8PortValue; 	break;
				case DIO_u8PORTB:  PORTB = Copy_u8PortValue; 	break;
				case DIO_u8PORTC:  PORTC = Copy_u8PortValue; 	break;
				case DIO_u8PORTD:  PORTD = Copy_u8PortValue; 	break;
				default       	:  Local_u8ErrorState = NOK;	break;	/*Wrong PORT*/
			}

			return Local_u8ErrorState;
		}



		u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value)
		{
			u8 Local_u8ErrorState = OK;

			if((Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN) && (Copy_pu8Value != NULL))	// Check PINS and Pointer
			{
				switch(Copy_u8Port)
				{
					case DIO_u8PORTA:  		*Copy_pu8Value = GET_BIT(PINA , Copy_u8Pin); 	break;
					case DIO_u8PORTB:  		*Copy_pu8Value = GET_BIT(PINB , Copy_u8Pin); 	break;
					case DIO_u8PORTC:  		*Copy_pu8Value = GET_BIT(PINC , Copy_u8Pin); 	break;
					case DIO_u8PORTD:  		*Copy_pu8Value = GET_BIT(PIND , Copy_u8Pin); 	break;
					default       	:  		Local_u8ErrorState = NOK;						break;	// Check PINS
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}



		u8 DIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin)
		{
			u8 Local_u8ErrorState = OK;

			if(Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN )	// Check PINS
			{
				switch(Copy_u8Port)
				{
					case DIO_u8PORTA:  TOG_BIT(PORTA , Copy_u8Pin); 	break;
					case DIO_u8PORTB:  TOG_BIT(PORTB , Copy_u8Pin); 	break;
					case DIO_u8PORTC:  TOG_BIT(PORTC , Copy_u8Pin); 	break;
					case DIO_u8PORTD:  TOG_BIT(PORTD , Copy_u8Pin); 	break;
					default       	:  Local_u8ErrorState = NOK;		break;	// Check PINS
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}



		u8 DIO_voidTogglePort(u8 Copy_u8Port)
		{
			u8 Local_u8ErrorState = OK;

			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:  TOG_REG(PORTA , Copy_u8Port); 	break;
				case DIO_u8PORTB:  TOG_REG(PORTB , Copy_u8Port); 	break;
				case DIO_u8PORTC:  TOG_REG(PORTC , Copy_u8Port); 	break;
				case DIO_u8PORTD:  TOG_REG(PORTD , Copy_u8Port); 	break;
				default       	:  Local_u8ErrorState = NOK;		break;	/*Wrong PORT*/
			}

			return Local_u8ErrorState;
		}

#endif



