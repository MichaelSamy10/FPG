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
	 MNVIC_voidSetInterruptGroupMode( MNVIC_GROUPMODE_G8S2);
	 MNVIC_voidSetInterruptPeriority(TIMER4_POS,0,0,MNVIC_GROUPMODE_G8S2);
	 MNVIC_voidSetInterruptPeriority(EXTI4_POS,1,0,MNVIC_GROUPMODE_G8S2);

	OBS_voidInit(MGPIO_u8PORTA,4,EXTI4_POS,Obstacle_SenseForward);
	OBS_voidInit(MGPIO_u8PORTA,1,EXTI10_15_POS,Obstacle_SenseBack);
//	LDIR_voidInit(MGPIO_u8PORTA,8,EXTI9_5_POS,LD_IRsenseLeft);
//	LDIR_voidInit(MGPIO_u8PORTB,13,EXTI10_15_POS,LD_IRsenseRight);
	SERVO_voidInit();
	Ultrasonic_voidInit();
	BT_voidInit();

		/*************** PIN MODES *****************************/

<<<<<<< HEAD
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,1,MGPIO_u8OUTPUT);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,4,MGPIO_u8INPUT);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,5,MGPIO_u8INPUT);



//		MGPIO_voidSetPullType(MGPIO_u8PORTA,4,MGPIO_u8PullUP);
//		MGPIO_voidSetPullType(MGPIO_u8PORTA,5,MGPIO_u8PullUP);




=======
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,2,MGPIO_u8OUTPUT);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,4,MGPIO_u8INPUT);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,5,MGPIO_u8INPUT);
>>>>>>> branch 'Temp' of https://github.com/MichaelSamy10/FPG_FOTA_Parking_Guard



//		MGPIO_voidSetPullType(MGPIO_u8PORTA,4,MGPIO_u8PullUP);
//		MGPIO_voidSetPullType(MGPIO_u8PORTA,5,MGPIO_u8PullUP);



	DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
	DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
	DCMOTOR_voidSetSpeed(DCMOTOR_1,10000,2500);
	DCMOTOR_voidSetSpeed(DCMOTOR_2,10000,2500);

	u8 distance;
	while(1)
	{
<<<<<<< HEAD
//		Ultrasonic_voidRead();
=======
//		 Ultrasonic_voidRead();
//		distance = Ultrasonic_u8GetDistance();
//		if(distance > 10)
//		{
//			MGPIO_voidSetPinValue(MGPIO_u8PORTA,2,MGPIO_u8HIGH);
//		}
//		else
//		{
//			MGPIO_voidSetPinValue(MGPIO_u8PORTA,2,MGPIO_u8LOW);
//
//		}
>>>>>>> branch 'Temp' of https://github.com/MichaelSamy10/FPG_FOTA_Parking_Guard
//		MSTK_voidDelayMS(10);
		/*****************TEST MOTORS**********************/

//		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
//		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
//		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,4000);
//		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,4000);



		/******************** ULTRASONIC & SERVO**********************/

<<<<<<< HEAD
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,300);
//		Ultrasonic_voidRead();
=======
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,300);	//Right
//		//Ultrasonic_voidRead();
>>>>>>> branch 'Temp' of https://github.com/MichaelSamy10/FPG_FOTA_Parking_Guard
//		MSTK_voidDelayMS(2000);
//
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1000);
//		//Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);
//
//
//
<<<<<<< HEAD
//
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1000);
//		Ultrasonic_voidRead();
=======
//		TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,2000);	//Left
//		//Ultrasonic_voidRead();
>>>>>>> branch 'Temp' of https://github.com/MichaelSamy10/FPG_FOTA_Parking_Guard
//		MSTK_voidDelayMS(2000);

<<<<<<< HEAD
=======

	//	TIM2_5_voidSetPWM(MTIM_5,MTIM2_5_ch1,19999,1000);
		//Ultrasonic_voidRead();
	//	MSTK_voidDelayMS(2000);

>>>>>>> branch 'Temp' of https://github.com/MichaelSamy10/FPG_FOTA_Parking_Guard



	}

}
