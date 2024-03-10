#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

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
#include "APP/APP_interface.h"

enum{
	SEARCHING,
	PARKING,
	PARKED
}SELFPARKING_t;

SELFPARKING_t PARKING_STATE = SEARCHING;

int main()
{
	MRCC_voidInitializeSystemClock();
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_TIM1_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM5_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_USART1_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_USART6_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_SYSCFG_EN);

	/***************Initialization**********************************/
	MSTK_voidIntialize();
	DCMOTOR_voidInit();
	OBS_voidInit(MGPIO_u8PORTA,4,EXTI4_POS,Obstacle_SenseForward);
	//OBS_voidInit(MGPIO_u8PORTA,13,EXTI10_15_POS,Obstacle_SenseBack);
	LDIR_voidInit(MGPIO_u8PORTA,8,EXTI9_5_POS,LD_IRsenseLeft);
	LDIR_voidInit(MGPIO_u8PORTB,13,EXTI10_15_POS,LD_IRsenseRight);
	SERVO_voidInit();
	Ultrasonic_voidInit();
	BT_voidInit();
 /**/
		/************ UART1 for BOOTLOADER***************/
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,9,MGPIO_u8ALTFUNC);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,10,MGPIO_u8ALTFUNC);
//		MGPIO_voidSetAltFunc(MGPIO_u8PORTA,9,GPIO_u8AF7);
//		MGPIO_voidSetAltFunc(MGPIO_u8PORTA,10,GPIO_u8AF7);
//		MUSART1_voidInit();
//		MUSART1_voidEnable();

		/*********** Bluetooth Car Control ****************/
		MUSART6_voidSetCallBack(&Car_Control);

		//TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,2500);

	while(1)
	{
		/*****************TEST MOTORS**********************/

//		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
//		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
//		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,4000);
//		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,4000);



		/******************** ULTRASONIC & SERVO**********************/

//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,250);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);
//
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1000);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);
//
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,2000);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);
//
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1000);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);



	}

}




