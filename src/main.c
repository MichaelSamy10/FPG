#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MTIM1/MTIM1_interface.h"
#include "MCAL/MTIM2_5/MTIM2_5_interface.h"
#include "HAL/Ultrasonic/Ultrasonic_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "HAL/DCMOTOR/DCMOTOR_interface.h"
#include "MCAL/MUART1/MUART1_interface.h"
#include "MCAL/MUART6/MUART6_interface.h"

#define TX	9
#define RX	10
#define MOTOR_FREQ				10000
#define MOTOR_DUTY_CYCLE		4000
#define MOTOR_DELAY				100

void Car_Control();

void LD_IRsenseRight(void);
void LD_IRsenseLeft(void);
void LD_Init(void);
void Obstacle_Init(void);
void Obstacle_SenseBack(void);
void Obstacle_SenseForward(void);

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
	//LD_Init();
	MSTK_voidIntialize();
//	MNVIC_voidEnableInterrupt(USART6_POS);

//	DCMOTOR_voidInit();
//	Obstacle_Init();
//	SERVO_voidInit();
	Ultrasonic_voidInit();


	//	u8 var1=0,var2=0;
	//	u8 distance;


	// PIN MODES
		MGPIO_voidSetPinMode(MGPIO_u8PORTA,1,MGPIO_u8OUTPUT);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,11,MGPIO_u8ALTFUNC);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,12,MGPIO_u8ALTFUNC);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,4,MGPIO_u8INPUT);
//		MGPIO_voidSetPinMode(MGPIO_u8PORTA,5,MGPIO_u8INPUT);
		MGPIO_voidSetPinMode(MGPIO_u8PORTA,9,MGPIO_u8ALTFUNC);
		MGPIO_voidSetPinMode(MGPIO_u8PORTA,10,MGPIO_u8ALTFUNC);


//		MGPIO_voidSetPullType(MGPIO_u8PORTA,4,MGPIO_u8PullUP);
//		MGPIO_voidSetPullType(MGPIO_u8PORTA,5,MGPIO_u8PullUP);



//		MGPIO_voidSetAltFunc(MGPIO_u8PORTA,11,GPIO_u8AF8);
//		MGPIO_voidSetAltFunc(MGPIO_u8PORTA,12,GPIO_u8AF8);

		MGPIO_voidSetAltFunc(MGPIO_u8PORTA,9,GPIO_u8AF7);
		MGPIO_voidSetAltFunc(MGPIO_u8PORTA,10,GPIO_u8AF7);

		MUSART1_voidInit();
		//MUSART6_voidInit();

		MUSART1_voidEnable();
		//MUSART6_voidEnable();

//		MUSART6_voidEnableInterrupt();
//
//		MUSART6_voidSetCallBack(&Car_Control);

	while(1)
	{
		Ultrasonic_voidRead();
		MSTK_voidDelayMS(2000);

//		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
//		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
//		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,2000);
//		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,2000);
//		MGPIO_voidSetPinValue(MGPIO_u8PORTA,0,1);
//		MSTK_voidDelayMS(3000);
//		MGPIO_voidSetPinValue(MGPIO_u8PORTA,0,0);
//		MSTK_voidDelayMS(3000);


		/******************** ULTRASONIC & SERVO**********************/

		//distance = Ultrasonic_u8GetDistance();
//		TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,250);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);
//
//		TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,1000);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);
//
//		TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,2000);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);
//
//		TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,1000);
//		Ultrasonic_voidRead();
//		MSTK_voidDelayMS(2000);


//		MGPIO_voidSetPinValue(MGPIO_u8PORTA,0,1);
//		MSTK_voidDelayMS(3000);
//		MGPIO_voidSetPinValue(MGPIO_u8PORTA,0,0);
//		MSTK_voidDelayMS(3000);

//		var1 = (distance / 10) + '0';
//		var2 = (distance % 10) + '0';
//
//		  MUSART_voidSendData(var1);
//		  MUSART_voidSendData(var2);
//		  if(distance > 20){
//				MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,1);
//		  }
//		  else
//		  {
//				MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,0);
//		  }

	}

}


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
			MSTK_voidDelayMS(MOTOR_DELAY);
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
			break;
		case 'L'://Left
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,6000);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			MSTK_voidDelayMS(MOTOR_DELAY);
			DCMOTOR_voidStop(DCMOTOR_2);
			DCMOTOR_voidStop(DCMOTOR_1);
			break;
		case 'R'://Right
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			MSTK_voidDelayMS(MOTOR_DELAY);
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
			break;
		case 'G'://Forward Left
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,3000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,1000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			MSTK_voidDelayMS(MOTOR_DELAY);
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
			break;
		case 'I'://Forward Right
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,6000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,3000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
			MSTK_voidDelayMS(MOTOR_DELAY);
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
			break;
		case 'H'://BackLeft
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,3000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,1000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);

			break;
		case 'J'://BackRight
			DCMOTOR_voidSetSpeed(DCMOTOR_1,MOTOR_FREQ,1000);
			DCMOTOR_voidSetSpeed(DCMOTOR_2,MOTOR_FREQ,3000);
			DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
			DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);
			MSTK_voidDelayMS(100);
			DCMOTOR_voidStop(DCMOTOR_1);
			DCMOTOR_voidStop(DCMOTOR_2);
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

