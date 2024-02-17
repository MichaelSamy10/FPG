/*
 * MTIM2_5_program.c
 *
 *  Created on: Jan 31, 2024
 *      Author: BROTHERS
 */

/*********************************************/
/*********************************************/

/***************	TIM2_5 Files include	***************/
/*Standard LIBS*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*RCC files*/
#include "MTIM2_5_interface.h"
#include "MTIM2_5_private.h"
#include "MTIM2_5_config.h"
#include "MTIM2_5_register.h"



static void(*MTIM3_pvCallBack)(void)=NULL;
static void(*MTIM4_pvCallBack)(void)=NULL;
static void(*MTIM5_pvCallBack)(void)=NULL;
/*********************************************/
/*********************************************/
u32 Global_ReturnValue=0;
/***************	TIM2_5 Functions Implementations	***************/


void TIM2_5_voidInitialize(MTIMx_NUMBER_t Copy_udtTimerNumber){
	switch (Copy_udtTimerNumber){
				case MTIM_2:
								/*no clock devision*/
							  CLR_BIT(MTIM2->CR1,CR1_CKD9);
							  CLR_BIT(MTIM2->CR1,CR1_CKD8);

							  /*enable AUTO RELOAD PRELOAD*/
							  SET_BIT(MTIM2->CR1,CR1_ARPE);
							  /*Set PreScaler*/
							  	 MTIM2->PSC=0x10;
							  /*set timer as edge aligned*/
							  	CLR_BIT(MTIM2->CR1,CR1_CMS6);
							  	CLR_BIT(MTIM2->CR1,CR1_CMS5);
							  /*Counter direction*/
							#if MTIM2_CMODE == MTIM_CDOWN
							  SET_BIT(MTIM2->CR1,CR1_DIR);
							#elif MTIM2_CMODE == MTIM_CUP
							  CLR_BIT(MTIM2->CR1,CR1_DIR);
							  #endif


							break;

				case MTIM_3 :
					/*no clock devision*/
								  CLR_BIT(MTIM3->CR1,CR1_CKD9);
								  CLR_BIT(MTIM3->CR1,CR1_CKD8);

								  /*enable AUTO RELOAD PRELOAD*/
								  SET_BIT(MTIM3->CR1,CR1_ARPE);
								  /*Set PreScaler*/
								  	 MTIM3->PSC=0x10;
								  /*set timer as edge aligned*/
								  	CLR_BIT(MTIM3->CR1,CR1_CMS6);
								  	CLR_BIT(MTIM3->CR1,CR1_CMS5);
								  /*Counter direction*/
								#if MTIM3_CMODE == MTIM_CDOWN
								  SET_BIT(MTIM3->CR1,CR1_DIR);
								#elif MTIM3_CMODE == MTIM_CUP
								  CLR_BIT(MTIM3->CR1,CR1_DIR);
								  #endif
								  	 break;
				case MTIM_4:
					/*no clock devision*/
								  CLR_BIT(MTIM4->CR1,CR1_CKD9);
								  CLR_BIT(MTIM4->CR1,CR1_CKD8);

								  /*enable AUTO RELOAD PRELOAD*/
								  SET_BIT(MTIM4->CR1,CR1_ARPE);
								  /*Set PreScaler*/
								  	 MTIM4->PSC=0x10;
								  /*set timer as edge aligned*/
								  	CLR_BIT(MTIM4->CR1,CR1_CMS6);
								  	CLR_BIT(MTIM4->CR1,CR1_CMS5);
								  /*Counter direction*/
								#if MTIM2_CMODE == MTIM_CDOWN
								  SET_BIT(MTIM4->CR1,CR1_DIR);
								#elif MTIM4_CMODE == MTIM_CUP
								  CLR_BIT(MTIM4->CR1,CR1_DIR);
								  #endif
								  break;
				case MTIM_5:
					/*no clock devision*/
				  CLR_BIT(MTIM5->CR1,CR1_CKD9);
				  CLR_BIT(MTIM5->CR1,CR1_CKD8);

				  /*enable AUTO RELOAD PRELOAD*/
				  SET_BIT(MTIM5->CR1,CR1_ARPE);
				  /*Set PreScaler*/
				  	 MTIM5->PSC=0x10;
				  /*set timer as edge aligned*/
				  	CLR_BIT(MTIM5->CR1,CR1_CMS6);
				  	CLR_BIT(MTIM5->CR1,CR1_CMS5);
				  /*Counter direction*/
				#if MTIM5_CMODE == MTIM_CDOWN
				  SET_BIT(MTIM5->CR1,CR1_DIR);
				#elif MTIM5_CMODE == MTIM_CUP
				  CLR_BIT(MTIM5->CR1,CR1_DIR);
				  #endif
					break;
					}
}

