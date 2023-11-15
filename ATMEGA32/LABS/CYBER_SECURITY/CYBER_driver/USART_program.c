/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	USART				**************************/
/***********************		DATE	:	OCT 29, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/



#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "USART_interface.h"
#include "USART_register.h"
#include "USART_config.h"


void USART_Init( )
{
	/* 1- Select the character size in bit 2 */
	CLR_BIT(UCSRB , UCSRB_UCSZ2);

	/* Select UCSRC register
	 * - Asynchronous mode
	 * - No parity
	 * - 1 stop bit
	 * - 8 bit character size
	 * - Polarity = 0 */
	UCSRC = 0b10000110;

	/* 2- Set the baud rate 9600 bps */
	/* Set UBRRL with 51 if you used F_CPU = 8 MHZ   ... else if you used F_CPU = 16 MHZ hense you shoud set UBRRL with 103 to get the desired baud rate */
	UBRRL = 51;

	/* 3- Enable the RX and TX */
	SET_BIT(UCSRB , UCSRB_RXEN);
	SET_BIT(UCSRB , UCSRB_TXEN);
}





void USART_Transmit(u8 Copy_u8Data)
{
	/* Wait until the transmit buffer empty flag raised to be ready for new data */
	while(GET_BIT(UCSRA , UCSRA_UDRE) == 0);

	/* Put the new data */
	UDR = Copy_u8Data;
}



u8 USART_Receive()
{
	/* Wait until the receive buffer complete flag raised and the data to be ready in UDR */
	while(GET_BIT(UCSRA , UCSRA_RXC) == 0);

	/* Read or return the data */
	return UDR;
}


