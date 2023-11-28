/*
 * RTOS_private.h
 *
 *  Created on: Nov 26, 2023
 *      Author: EngMoS
 */

#ifndef RTOS_DRIVER_RTOS_PRIVATE_H_
#define RTOS_DRIVER_RTOS_PRIVATE_H_


typedef struct
{
	u32 	Periodicity;
	u8 		Periorty;
	u8		State;
	u8 		FirstDelay;
	void 	(*TaskFun)(void);
}Task_t;


static void Schedular(void);


#endif /* RTOS_DRIVER_RTOS_PRIVATE_H_ */
