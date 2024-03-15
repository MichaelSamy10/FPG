/*
 * OBS_program.c
 *
 *  Created on: Mar 7, 2024
 *      Author: MICHAEL
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "../../MCAL/MEXTI/MEXTI_interface.h"
#include "../../MCAL/MNVIC/MNVIC_interface.h"
#include "OBS_interface.h"
#include "OBS_config.h"
 /**/
void OBS_voidInit(u8 Copy_u8Port,u8 Copy_u8PIN,u8 Copy_u8EXTI_Num,void(*Copy_pvCallBackFunc)(void))
{
		MGPIO_voidSetPinMode(Copy_u8Port,Copy_u8PIN,MGPIO_u8INPUT);
		MGPIO_voidSetPullType(Copy_u8Port,Copy_u8PIN,MGPIO_u8PullUP);
		//MEXTI_voidEnableEXTI(Copy_u8PIN);
		MEXTI_voidTriggerSource(Copy_u8PIN,MEXTI_FALLING_EDGE);
		MEXTI_voidSelectPort(Copy_u8PIN,Copy_u8Port);
		MEXTI_voidSetCallBack(Copy_u8PIN,Copy_pvCallBackFunc);
		//MNVIC_voidEnableInterrupt(Copy_u8EXTI_Num);
}
/**/
