/*
 * Ultrasonic_program.c
 *
 *  Created on: Feb 19, 2024
 *      Author: MICHAEL
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "../../MCAL/MSTK/MSTK_interface.h"
#include "../../MCAL/MNVIC/MNVIC_interface.h"
#include "../../MCAL/MTIM1/MTIM1_interface.h"
#include "../../MCAL/MTIM2_5/MTIM2_5_interface.h"
#include "../../MCAL/MUART1/MUART1_interface.h"
#include "Ultrasonic_private.h"
#include "Ultrasonic_config.h"
#include "Ultrasonic_interface.h"


u8 G_u8Distance;


void Ultrasonic_voidInit(void)
{
	/* Set Trigger pin mode */
	MGPIO_voidSetPinMode(TRIG_PORT, TRIG_PIN,MGPIO_u8OUTPUT);

	// Alternate Function for TIM1 CH1 -> PA8
	MGPIO_voidSetPinMode(ECHO_PORT,ECHO_PIN,MGPIO_u8ALTFUNC);
	MGPIO_voidSetAltFunc(ECHO_PORT,ECHO_PIN,GPIO_u8AF2);

	/* Timer1 Input Capture Init */
	//MTIM1_voidICU_init(US_TIMER_CHANNEL);
	TIM2_5_voidICU_init(US_TIMER,US_TIMER_CHANNEL);
	/* Enable Timer1 Interrupt */
	//MNVIC_voidEnableInterrupt(TIMER1_POS);
	MNVIC_voidEnableInterrupt(TIMER4_POS);


}

 void Ultrasonic_voidSetCallBackICU(void)
{
	static u32 L_u32FirstCapt = 0;
	static u32 L_u32SecondCapt = 0;
	static u32 L_u32Difference = 0;
	static u8 Is_First_Captured = 0;  // is the first value captured ?

	//MUSART1_voidSendData(' ');
		if (Is_First_Captured==0) // if the first value is not captured
		{
			//L_u32FirstCapt = MTIM1_u32ReturnICU_value(US_TIMER_CHANNEL); // read the first value
			L_u32FirstCapt = TIM2_5_u32ReturnICUvalue(US_TIMER,US_TIMER_CHANNEL); // read the first value

			Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			//MTIM1_voidChangeICU_polarity(US_TIMER_CHANNEL,MTIM1_FallingEdge);
			TIM2_5_ChangICUpolaritiy(US_TIMER,US_TIMER_CHANNEL,MTIM_FallingEdge);
		}
		else if (Is_First_Captured==1)   // if the first is already captured
		{
			// read second value
			//L_u32SecondCapt = MTIM1_u32ReturnICU_value(US_TIMER_CHANNEL);
			L_u32SecondCapt = TIM2_5_u32ReturnICUvalue(US_TIMER,US_TIMER_CHANNEL);

			if (L_u32SecondCapt > L_u32FirstCapt)
			{
				L_u32Difference = L_u32SecondCapt-L_u32FirstCapt;
			}

			else if (L_u32FirstCapt > L_u32SecondCapt)
			{
				L_u32Difference = (0xFFFF - L_u32FirstCapt) + L_u32SecondCapt;
			}

			G_u8Distance = L_u32Difference * 0.034/2;
			Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			//MTIM1_voidChangeICU_polarity(US_TIMER_CHANNEL,MTIM1_RisingEdge);
			TIM2_5_ChangICUpolaritiy(US_TIMER,US_TIMER_CHANNEL,MTIM_RisingEdge);
			//MTIM1_voidDisableICU_interrupt(US_TIMER_CHANNEL);
			TIM2_5_voidDisable_ICU_Interrupt(US_TIMER,US_TIMER_CHANNEL);
		}
}

u8 Ultrasonic_u8GetDistance()
{
	return G_u8Distance;
}

void Ultrasonic_voidRead(void)
{
	u8 var1,var2;
	// pull the TRIG pin HIGH
	MGPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, MGPIO_u8HIGH);

	// wait for 10 us
	MSTK_voidDelayUS(10);

	// pull the TRIG pin low
	MGPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, MGPIO_u8LOW);

	//MTIM1_voidEnableICU_interrupt(US_TIMER_CHANNEL);
	TIM2_5_voidEnable_ICU_Interrupt(US_TIMER,US_TIMER_CHANNEL);

	// Set callBack for ICU Timer1
	//MTIM1_voidSetCallBacK_ICU(&Ultrasonic_voidSetCallBackICU);
	MTIM4_setCALLBACK(&Ultrasonic_voidSetCallBackICU);
	MSTK_voidDelayMS(10);


	if(G_u8Distance > 20)
	{
		MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,1);
	}
    else
    {
		MGPIO_voidSetPinValue(MGPIO_u8PORTA,1,0);
    }


//	var1 = (G_u8Distance / 10) + '0';
//	var2 = (G_u8Distance % 10) + '0';
//
//	  MUSART1_voidSendData(var1);
//	  MUSART1_voidSendData(var2);
}
