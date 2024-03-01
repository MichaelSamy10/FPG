/*
 * DCMOTOR_program.c
 *
 *  Created on: Feb 13, 2024
 *      Author: MICHAEL
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "../../MCAL/MRCC/MRCC_interface.h"
#include "../../MCAL/MTIM2_5/MTIM2_5_interface.h"

#include "DCMOTOR_interface.h"
#include "DCMOTOR_config.h"


void DCMOTOR_voidInit()
{
	/* Set Timer 3,4,5 Clock for PWM signal generation*/
//	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
//	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
//	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM5_EN);
	/* Timer3 PWM Channel 1-> PORTA 6 */
	MGPIO_voidSetPinMode(TIMER3_CH1_PORT,TIMER3_CH1_PIN,MGPIO_u8ALTFUNC);
	/* Timer3 Alternate Function */
	MGPIO_voidSetAltFunc(TIMER3_CH1_PORT,TIMER3_CH1_PIN,GPIO_u8AF2);

	/* Timer4 PWM Channel 1-> PORTB 6 */
	MGPIO_voidSetPinMode(TIMER4_CH1_PORT,TIMER4_CH1_PIN,MGPIO_u8ALTFUNC);
	/* Timer4 Alternate Function */
	MGPIO_voidSetAltFunc(TIMER4_CH1_PORT,TIMER4_CH1_PIN,GPIO_u8AF2);

	/* Init Control Pins (PA0 - PA1 - PA2 - PA3) for Controlling direction */
	MGPIO_voidSetPinMode(DCMOTOR1_CONTROL_PORT,DCMOTOR1_CONTROL_PIN0,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(DCMOTOR1_CONTROL_PORT,DCMOTOR1_CONTROL_PIN1,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(DCMOTOR2_CONTROL_PORT,DCMOTOR2_CONTROL_PIN0,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(DCMOTOR2_CONTROL_PORT,DCMOTOR2_CONTROL_PIN1,MGPIO_u8OUTPUT);

	/* Timer 3,4 PWM Init */
	TIM2_5_voidPWM_Init(MOTOR1_PWM_TIMER,MOTOR1_PWM_CHANNEL);
	TIM2_5_voidPWM_Init(MOTOR2_PWM_TIMER,MOTOR2_PWM_CHANNEL);

}

void DCMOTOR_voidSetDirection(u8 Copy_u8MotorNum,u8 Copy_u8Direction)
{
	u8 L_u8ControlPort,L_u8ControlPin0,L_u8ControlPin1;
	switch(Copy_u8MotorNum)
	{
		case DCMOTOR_1:
			L_u8ControlPort = DCMOTOR1_CONTROL_PORT;
			L_u8ControlPin0 = DCMOTOR1_CONTROL_PIN0;
			L_u8ControlPin1 = DCMOTOR1_CONTROL_PIN1;
			break;

		case DCMOTOR_2:
			L_u8ControlPort = DCMOTOR2_CONTROL_PORT;
			L_u8ControlPin0 = DCMOTOR2_CONTROL_PIN0;
			L_u8ControlPin1 = DCMOTOR2_CONTROL_PIN1;
			break;

	}

	switch(Copy_u8Direction)
	{
		case DCMOTOR_FORWARD_DIRECTION:
			MGPIO_voidSetPinValue(L_u8ControlPort,L_u8ControlPin0,MGPIO_u8HIGH);
			MGPIO_voidSetPinValue(L_u8ControlPort,L_u8ControlPin1,MGPIO_u8LOW);
		break;

		case DCMOTOR_BACKWARD_DIRECTION:
			MGPIO_voidSetPinValue(L_u8ControlPort,L_u8ControlPin0,MGPIO_u8LOW);
			MGPIO_voidSetPinValue(L_u8ControlPort,L_u8ControlPin1,MGPIO_u8HIGH);
		break;
	}


}

void DCMOTOR_voidSetSpeed(u8 Copy_u8MotorNum,u16 Copy_u16Frequency,u16 Copy_u16DutyCycle)
{
	switch(Copy_u8MotorNum)
	{
		case DCMOTOR_1:
			/* PWM init for Timer3 Channel 1*/
			TIM2_5_voidSetPWM(MOTOR1_PWM_TIMER,MOTOR1_PWM_CHANNEL,Copy_u16Frequency,Copy_u16DutyCycle);
			break;
		case DCMOTOR_2:
			TIM2_5_voidSetPWM(MOTOR2_PWM_TIMER,MOTOR2_PWM_CHANNEL,Copy_u16Frequency,Copy_u16DutyCycle);
			break;

	}

}

void DCMOTOR_voidStop(u8 Copy_u8MotorNum)
{

	switch(Copy_u8MotorNum)
	{
	case DCMOTOR_1:TIM2_5_voidTimerStop(MOTOR1_PWM_TIMER); break;
	case DCMOTOR_2:TIM2_5_voidTimerStop(MOTOR2_PWM_TIMER); break;

	}

}





