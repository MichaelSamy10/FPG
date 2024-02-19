#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MTIM2_5/MTIM2_5_interface.h"

#define TRIG_PORT MGPIO_u8PORTA
#define TRIG_PIN  2
#define TX	9
#define RX	10

void CaptureCallBack(void);
void HCSR04_Read();

u32 IC_Val1 = 0;
u32 IC_Val2 = 0;
u32 Difference = 0;
u8 Is_First_Captured = 0;  // is the first value captured ?
u8 Distance  = 0;
u8 var1 =0;
u8 var2 =0;

int main()
{
	MRCC_voidInitializeSystemClock();
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_USART1_EN);

	MNVIC_voidEnableInterrupt(29);

	MSTK_voidIntialize();

	TIM2_5_voidICU_init(MTIM_3,MTIM2_5_ch1);
	MGPIO_voidSetPinMode(TRIG_PORT, TRIG_PIN,MGPIO_u8OUTPUT);

	MGPIO_voidSetPinMode(MGPIO_u8PORTA,TX,MGPIO_u8ALTFUNC);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,RX,MGPIO_u8ALTFUNC);

	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,TX,GPIO_u8AF7);
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,RX,GPIO_u8AF7);

	// ICU TIM3 CH1 -> PA6
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,6,MGPIO_u8ALTFUNC);
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA,6,GPIO_u8AF2);

	MUSART_voidInit();
	MUSART_voidEnable();

	MUSART_voidSendString("Hello");

	while(1)
	{
		HCSR04_Read();

		var1 = (Distance / 10) + '0';
		var2 = (Distance % 10) + '0';

		  MUSART_voidSendData(var1);
		  MUSART_voidSendData(var2);

		  //MSTK_voidSetBusyWait(10000);
	}

}


//void delay (u16 time)
//{
//	//TIM2_5_voidSetBusyWait(MTIM_3,0);
//
//	//__HAL_TIM_SET_COUNTER(&htim1, 0);
//	setCounter(0);
//
//	while (getCounter() < time);
//}

void CaptureCallBack(void)
{
	MUSART_voidSendData('1');

			if (Is_First_Captured==0) // if the first value is not captured
			{
				IC_Val1 = TIM2_5_u32ReturnICUvalue(MTIM_3,MTIM2_5_ch1); // read the first value
				Is_First_Captured = 1;  // set the first captured as true
				// Now change the polarity to falling edge
				TIM2_5_ChangICUpolaritiy(MTIM_3,MTIM2_5_ch1,MTIM_FallingEdge);
				//__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
			}

			else if (Is_First_Captured==1)   // if the first is already captured
			{
				MUSART_voidSendData('2');

				IC_Val2 = TIM2_5_u32ReturnICUvalue(MTIM_3,MTIM2_5_ch1);  // read second value
				//__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

				if (IC_Val2 > IC_Val1)
				{
					Difference = IC_Val2-IC_Val1;
				}

				else if (IC_Val1 > IC_Val2)
				{
					Difference = (0xffff - IC_Val1) + IC_Val2;
				}

				Distance = Difference * .034/2;
				Is_First_Captured = 0; // set it back to false

				// set polarity to rising edge
				TIM2_5_ChangICUpolaritiy(MTIM_3,MTIM2_5_ch1,MTIM_RisingEdge);
				TIM2_5_voidDisable_ICU_Interrupt(MTIM_3,MTIM2_5_ch1);
				//__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
			}

}

void HCSR04_Read (void)
{
	MGPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, MGPIO_u8HIGH);  // pull the TRIG pin HIGH

	//delay(10);  // wait for 10 us
	MSTK_voidSetBusyWait(160);

	MGPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, MGPIO_u8LOW);  // pull the TRIG pin low

	// Channel 1 -> PA6
	TIM2_5_voidEnable_ICU_Interrupt(MTIM_3,MTIM2_5_ch1);

	MTIM3_setCALLBACK(&CaptureCallBack);

	MSTK_voidSetBusyWait(1000000);
}
