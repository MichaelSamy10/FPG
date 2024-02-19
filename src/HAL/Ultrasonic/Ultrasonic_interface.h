/*
 * Ultrasonic_interface.h
 *
 *  Created on: Feb 19, 2024
 *      Author: MICHAEL
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_


void Ultrasonic_voidInit(void);

void Ultrasonic_voidSetCallBackICU(void);

u8 Ultrasonic_u8GetDistance();

void Ultrasonic_voidRead(void);


#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
