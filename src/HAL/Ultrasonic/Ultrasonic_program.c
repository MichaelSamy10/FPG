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
#include "../../MCAL/MUART/MUART_interface.h"
#include "../../MCAL/MTIM2_5/MTIM2_5_interface.h"

#include "Ultrasonic_private.h"
#include "Ultrasonic_config.h"
#include "Ultrasonic_interface.h"


u8 G_u8Distance  ;


void Ultrasonic_voidInit(void)
{
	/* Set Trigger pin mode */
	MGPIO_voidSetPinMode(TRIG_PORT, TRIG_PIN,MGPIO_u8OUTPUT);

	// Alternate Function for TIM3 CH1 -> PA6
	MGPIO_voidSetPinMode(ECHO_PORT,ECHO_PIN,MGPIO_u8ALTFUNC);
	MGPIO_voidSetAltFunc(ECHO_PORT,ECHO_PIN,GPIO_u8AF2);

	/* Timer3 Input Capture Init */
	TIM2_5_voidICU_init(MTIM_3,MTIM2_5_ch1);


}

 void Ultrasonic_voidSetCallBackICU(void)
{
	static u32 L_u32FirstCapt = 0;
	static u32 L_u32SecondCapt = 0;
	static u32 L_u32Difference = 0;
	static u8 Is_First_Captured = 0;  // is the first value captured ?

	MUSART_voidSendData(' ');
		if (Is_First_Captured==0) // if the first value is not captured
		{
			L_u32FirstCapt = TIM2_5_u32ReturnICUvalue(MTIM_3,MTIM2_5_ch1); // read the first value
			Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			TIM2_5_ChangICUpolaritiy(MTIM_3,MTIM2_5_ch1,MTIM_FallingEdge);
		}
		else if (Is_First_Captured==1)   // if the first is already captured
		{
			// read second value
			L_u32SecondCapt = TIM2_5_u32ReturnICUvalue(MTIM_3,MTIM2_5_ch1);

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
			TIM2_5_ChangICUpolaritiy(MTIM_3,MTIM2_5_ch1,MTIM_RisingEdge);
			TIM2_5_voidDisable_ICU_Interrupt(MTIM_3,MTIM2_5_ch1);
		}
}

u8 Ultrasonic_u8GetDistance()
{
	return G_u8Distance;
}

void Ultrasonic_voidRead(void)
{
	// pull the TRIG pin HIGH
	MGPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, MGPIO_u8HIGH);
	//MUSART_voidSendData('1');

	// wait for 10 us
	MSTK_voidDelayUS(10);
	//MSTK_voidSetBusyWait(160);

	// pull the TRIG pin low
	MGPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, MGPIO_u8LOW);

	TIM2_5_voidEnable_ICU_Interrupt(MTIM_3,MTIM2_5_ch1);

	// Channel 1 -> PA6
	MTIM3_setCALLBACK(&Ultrasonic_voidSetCallBackICU);

	MSTK_voidDelayMS(200);

}
