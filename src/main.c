#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MTIM2_5/MTIM2_5_interface.h"
#include "HAL/Ultrasonic/Ultrasonic_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "HAL/DCMOTOR/DCMOTOR_interface.h"

#define TX	9
#define RX	10

void Car_Control();

int main()
{
	MRCC_voidInitializeSystemClock();
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_USART1_EN);

	MSTK_voidIntialize();
//	MNVIC_voidEnableInterrupt(USART1_POS);

	DCMOTOR_voidInit();

	/**********SERVO******************/
	//SERVO_voidInit();
	//TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,500);
	//SERVO_voidSetAngle(0);
	/*********************************/

	/**********ULTRASONIC************/
	/* Ultrasonic Init */
	//Ultrasonic_voidInit();

	u8 var1=0,var2=0;
	u8 distance;



	/*********BLUETOOTH********************/

//	MGPIO_voidSetPinMode(MGPIO_u8PORTA,0,MGPIO_u8OUTPUT);
//	MGPIO_voidSetPinMode(MGPIO_u8PORTA,1,MGPIO_u8OUTPUT);
//	MGPIO_voidSetPinMode(MGPIO_u8PORTA,2,MGPIO_u8OUTPUT);
//	MGPIO_voidSetPinMode(MGPIO_u8PORTA,3,MGPIO_u8OUTPUT);
//	MGPIO_voidSetPinMode(MGPIO_u8PORTA,4,MGPIO_u8OUTPUT);
//
//	/* UART */
//	MGPIO_voidSetPinMode(MGPIO_u8PORTA,TX,MGPIO_u8ALTFUNC);
//	MGPIO_voidSetPinMode(MGPIO_u8PORTA,RX,MGPIO_u8ALTFUNC);
//
//	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,TX,GPIO_u8AF7);
//	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,RX,GPIO_u8AF7);
//
//	MUSART_voidInit();
//	MUSART_voidEnable();
//
//	MUSART_voidEnableInterrupt();
//
//	MUSART_voidSetCallBack(&Car_Control);

	while(1)
	{

//		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,1000);
//		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,1000);
//		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_BACKWARD_DIRECTION);
//		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);

//		MSTK_voidDelayMS(5000);
//		DCMOTOR_voidStop(DCMOTOR_1);
//		DCMOTOR_voidStop(DCMOTOR_2);
//		MSTK_voidDelayMS(5000);

		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,4000);
		//DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,1000);
		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		//DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		MSTK_voidDelayMS(5000);



//		MGPIO_voidSetPinValue(MGPIO_u8PORTA,4,MGPIO_u8HIGH);
//		MSTK_voidDelayMS(3000);
//		MGPIO_voidSetPinValue(MGPIO_u8PORTA,4,MGPIO_u8LOW);
//		MSTK_voidDelayMS(3000);

		/**********BLUETOOTH ****************/

//		if(data == '1')
//		{
//			//MUSART_voidSendString("ON");
//			MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,MGPIO_u8HIGH);
//		}
//		else
//		{
//			//MUSART_voidSendString("OFF");
//			MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,MGPIO_u8LOW);
//		}


		/********** SERVO *****************/

//		TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,500); //0
//		MSTK_voidDelayMS(2000);
//		TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,1800); // 90
//		MSTK_voidDelayMS(2000);
//		TIM2_5_voidSetPWM(MTIM_4,MTIM2_5_ch1,19999,2000);
//		MSTK_voidDelayMS(2000);




		/**************** ULTRASONIC **********/

//		Ultrasonic_voidRead();
//
//		distance = Ultrasonic_u8GetDistance();
//
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
	data = MUSART_voidRecieveAsynchronous();
			if(data == 'F')
			{
				//MUSART_voidSendString("ON");
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,0,MGPIO_u8HIGH);
			}
			else if(data == 'B')
			{
				//MUSART_voidSendString("OFF");
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,MGPIO_u8HIGH);
			}
			else if(data == 'L')
			{
				//MUSART_voidSendString("OFF");
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,2,MGPIO_u8HIGH);
			}
			else if(data == 'R')
			{
				//MUSART_voidSendString("OFF");
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,3,MGPIO_u8LOW);
			}

			else
			{
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,0,MGPIO_u8LOW);
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,MGPIO_u8LOW);
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,2,MGPIO_u8LOW);
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,3,MGPIO_u8LOW);
				//MUSART_voidSendString("Hi");
			}
}
