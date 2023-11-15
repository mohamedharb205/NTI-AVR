/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	TIMER0				**************************/
/***********************		DATE	:	OCT 27, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef MCAL_TIMER0_TIMER0_REGISTER_H_
#define MCAL_TIMER0_TIMER0_REGISTER_H_


/* TIMER0 REGISTERS */
#define 		TCNT0				(*(volatile u8*)0x52)
#define 		TCCR0				(*(volatile u8*)0x53)
#define 		TIMSK				(*(volatile u8*)0x59)
#define 		OCR0				(*(volatile u8*)0x5C)



/* TCCR0 BITS */
#define 		TCCR0_CS00			0
#define 		TCCR0_CS01			1
#define 		TCCR0_CS02			2
#define 		TCCR0_WGM01			3
#define 		TCCR0_COM00			4
#define 		TCCR0_COM01			5
#define 		TCCR0_WGM00			6
//#define 		TCCR0_FOC0			7


/* TIMSK BITS */
#define 		TIMSK_TOIE0			0	//TCNT Interrupt
#define 		TIMSK_OCIE0			1	//OCR Interrupt


#endif /* MCAL_TIMER0_TIMER0_REGISTER_H_ */
