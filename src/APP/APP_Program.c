/*
 * APP_Program.c
 *
 *  Created on: Mar 9, 2024
 *      Author: BROTHERS
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/MRCC/MRCC_interface.h"
#include "../MCAL/MGPIO/MGPIO_interface.h"
#include "../MCAL/MEXTI/MEXTI_interface.h"
#include "../MCAL/MSTK/MSTK_interface.h"
#include "../MCAL/MNVIC/MNVIC_interface.h"
#include "../MCAL/MTIM1/MTIM1_interface.h"
#include "../MCAL/MTIM2_5/MTIM2_5_interface.h"
#include "../MCAL/MUART1/MUART1_interface.h"
#include "../MCAL/MUART6/MUART6_interface.h"
#include "../HAL/Ultrasonic/Ultrasonic_interface.h"
#include "../HAL/SERVO/SERVO_interface.h"
#include "../HAL/DCMOTOR/DCMOTOR_interface.h"
#include "../HAL/BT/BT_interface.h"
#include "../HAL/OBS/OBS_interface.h"
#include "../HAL/LDIR/LDIR_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "APP_interface.h"
#include "APP_config.h"

typedef enum{
	SEARCHING,
	PARKING,
	PARKED
}SELFPARKING_t;

SELFPARKING_t PARKING_STATE = SEARCHING;


void Car_Control(void)
{
	u8 data;
	data = MUSART6_voidRecieveAsynchronous();
	switch(data)
	{
		case 'F'://Forward
			Move_Car_To(FORWARD);
			break;
		case 'B'://Backward
			Move_Car_To(BACKWARD);
			break;
		case 'L'://Left
			Move_Car_To(LEFT);
			break;
		case 'R'://Right
			Move_Car_To(RIGHT);
			break;
		case 'G'://Forward Left
			Move_Car_To(FORWARD_LEFT);
			break;
		case 'I'://Forward Right
			Move_Car_To(FORWARD_RIGHT);
			break;
		case 'H'://BackLeft
			Move_Car_To(BACKWARD_LEFT);
			break;
		case 'J'://BackRight
			Move_Car_To(BACKWARD_RIGHT);
			break;
		case 'P':
			AutoParking();
			break;
		case 'S'://Stop
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
		break;
		case 'O': // Obstacle ON
			MNVIC_voidEnableInterrupt(EXTI4_POS);
			MEXTI_voidEnableEXTI(4);
				DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
				DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
				DCMOTOR_voidSetSpeed(DCMOTOR_1,10000,2500);
				DCMOTOR_voidSetSpeed(DCMOTOR_2,10000,2500);
			break;
		case 'Z': // Obstacle OFF
			MNVIC_voidDisableInterrupt(EXTI4_POS);
			MEXTI_voidDisableEXTI(4);
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
	DCMOTOR_voidStop(DCMOTOR_1);
	DCMOTOR_voidStop(DCMOTOR_2);
	while(MGPIO_u8GetPinValue(MGPIO_u8PORTB,13)==0){
		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,1200);
		DCMOTOR_voidStop(DCMOTOR_2);
	}
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
}
/**/
void LD_IRsenseLeft(void){
	DCMOTOR_voidStop(DCMOTOR_1);
	DCMOTOR_voidStop(DCMOTOR_2);
	while(MGPIO_u8GetPinValue(MGPIO_u8PORTA,8)==0){
		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,1200);
		DCMOTOR_voidStop(DCMOTOR_1);
	}
	DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
	DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
	DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
	DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
}


void Obstacle_SenseBack(void)
{
	MNVIC_voidEnableInterrupt(EXTI10_15_POS);
	MEXTI_voidEnableEXTI(1);
}

void Obstacle_SenseForward(void)
{
	u8 distance;
	DCMOTOR_voidStop(DCMOTOR_1);
	DCMOTOR_voidStop(DCMOTOR_2);
	//Move Servo to right
	TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,300);
	MSTK_voidDelayMS(2000);
	Ultrasonic_voidRead();
	distance = Ultrasonic_u8GetDistance();
	if(distance > 10)
	{
		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1200);
		Move_Car_To(RIGHT);
		MSTK_voidDelayMS(1000);
		Move_Car_To(FORWARD);
	}
	else
	{
		//Move Servo to left
		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,2000);
		MSTK_voidDelayMS(2000);
		Ultrasonic_voidRead();
		distance = Ultrasonic_u8GetDistance();
		if(distance > 10)
		{
			TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1200);
			Move_Car_To(LEFT);
			MSTK_voidDelayMS(1000);
			Move_Car_To(FORWARD);
		}
		else
		{
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
		}
		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1200);

	}

}

void AutoParking(void){
	MEXTI_voidDisableEXTI(4);
	MNVIC_voidDisableInterrupt(EXTI10_15_POS);
	MEXTI_voidDisableEXTI(1);
	while(PARKING_STATE!= PARKED)
	{
		switch (PARKING_STATE){
			case SEARCHING: /*ultrasonic search for slot*/
				PARKING_STATE= PARKING;
				break;
			case PARKING: /*logic for manuvaring*/
				DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,3250);
				DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,5000);
				DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
				DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
				MSTK_voidDelayMS(600);
				DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,3200);
				DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,3200);
				DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
				DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);

				while(MGPIO_u8GetPinValue(MGPIO_u8PORTA,OBS_BACKWARD_PIN)!=0);
				DCMOTOR_voidStop(DCMOTOR_1);
				DCMOTOR_voidStop(DCMOTOR_2);
				MSTK_voidDelayMS(2000);

				DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,2000);
				DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,4000);
				DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);
				DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
				MSTK_voidDelayMS(600);
				DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,2000);
				DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,2000);
				DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
				DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
				while(MGPIO_u8GetPinValue(MGPIO_u8PORTA,OBS_FORWARD_PIN)!=0);
				DCMOTOR_voidStop(DCMOTOR_1);
				DCMOTOR_voidStop(DCMOTOR_2);

				PARKING_STATE= PARKED;
				break;
		}
	}
	DCMOTOR_voidStop(DCMOTOR_1);
	DCMOTOR_voidStop(DCMOTOR_2);
	PARKING_STATE=SEARCHING;

	//MGPIO_voidSetPinValue(MGPIO_u8PORTA,OBS_FORWARD_PIN,1);
	MNVIC_voidEnableInterrupt(EXTI10_15_POS);
	MEXTI_voidEnableEXTI(1);

}



void Move_Car_To(u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{
		case FORWARD://Forward
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			break;
		case BACKWARD://Backward
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,MOTOR_DUTY_CYCLE);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);
			break;
		case LEFT://Left
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,5000);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidStop(DCMOTOR_1);
			break;
		case RIGHT://Right
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,5000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidStop(DCMOTOR_2);
			break;
		case FORWARD_LEFT://Forward Left
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,2000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			break;
		case FORWARD_RIGHT://Forward Right
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,2000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,6000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			break;
		case BACKWARD_LEFT://BackLeft
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,2000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);
			break;
		case BACKWARD_RIGHT://BackRight
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,2000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,6000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);
			break;
	}
}