void LD_Init(void)
{
		/** PIN sETup**/
		MGPIO_voidSetPinMode(MGPIO_u8PORTB,4,MGPIO_u8INPUT);
		MGPIO_voidSetPinMode(MGPIO_u8PORTB,5,MGPIO_u8INPUT);
		MGPIO_voidSetPullType(MGPIO_u8PORTB,4,MGPIO_u8PullUP);
		MGPIO_voidSetPullType(MGPIO_u8PORTB,5,MGPIO_u8PullUP);
		/*EXTI interrupt*/
		MEXTI_voidEnableEXTI(MEXTI_LINE4);
		MEXTI_voidTriggerSource(MEXTI_LINE4,MEXTI_FALLING_EDGE);
		MEXTI_voidSelectPort(MEXTI_LINE4,MEXTI_PORTB);
		MEXTI_voidSetCallBack(MEXTI_LINE4,LD_IRsenseRight);

		MEXTI_voidEnableEXTI(MEXTI_LINE5);
		MEXTI_voidTriggerSource(MEXTI_LINE5,MEXTI_FALLING_EDGE);
		MEXTI_voidSelectPort(MEXTI_LINE5,MEXTI_PORTA);
		MEXTI_voidSetCallBack(MEXTI_LINE5,LD_IRsenseLeft);
		MEXTI_voidEnableEXTI(MEXTI_LINE5);

		/** DC motor **/
		//	DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		//	DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		//	DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,2000);
		//	DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,2000);

		//	/**Enable interrupt**/
		MNVIC_voidEnableInterrupt(EXTI4_POS);
		MNVIC_voidEnableInterrupt(EXTI9_5_POS);

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

void Obstacle_Init(void)
{
	/** PIN sETup**/
			MGPIO_voidSetPinMode(MGPIO_u8PORTA,4,MGPIO_u8INPUT);
			MGPIO_voidSetPinMode(MGPIO_u8PORTA,5,MGPIO_u8INPUT);

			MGPIO_voidSetPullType(MGPIO_u8PORTA,4,MGPIO_u8PullUP);
			MGPIO_voidSetPullType(MGPIO_u8PORTA,5,MGPIO_u8PullUP);

			MEXTI_voidTriggerSource(MEXTI_LINE4,MEXTI_FALLING_EDGE);
			MEXTI_voidSelectPort(MEXTI_LINE4,MEXTI_PORTA);
			MEXTI_voidSetCallBack(MEXTI_LINE4,Obstacle_SenseBack);
			MEXTI_voidEnableEXTI(MEXTI_LINE4);

			MEXTI_voidTriggerSource(MEXTI_LINE5,MEXTI_FALLING_EDGE);
			MEXTI_voidSelectPort(MEXTI_LINE5,MEXTI_PORTA);
			MEXTI_voidSetCallBack(MEXTI_LINE5,Obstacle_SenseForward);
			MEXTI_voidEnableEXTI(MEXTI_LINE5);

			MNVIC_voidEnableInterrupt(EXTI4_POS);
			MNVIC_voidEnableInterrupt(EXTI9_5_POS);

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