void TIM2_5_voidTimerStart(MTIMx_NUMBER_t Copy_udtTimerNumber){
	switch (Copy_udtTimerNumber){
			case MTIM_2:
							SET_BIT(MTIM2->CR1,CR1_CEN);
							break;

			case MTIM_3 :
							SET_BIT(MTIM3->CR1,CR1_CEN);
							break;

			case MTIM_4:
							SET_BIT(MTIM4->CR1,CR1_CEN);
							break;

			case MTIM_5:
							SET_BIT(MTIM5->CR1,CR1_CEN);
							break;
				}

}

void TIM2_5_voidTimerStop(MTIMx_NUMBER_t Copy_udtTimerNumber){
	switch (Copy_udtTimerNumber){
			case MTIM_2: CLR_BIT(MTIM2->CR1,CR1_CEN);
						break;

			case MTIM_3 : CLR_BIT(MTIM3->CR1,CR1_CEN);
						break;

			case MTIM_4 : CLR_BIT(MTIM4->CR1,CR1_CEN);
						break;

			case MTIM_5 : CLR_BIT(MTIM5->CR1,CR1_CEN);
						break;
				}
}




void TIM2_5_voidEnableInterrupt(MTIMx_NUMBER_t Copy_udtTimerNumber){
	switch (Copy_udtTimerNumber){
			case MTIM_2: SET_BIT(MTIM2->CR1,DIER_TIE);
						break;

			case MTIM_3 : SET_BIT(MTIM3->CR1,DIER_TIE);
						break;
			case MTIM_4 : SET_BIT(MTIM4->CR1,DIER_TIE);
						break;

			case MTIM_5 : SET_BIT(MTIM5->CR1,DIER_TIE);
						break;
				}
}
void TIM2_5_voidDisableInterrupt(MTIMx_NUMBER_t Copy_udtTimerNumber){
	switch (Copy_udtTimerNumber){
			case MTIM_2: CLR_BIT(MTIM2->CR1,DIER_TIE);
						break;

			case MTIM_3 : CLR_BIT(MTIM3->CR1,DIER_TIE);
						break;

			case MTIM_4 : CLR_BIT(MTIM4->CR1,DIER_TIE);
						break;

			case MTIM_5 : CLR_BIT(MTIM5->CR1,DIER_TIE);
						break;
				}
}

void TIM2_5_voidSetBusyWait(MTIMx_NUMBER_t Copy_udtTimerNumber,u32 Copy_u32TickNum){
	switch (Copy_udtTimerNumber){
	case MTIM_2:
					/*clear timer value */
					MTIM2->CNT=0x00000000;
					/*set PreLoad value */
					MTIM2->ARR=Copy_u32TickNum;
					/*start timer*/
					SET_BIT(MTIM2->CR1,CR1_CEN);
					/*wait for timer*/
					while(GET_BIT(MTIM2->SR,SR_UIF)!=1);
					/*stop timer*/
					CLR_BIT(MTIM2->CR1,CR1_CEN);
					break;
	case MTIM_3: /*clear timer value */
		/*clear timer value */
			MTIM3->CNT=0x00000000;
			/*set PreLoad value */
			MTIM3->ARR=Copy_u32TickNum;
			/*start timer*/
			SET_BIT(MTIM3->CR1,CR1_CEN);
			/*wait for timer*/
			while(GET_BIT(MTIM3->SR,SR_UIF)!=1);
			/*stop timer*/
			CLR_BIT(MTIM3->CR1,CR1_CEN);
			break;
	case MTIM_4: /*clear timer value */
		/*clear timer value */
			MTIM4->CNT=0x00000000;
			/*set PreLoad value */
			MTIM4->ARR=Copy_u32TickNum;
			/*start timer*/
			SET_BIT(MTIM4->CR1,CR1_CEN);
			/*wait for timer*/
			while(GET_BIT(MTIM4->SR,SR_UIF)!=1);
			/*stop timer*/
			CLR_BIT(MTIM4->CR1,CR1_CEN);
			break;
	case MTIM_5: /*clear timer value */
		/*clear timer value */
		MTIM5->CNT=0x00000000;
		/*set PreLoad value */
		MTIM5->ARR=Copy_u32TickNum;
		/*start timer*/
		SET_BIT(MTIM5->CR1,CR1_CEN);
		/*wait for timer*/
		while(GET_BIT(MTIM5->SR,SR_UIF)!=1);
		/*stop timer*/
		CLR_BIT(MTIM5->CR1,CR1_CEN);
		break;
	}
	}

