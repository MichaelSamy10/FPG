/*
 * DCMOTOR_interface.h
 *
 *  Created on: Feb 13, 2024
 *      Author: MICHAEL
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_


#define DCMOTOR_FORWARD_DIRECTION		0
#define DCMOTOR_BACKWARD_DIRECTION		1


#define DCMOTOR_1						1
#define DCMOTOR_2   					2
#define DCMOTOR_3   					3
#define DCMOTOR_4   					4


void DCMOTOR_voidInit();

void DCMOTOR_voidSetDirection(u8 Copy_u8MotorNum,u8 Copy_u8Direction);

void DCMOTOR_voidSetSpeed(u8 Copy_u8MotorNum,u16 Copy_u16Frequency,u16 Copy_u16DutyCycle);

void DCMOTOR_voidStop(u8 Copy_u8MotorNum);

#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
