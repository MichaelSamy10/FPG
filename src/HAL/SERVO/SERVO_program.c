/*
 * SERVO_program.c
 *
 *  Created on: Feb 21, 2024
 *      Author: MICHAEL
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/MRCC/MRCC_interface.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "../../MCAL/MTIM2_5/MTIM2_5_interface.h"

#include "SERVO_interface.h"
#include "SERVO_config.h"



void SERVO_voidInit()
{
//	/* Enable Timer 4 Clock for PWM generation */
//	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);

	/* Timer 5 PWM Channel 1-> PORTA 0 */
	MGPIO_voidSetPinMode(SERVO_PORT,SERVO_PIN,MGPIO_u8ALTFUNC);
	/* Timer 5 Alternate Function */
	MGPIO_voidSetAltFunc(SERVO_PORT,SERVO_PIN,GPIO_u8AF2);

	TIM2_5_voidPWM_Init(SERVO_PWM_TIMER,SERVO_PWM_TIMER_CH);

}

void SERVO_voidSetAngle(u16 Copy_u16Angle)
{
	// 0->1000  90->1500  180->2000
	u16 L_u16Angle = 1000 + (((u32)999*Copy_u16Angle)/180);
	/* set Angle of Servo */
	TIM2_5_voidSetPWM(SERVO_PWM_TIMER,SERVO_PWM_TIMER_CH,19999,L_u16Angle);
}

void SERVO_voidStop()
{
	TIM2_5_voidTimerStop(SERVO_PWM_TIMER);
}