void TIM2_5_voidPWM_Init(MTIMx_NUMBER_t Copy_udtTimerNumber,MTIM2_5_PWM_channel_num Copy_udtPWMchannel){
		switch (Copy_udtTimerNumber){
		case MTIM_3:
			switch(Copy_udtPWMchannel){
			case MTIM2_5_ch1:
				/*set the preScaler value in the preScaler register*/
				MTIM3->PSC=TIM3_PRESCALER;
				/*select the pwm mode*/
				SET_BIT(MTIM3->CCMR1,CCRM1_OC1M_6);
				SET_BIT(MTIM3->CCMR1,CCRM1_OC1M_5);
				CLR_BIT(MTIM3->CCMR1,CCRM1_OC1M_4);
				/*enable output compre auto reload register*/
				SET_BIT(MTIM3->CCMR1,CCRM1_OC1PE);
				/*enable out put on the corresponding PIN*/
				SET_BIT(MTIM3->CCER,CCER_CC1E);
				 break;
			case MTIM2_5_ch2:
				/*set the preScaler value in the preScaler register*/
				MTIM3->PSC=TIM3_PRESCALER;
				/*select the pwm mode*/
				SET_BIT(MTIM3->CCMR1,CCRM1_OC2M_14);
				SET_BIT(MTIM3->CCMR1,CCRM1_OC2M_13);
				CLR_BIT(MTIM3->CCMR1,CCRM1_OC2M_12);
				/*enable output compre auto reload register*/
				SET_BIT(MTIM3->CCMR1,CCRM1_OC2PE);
				/*enable out put on the corresponding PIN*/
				SET_BIT(MTIM3->CCER,CCER_CC2E);
		    	  break;
			case MTIM2_5_ch3:
				/*set the preScaler value in the preScaler register*/
				MTIM3->PSC=TIM3_PRESCALER;
				/*select the pwm mode*/
				SET_BIT(MTIM3->CCMR2,CCRM2_OC3M_6);
				SET_BIT(MTIM3->CCMR2,CCRM2_OC3M_5);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC3M_4);
				/*enable output compre auto reload register*/
				SET_BIT(MTIM3->CCMR2,CCRM2_OC3PE);
				/*enable out put on the corresponding PIN*/
				SET_BIT(MTIM3->CCER,CCER_CC3E);
				break;
			case MTIM2_5_ch4:
				/*set the preScaler value in the preScaler register*/
				MTIM3->PSC=TIM3_PRESCALER;
				/*select the pwm mode*/
				SET_BIT(MTIM3->CCMR2,CCRM2_OC4M_14);
				SET_BIT(MTIM3->CCMR2,CCRM2_OC4M_13);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC4M_12);
				/*enable output compre auto reload register*/
				SET_BIT(MTIM3->CCMR2,CCRM2_OC4PE);
				/*enable out put on the corresponding PIN*/
				SET_BIT(MTIM3->CCER,CCER_CC4E);
				 break;
			}
			break;
		case MTIM_4:
			switch(Copy_udtPWMchannel){
				case MTIM2_5_ch1:
					/*set the preScaler value in the preScaler register*/
					MTIM4->PSC=TIM4_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM4->CCMR1,CCRM1_OC1M_6);
					SET_BIT(MTIM4->CCMR1,CCRM1_OC1M_5);
					CLR_BIT(MTIM4->CCMR1,CCRM1_OC1M_4);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM4->CCMR1,CCRM1_OC1PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM4->CCER,CCER_CC1E);
					 break;
				case MTIM2_5_ch2:
					/*set the preScaler value in the preScaler register*/
					MTIM4->PSC=TIM4_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM4->CCMR1,CCRM1_OC2M_14);
					SET_BIT(MTIM4->CCMR1,CCRM1_OC2M_13);
					CLR_BIT(MTIM4->CCMR1,CCRM1_OC2M_12);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM4->CCMR1,CCRM1_OC2PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM4->CCER,CCER_CC2E);
			    	  break;
				case MTIM2_5_ch3:
					/*set the preScaler value in the preScaler register*/
					MTIM4->PSC=TIM4_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM4->CCMR2,CCRM2_OC3M_6);
					SET_BIT(MTIM4->CCMR2,CCRM2_OC3M_5);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC3M_4);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM4->CCMR2,CCRM2_OC3PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM4->CCER,CCER_CC3E);
					break;
				case MTIM2_5_ch4:
					/*set the preScaler value in the preScaler register*/
					MTIM4->PSC=TIM4_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM4->CCMR2,CCRM2_OC4M_14);
					SET_BIT(MTIM4->CCMR2,CCRM2_OC4M_13);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC4M_12);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM4->CCMR2,CCRM2_OC4PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM4->CCER,CCER_CC4E);
					 break;
				}
				break;
		case MTIM_5:
			switch(Copy_udtPWMchannel){
				case MTIM2_5_ch1:
					/*set the preScaler value in the preScaler register*/
					MTIM5->PSC=TIM5_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM5->CCMR1,CCRM1_OC1M_6);
					SET_BIT(MTIM5->CCMR1,CCRM1_OC1M_5);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC1M_4);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM5->CCMR1,CCRM1_OC1PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM5->CCER,CCER_CC1E);
					 break;
				case MTIM2_5_ch2:
					/*set the preScaler value in the preScaler register*/
					MTIM5->PSC=TIM5_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM5->CCMR1,CCRM1_OC2M_14);
					SET_BIT(MTIM5->CCMR1,CCRM1_OC2M_13);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC2M_12);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM5->CCMR1,CCRM1_OC2PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM5->CCER,CCER_CC2E);
			    	  break;
				case MTIM2_5_ch3:
					/*set the preScaler value in the preScaler register*/
					MTIM5->PSC=TIM5_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM5->CCMR2,CCRM2_OC3M_6);
					SET_BIT(MTIM5->CCMR2,CCRM2_OC3M_5);
					CLR_BIT(MTIM5->CCMR2,CCRM2_OC3M_4);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM5->CCMR2,CCRM2_OC3PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM5->CCER,CCER_CC3E);
					break;
				case MTIM2_5_ch4:
					/*set the preScaler value in the preScaler register*/
					MTIM5->PSC=TIM5_PRESCALER;
					/*select the pwm mode*/
					SET_BIT(MTIM5->CCMR2,CCRM2_OC4M_14);
					SET_BIT(MTIM5->CCMR2,CCRM2_OC4M_13);
					CLR_BIT(MTIM5->CCMR2,CCRM2_OC4M_12);
					/*enable output compre auto reload register*/
					SET_BIT(MTIM5->CCMR2,CCRM2_OC4PE);
					/*enable out put on the corresponding PIN*/
					SET_BIT(MTIM5->CCER,CCER_CC4E);
					 break;
				}
				break;
	}
}



