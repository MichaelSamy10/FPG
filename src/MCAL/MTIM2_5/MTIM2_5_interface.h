/*
 * MTIM2_5_interface.h
 *
 *  Created on: Jan 31, 2024
 *      Author: BROTHERS
 */

#ifndef MTIM2_5_MTIM2_5_INTERFACE_H_
#define MTIM2_5_MTIM2_5_INTERFACE_H_

/*********************************************/
/*********************************************/
/******************************	user defined MACROS		******************************/


/******************************	user defined DATA TYPES		******************************/
/***************	TIM2_5 select timer***************/
typedef enum{
 MTIM_2=2	,
 MTIM_3		,
 MTIM_4		,
 MTIM_5
}MTIMx_NUMBER_t;
/***************	TIM2_5 select PWM Channel NUMBER ****************/
typedef enum{
	MTIM2_5_ch1,
	MTIM2_5_ch2,
	MTIM2_5_ch3,
	MTIM2_5_ch4,
}MTIM2_5_PWM_channel_num;


/************************************************/
/*********************************************/

/***************	TIM2_5 FUNCTIONS prototypes	***************/
void TIM2_5_voidInitialize(MTIMx_NUMBER_t Copy_udtTimerNumber);

void TIM2_5_voidTimerStart(MTIMx_NUMBER_t Copy_udtTimerNumber);

void TIM2_5_voidTimerStop(MTIMx_NUMBER_t Copy_udtTimerNumber);

void TIM2_5_voidEnableInterrupt(MTIMx_NUMBER_t Copy_udtTimerNumber);
void TIM2_5_voidDisableInterrupt(MTIMx_NUMBER_t Copy_udtTimerNumber);

void TIM2_5_voidSetBusyWait(MTIMx_NUMBER_t Copy_udtTimerNumber,u32 Copy_u16TickNum);

void TIM2_5_voidPWM_Init(MTIMx_NUMBER_t Copy_udtTimerNumber,MTIM2_5_PWM_channel_num Copy_udtPWMchannel);

void MTIM2_5_SetPWM(MTIMx_NUMBER_t Copy_udtTimerNumber,MTIM2_5_PWM_channel_num Copy_udtPWMchannel,u16 Copy_u16PRESCALER,u16 Copy_u16Frequancy,u16 Copy_DutyCycle);

void MTIM2_5_voidICU_init(MTIMx_NUMBER_t Copy_udtTimerNumber,MTIM2_5_PWM_channel_num Copy_udtICUchannel);

void MTIM3_setCALLBACK(void (*Copy_pvCallBACK)(void));
void MTIM4_setCALLBACK(void (*Copy_pvCallBACK)(void));
void MTIM5_setCALLBACK(void (*Copy_pvCallBACK)(void));
#endif /* MTIM2_5_MTIM2_5_INTERFACE_H_ */
