#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "HAL/Ultrasonic/Ultrasonic_interface.h"


#define TX	9
#define RX	10


int main()
{
	MRCC_voidInitializeSystemClock();
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_USART1_EN);

	/* Enable Timer3 Interrupt */
	MNVIC_voidEnableInterrupt(29);

	MGPIO_voidSetPinMode(MGPIO_u8PORTA,TX,MGPIO_u8ALTFUNC);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,RX,MGPIO_u8ALTFUNC);

	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,TX,GPIO_u8AF7);
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,RX,GPIO_u8AF7);

	MUSART_voidInit();
	MUSART_voidEnable();

	MSTK_voidIntialize();

	/* Ultrasonic Init */
	Ultrasonic_voidInit();


	u8 var1=0,var2=0;
	u8 distance;
	//MUSART_voidSendString("Hi");
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,1,MGPIO_u8OUTPUT);

	while(1)
	{
		Ultrasonic_voidRead();

		distance = Ultrasonic_u8GetDistance();

		var1 = (distance / 10) + '0';
		var2 = (distance % 10) + '0';

		  MUSART_voidSendData(var1);
		  MUSART_voidSendData(var2);
		  if(distance > 5){
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,1);
		  }
		  else
		  {
				MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,0);

		  }

	}

}