void MTIM2_5_SetPWM(MTIMx_NUMBER_t Copy_udtTimerNumber,MTIM2_5_PWM_channel_num Copy_udtPWMchannel,u16 Copy_u16PRESCALER,u16 Copy_u16Frequancy,u16 Copy_DutyCycle){
switch(Copy_udtTimerNumber){
case MTIM_3:
			switch(Copy_udtPWMchannel){
			case MTIM2_5_ch1:
							/*set the frequency of the PWM*/
							MTIM3->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM3->CCR1=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM3->CR1,CR1_CEN);
							break;
			case MTIM2_5_ch2:
							/*set the frequency of the PWM*/
							MTIM3->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM3->CCR2=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM3->CR1,CR1_CEN);
								break;
			case MTIM2_5_ch3:
							/*set the frequency of the PWM*/
							MTIM3->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM3->CCR3=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM3->CR1,CR1_CEN);
							break;
						case MTIM2_5_ch4:
							/*set the frequency of the PWM*/
							MTIM3->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM3->CCR4=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM3->CR1,CR1_CEN);
							break;
						}
					break;
case MTIM_4:
			switch(Copy_udtPWMchannel){
			case MTIM2_5_ch1:
							/*set the frequency of the PWM*/
							MTIM4->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM4->CCR1=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM4->CR1,CR1_CEN);
							break;
			case MTIM2_5_ch2:
							/*set the frequency of the PWM*/
							MTIM4->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM4->CCR2=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM4->CR1,CR1_CEN);
							break;
			case MTIM2_5_ch3:
							/*set the frequency of the PWM*/
							MTIM4->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM4->CCR3=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM4->CR1,CR1_CEN);
							break;
			case MTIM2_5_ch4:
							/*set the frequency of the PWM*/
							MTIM4->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM4->CCR4=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM4->CR1,CR1_CEN);
							break;
					}
					break;
