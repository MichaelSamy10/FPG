#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MTIM2_5/MTIM2_5_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/DC_motor/DCMOTOR_interface.h"


void LD_IRsenseRight(void);
void LD_IRsenseLeft(void);
int main()
{
	/**Enable peripherals from RCC**/
	MRCC_voidInitializeSystemClock();
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);
	MRCC_voidEnablePeripheralClock(MRCC_APB2,MRCC_SYSCFG_EN);
	/** PIN sETup**/
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,1,MGPIO_u8INPUT);
	MGPIO_voidSetPullType(MGPIO_u8PORTB,1,MGPIO_u8PullUP);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,0,MGPIO_u8INPUT);
	MGPIO_voidSetPullType(MGPIO_u8PORTB,0,MGPIO_u8PullUP);
	/*** Initialize ***/
	TIM2_5_voidPWM_Init(MTIM_3,MTIM2_5_ch1);
	TIM2_5_voidPWM_Init(MTIM_4,MTIM2_5_ch1);
	DCMOTOR_voidInit();
	/*EXTI interrupt*/
	MEXTI_voidEnableEXTI(0);
	MEXTI_voidTriggerSource(0,MEXTI_RISING_EDGE);
	MEXTI_voidSelectPort(0,MEXTI_PORTA);
	MEXTI_voidSetCallBack(0,LD_IRsenseRight);
	MEXTI_voidEnableEXTI(1);
	MEXTI_voidTriggerSource(1,MEXTI_RISING_EDGE);
	MEXTI_voidSelectPort(1,MEXTI_PORTA);
	MEXTI_voidSetCallBack(1,LD_IRsenseLeft);
	/** DC motor **/
	DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
	DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
	DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,2000);
	DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,2000);
	/**Enable interrupt**/
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);


	while(1)
	{
		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,2000);
		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,2000);

	}

}



void LD_IRsenseRight(void){
	while(MGPIO_u8GetPinValue(MGPIO_u8PORTA,0)==1){
		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetSpeed(DCMOTOR_1,5000,1200);
		DCMOTOR_voidStop(DCMOTOR_2);
	}
}
void LD_IRsenseLeft(void){
	while(MGPIO_u8GetPinValue(MGPIO_u8PORTA,1)==1){
		DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_FORWARD_DIRECTION);
		DCMOTOR_voidStop(DCMOTOR_1);
		DCMOTOR_voidSetSpeed(DCMOTOR_2,5000,1200);
	}
}
