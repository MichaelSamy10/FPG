/*
 * APP_Program.c
 *
 *  Created on: Mar 9, 2024
 *      Author: BROTHERS
 */
#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MTIM1/MTIM1_interface.h"
#include "MCAL/MTIM2_5/MTIM2_5_interface.h"
#include "MCAL/MUART1/MUART1_interface.h"
#include "MCAL/MUART6/MUART6_interface.h"
#include "HAL/Ultrasonic/Ultrasonic_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "HAL/DCMOTOR/DCMOTOR_interface.h"
#include "HAL/BT/BT_interface.h"
#include "HAL/OBS/OBS_interface.h"
#include "HAL/LDIR/LDIR_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "APP_interface.h"
#include "APP_config.h"

void Car_Control(void)
{
	u8 data;
	data = MUSART6_voidRecieveAsynchronous();
	switch(data)
	{
		case 'F'://Forward
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);

			break;
		case 'B'://Backward
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);
			break;
		case 'L'://Left
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,6000);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidStop(DCMOTOR_1);
			break;
		case 'R'://Right
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidStop(DCMOTOR_2);
			break;
		case 'G'://Forward Left
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,2000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);

			break;
		case 'I'://Forward Right
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,2000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);

			break;
		case 'H'://BackLeft
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,2000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);

			break;
		case 'J'://BackRight
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,2000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,6000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);
			break;
		case 'S'://Stop
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
		break;
		default:
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
			break;
	}
}


void LD_IRsenseRight(void){
	while(MGPIO_u8GetPinValue(MGPIO_u8PORTB,4)==0){
		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,1200);
		DCMOTOR_voidStop(DCMOTOR_2);
	}
}
void LD_IRsenseLeft(void){
	while(MGPIO_u8GetPinValue(MGPIO_u8PORTB,5)==0){
		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidStop(DCMOTOR_1);
		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,1200);
	}
}


void Obstacle_SenseBack(void)
{

}

void Obstacle_SenseForward(void)
{
	while(MGPIO_u8GetPinValue(MGPIO_u8PORTA,5)==0){
		DCMOTOR_voidStop(DCMOTOR_1);
		DCMOTOR_voidStop(DCMOTOR_2);
	}
}