case MTIM_5:
			switch(Copy_udtPWMchannel){
			case MTIM2_5_ch1:
							/*set the frequency of the PWM*/
							MTIM5->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM5->CCR1=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM5->CR1,CR1_CEN);
							break;
			case MTIM2_5_ch2:
							/*set the frequency of the PWM*/
							MTIM5->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM5->CCR2=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM5->CR1,CR1_CEN);
							break;
			case MTIM2_5_ch3:
							/*set the frequency of the PWM*/
							MTIM5->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM5->CCR3=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM5->CR1,CR1_CEN);
							break;
			case MTIM2_5_ch4:
							/*set the frequency of the PWM*/
							MTIM5->ARR=Copy_u16Frequancy;
							/*set the duty cycle of the PWM*/
							MTIM5->CCR4=Copy_DutyCycle;
							/*enable timer to start the PWM*/
							SET_BIT(MTIM5->CR1,CR1_CEN);
							break;
					}
					break;
}
}


void MTIM2_5_voidICU_init(MTIMx_NUMBER_t Copy_udtTimerNumber,MTIM2_5_PWM_channel_num Copy_udtICUchannel){
	switch (Copy_udtTimerNumber){
	case MTIM_3:
		switch(Copy_udtICUchannel){
		case MTIM2_5_ch1:
			/*Select ICU*/
			CLR_BIT(MTIM3->CCMR1,CCRM1_CC1S1);
			SET_BIT(MTIM3->CCMR1,CCRM1_CC1S0);
			/*set the ICU FILTER value=0*/
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC1M_7);
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC1M_6);
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC1M_5);
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC1M_4);
			/*set ICU PRESCALER= no preScaler*/
			CLR_BIT(MTIM3->CCMR1,CCRM1_IC1PSC3);
			CLR_BIT(MTIM3->CCMR1,CCRM1_IC1PSC2);
			/*select the rising edge sense control*/
			SET_BIT(MTIM3->CCER,CCER_CC1P);
			SET_BIT(MTIM3->CCER,CCER_CC1NP);
			/*enable capture on the corresponding PIN*/
			SET_BIT(MTIM3->CCER,CCER_CC1E);
			/*enable interrupt*/
			SET_BIT(MTIM3->DIER,DIER_CC1IE);
			 break;
		case MTIM2_5_ch2:
			/*Select ICU*/
			CLR_BIT(MTIM3->CCMR1,CCRM1_CC2S1);
			SET_BIT(MTIM3->CCMR1,CCRM1_CC2S0);
			/*set the ICU FILTER value=0*/
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC2M_15);
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC2M_14);
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC2M_13);
			CLR_BIT(MTIM3->CCMR1,CCRM1_OC2M_12);
			/*set ICU PRESCALER= no preScaler*/
			CLR_BIT(MTIM3->CCMR1,CCRM1_IC2PSC10);
			CLR_BIT(MTIM3->CCMR1,CCRM1_IC2PSC11);
			/*select the rising edge sense control*/
			SET_BIT(MTIM3->CCER,CCER_CC2NP);
			SET_BIT(MTIM3->CCER,CCER_CC2P);
			/*enable capture on the corresponding PIN*/
			SET_BIT(MTIM3->CCER,CCER_CC2E);
			/*enable interrupt*/
			SET_BIT(MTIM3->DIER,DIER_CC2IE);
			 break;
		case MTIM2_5_ch3:
				/*Select ICU*/
				CLR_BIT(MTIM3->CCMR2,CCRM2_CC3S1);
				SET_BIT(MTIM3->CCMR2,CCRM2_CC3S0);
				/*set the ICU FILTER value=0*/
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC3M_7);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC3M_6);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC3M_5);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC3M_4);
				/*set ICU PRESCALER= no preScaler*/
				CLR_BIT(MTIM3->CCMR2,CCRM2_IC3PSC3);
				CLR_BIT(MTIM3->CCMR2,CCRM2_IC3PSC2);
				/*select the rising edge sense control*/
				SET_BIT(MTIM3->CCER,CCER_CC3NP);
				SET_BIT(MTIM3->CCER,CCER_CC3P);
				/*enable capture on the corresponding PIN*/
				SET_BIT(MTIM3->CCER,CCER_CC3E);
				/*enable interrupt*/
				SET_BIT(MTIM3->DIER,DIER_CC3IE);
				 break;
			case MTIM2_5_ch4:
				/*Select ICU*/
				CLR_BIT(MTIM3->CCMR2,CCRM2_CC4S1);
				SET_BIT(MTIM3->CCMR2,CCRM2_CC4S0);
				/*set the ICU FILTER value=0*/
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC4M_15);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC4M_14);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC4M_13);
				CLR_BIT(MTIM3->CCMR2,CCRM2_OC4M_12);
				/*set ICU PRESCALER= no preScaler*/
				CLR_BIT(MTIM3->CCMR2,CCRM2_IC4PSC10);
				CLR_BIT(MTIM3->CCMR2,CCRM2_IC4PSC11);
				/*select the rising edge sense control*/
				SET_BIT(MTIM3->CCER,CCER_CC4NP);
				SET_BIT(MTIM3->CCER,CCER_CC4P);
				/*enable capture on the corresponding PIN*/
				SET_BIT(MTIM3->CCER,CCER_CC4E);
				/*enable interrupt*/
				SET_BIT(MTIM3->DIER,DIER_CC4IE);
				 break;
}
		break;
		case MTIM_4:
			switch(Copy_udtICUchannel){
			case MTIM2_5_ch1:
				/*Select ICU*/
				CLR_BIT(MTIM4->CCMR1,CCRM1_CC1S1);
				SET_BIT(MTIM4->CCMR1,CCRM1_CC1S0);
				/*set the ICU FILTER value=0*/
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC1M_7);
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC1M_6);
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC1M_5);
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC1M_4);
				/*set ICU PRESCALER= no preScaler*/
				CLR_BIT(MTIM4->CCMR1,CCRM1_IC1PSC3);
				CLR_BIT(MTIM4->CCMR1,CCRM1_IC1PSC2);
				/*select the rising edge sense control*/
				SET_BIT(MTIM4->CCER,CCER_CC1P);
				SET_BIT(MTIM4->CCER,CCER_CC1NP);
				/*enable capture on the corresponding PIN*/
				SET_BIT(MTIM4->CCER,CCER_CC1E);
				/*enable interrupt*/
				SET_BIT(MTIM4->DIER,DIER_CC1IE);
				 break;
			case MTIM2_5_ch2:
				/*Select ICU*/
				CLR_BIT(MTIM4->CCMR1,CCRM1_CC2S1);
				SET_BIT(MTIM4->CCMR1,CCRM1_CC2S0);
				/*set the ICU FILTER value=0*/
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC2M_15);
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC2M_14);
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC2M_13);
				CLR_BIT(MTIM4->CCMR1,CCRM1_OC2M_12);
				/*set ICU PRESCALER= no preScaler*/
				CLR_BIT(MTIM4->CCMR1,CCRM1_IC2PSC10);
				CLR_BIT(MTIM4->CCMR1,CCRM1_IC2PSC11);
				/*select the rising edge sense control*/
				SET_BIT(MTIM4->CCER,CCER_CC2NP);
				SET_BIT(MTIM4->CCER,CCER_CC2P);
				/*enable capture on the corresponding PIN*/
				SET_BIT(MTIM4->CCER,CCER_CC2E);
				/*enable interrupt*/
				SET_BIT(MTIM4->DIER,DIER_CC2IE);
				 break;
			case MTIM2_5_ch3:
					/*Select ICU*/
					CLR_BIT(MTIM4->CCMR2,CCRM2_CC3S1);
					SET_BIT(MTIM4->CCMR2,CCRM2_CC3S0);
					/*set the ICU FILTER value=0*/
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC3M_7);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC3M_6);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC3M_5);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC3M_4);
					/*set ICU PRESCALER= no preScaler*/
					CLR_BIT(MTIM4->CCMR2,CCRM2_IC3PSC3);
					CLR_BIT(MTIM4->CCMR2,CCRM2_IC3PSC2);
					/*select the rising edge sense control*/
					SET_BIT(MTIM4->CCER,CCER_CC3NP);
					SET_BIT(MTIM4->CCER,CCER_CC3P);
					/*enable capture on the corresponding PIN*/
					SET_BIT(MTIM4->CCER,CCER_CC3E);
					/*enable interrupt*/
					SET_BIT(MTIM4->DIER,DIER_CC3IE);
					 break;
				case MTIM2_5_ch4:
					/*Select ICU*/
					CLR_BIT(MTIM4->CCMR2,CCRM2_CC4S1);
					SET_BIT(MTIM4->CCMR2,CCRM2_CC4S0);
					/*set the ICU FILTER value=0*/
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC4M_15);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC4M_14);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC4M_13);
					CLR_BIT(MTIM4->CCMR2,CCRM2_OC4M_12);
					/*set ICU PRESCALER= no preScaler*/
					CLR_BIT(MTIM4->CCMR2,CCRM2_IC4PSC10);
					CLR_BIT(MTIM4->CCMR2,CCRM2_IC4PSC11);
					/*select the rising edge sense control*/
					SET_BIT(MTIM4->CCER,CCER_CC4NP);
					SET_BIT(MTIM4->CCER,CCER_CC4P);
					/*enable capture on the corresponding PIN*/
					SET_BIT(MTIM4->CCER,CCER_CC4E);
					/*enable interrupt*/
					SET_BIT(MTIM4->DIER,DIER_CC4IE);
					 break;
	}
			break;
			case MTIM_5:
				switch(Copy_udtICUchannel){
				case MTIM2_5_ch1:
					/*Select ICU*/
					CLR_BIT(MTIM5->CCMR1,CCRM1_CC1S1);
					SET_BIT(MTIM5->CCMR1,CCRM1_CC1S0);
					/*set the ICU FILTER value=0*/
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC1M_7);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC1M_6);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC1M_5);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC1M_4);
					/*set ICU PRESCALER= no preScaler*/
					CLR_BIT(MTIM5->CCMR1,CCRM1_IC1PSC3);
					CLR_BIT(MTIM5->CCMR1,CCRM1_IC1PSC2);
					/*select the rising edge sense control*/
					SET_BIT(MTIM5->CCER,CCER_CC1P);
					SET_BIT(MTIM5->CCER,CCER_CC1NP);
					/*enable capture on the corresponding PIN*/
					SET_BIT(MTIM5->CCER,CCER_CC1E);
					/*enable interrupt*/
					SET_BIT(MTIM5->DIER,DIER_CC1IE);
					 break;
				case MTIM2_5_ch2:
					/*Select ICU*/
					CLR_BIT(MTIM5->CCMR1,CCRM1_CC2S1);
					SET_BIT(MTIM5->CCMR1,CCRM1_CC2S0);
					/*set the ICU FILTER value=0*/
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC2M_15);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC2M_14);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC2M_13);
					CLR_BIT(MTIM5->CCMR1,CCRM1_OC2M_12);
					/*set ICU PRESCALER= no preScaler*/
					CLR_BIT(MTIM5->CCMR1,CCRM1_IC2PSC10);
					CLR_BIT(MTIM5->CCMR1,CCRM1_IC2PSC11);
					/*select the rising edge sense control*/
					SET_BIT(MTIM5->CCER,CCER_CC2NP);
					SET_BIT(MTIM5->CCER,CCER_CC2P);
					/*enable capture on the corresponding PIN*/
					SET_BIT(MTIM5->CCER,CCER_CC2E);
					/*enable interrupt*/
					SET_BIT(MTIM5->DIER,DIER_CC2IE);
					 break;
				case MTIM2_5_ch3:
						/*Select ICU*/
						CLR_BIT(MTIM5->CCMR2,CCRM2_CC3S1);
						SET_BIT(MTIM5->CCMR2,CCRM2_CC3S0);
						/*set the ICU FILTER value=0*/
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC3M_7);
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC3M_6);
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC3M_5);
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC3M_4);
						/*set ICU PRESCALER= no preScaler*/
						CLR_BIT(MTIM5->CCMR2,CCRM2_IC3PSC3);
						CLR_BIT(MTIM5->CCMR2,CCRM2_IC3PSC2);
						/*select the rising edge sense control*/
						SET_BIT(MTIM5->CCER,CCER_CC3NP);
						SET_BIT(MTIM5->CCER,CCER_CC3P);
						/*enable capture on the corresponding PIN*/
						SET_BIT(MTIM5->CCER,CCER_CC3E);
						/*enable interrupt*/
						SET_BIT(MTIM5->DIER,DIER_CC3IE);
						 break;
					case MTIM2_5_ch4:
						/*Select ICU*/
						CLR_BIT(MTIM5->CCMR2,CCRM2_CC4S1);
						SET_BIT(MTIM5->CCMR2,CCRM2_CC4S0);
						/*set the ICU FILTER value=0*/
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC4M_15);
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC4M_14);
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC4M_13);
						CLR_BIT(MTIM5->CCMR2,CCRM2_OC4M_12);
						/*set ICU PRESCALER= no preScaler*/
						CLR_BIT(MTIM5->CCMR2,CCRM2_IC4PSC10);
						CLR_BIT(MTIM5->CCMR2,CCRM2_IC4PSC11);
						/*select the rising edge sense control*/
						SET_BIT(MTIM5->CCER,CCER_CC4NP);
						SET_BIT(MTIM5->CCER,CCER_CC4P);
						/*enable capture on the corresponding PIN*/
						SET_BIT(MTIM5->CCER,CCER_CC4E);
						/*enable interrupt*/
						SET_BIT(MTIM5->DIER,DIER_CC4IE);
						 break;
		}
				break;
	}

}

void MTIM3_setCALLBACK(void (*Copy_pvCallBACK)(void)){
	MTIM3_pvCallBack=Copy_pvCallBACK;
}
void MTIM4_setCALLBACK(void (*Copy_pvCallBACK)(void)){
	MTIM4_pvCallBack=Copy_pvCallBACK;
}
void MTIM5_setCALLBACK(void (*Copy_pvCallBACK)(void)){
	MTIM5_pvCallBack=Copy_pvCallBACK;
}
/*******************************/
void TIM2_IRQHandler(void){

}

void TIM3_IRQHandler(void){
	MTIM3_pvCallBack();
}
void TIM4_IRQHandler(void){
	MTIM4_pvCallBack();
}

void TIM5_IRQHandler(void){
	MTIM5_pvCallBack();
}
/***********************************/
