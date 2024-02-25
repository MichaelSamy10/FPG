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

#define TX	9
#define RX	10


int main()
{
	MRCC_voidInitializeSystemClock();
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_USART1_EN);

	MSTK_voidIntialize();


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

	//MUSART_voidSendString("Hi");
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,1,MGPIO_u8OUTPUT);

	/*********BLUETOOTH********************/
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,TX,MGPIO_u8ALTFUNC);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,RX,MGPIO_u8ALTFUNC);

	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,TX,GPIO_u8AF7);
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,RX,GPIO_u8AF7);

	MUSART_voidInit();
	MUSART_voidEnable();

	MUSART_voidSendString("HELLO WORLD\r\n");
	u8 data;

	while(1)
	{
		/**********BLUETOOTH ****************/
		 data = MUSART_voidReciveData();
		if(data == '1')
		{
			//MUSART_voidSendString("ON");
			MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,MGPIO_u8HIGH);
		}
		else
		{
			//MUSART_voidSendString("OFF");
			MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,MGPIO_u8LOW);
		}





//		SERVO_voidSetAngle(0);
//		MSTK_voidDelayMS(2000);
//		SERVO_voidSetAngle(180);
//		MSTK_voidDelayMS(2000);



		// ULTRASONIC

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

