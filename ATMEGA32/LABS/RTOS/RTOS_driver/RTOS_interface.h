/*
 * RTOS_interface.h
 *
 *  Created on: Nov 26, 2023
 *      Author: EngMoS
 */

#ifndef RTOS_DRIVER_RTOS_INTERFACE_H_
#define RTOS_DRIVER_RTOS_INTERFACE_H_


void RTOS_voidInit(void);	// Initialize the timer
void RTOS_voidStart(void);	// Start the timer
void RTOS_voidStop(void);	// Stop the timer

void RTOS_voidCreateTask(u8 Copy_u8Periorty, u32 Copy_u16Periodicity, u8 Copy_u8FirstDelay, void (*Copy_pvTaskFunc)(void));
void RTOS_voidDeleteTask(u8 Copy_u8Periorty, u32 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void));	// Make the function = NULL


#endif /* RTOS_DRIVER_RTOS_INTERFACE_H_ */
