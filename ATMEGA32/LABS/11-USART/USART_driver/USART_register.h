/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	USART				**************************/
/***********************		DATE	:	OCT 29, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef USART_DRIVER_USART_REGISTER_H_
#define USART_DRIVER_USART_REGISTER_H_



#define UDR                     *((volatile u8*)0x2C)


#define UCSRA                   *((volatile u8*)0x2B)
#define UCSRA_RXC               7
#define UCSRA_UDRE              5


#define UCSRB                   *((volatile u8*)0x2A)
#define UCSRB_RXEN              4
#define UCSRB_TXEN              3
#define UCSRB_UCSZ2             2


#define UCSRC                   *((volatile u8*)0x40)
#define UBRRL                   *((volatile u8*)0x29)



#endif /* USART_DRIVER_USART_REGISTER_H_ */
