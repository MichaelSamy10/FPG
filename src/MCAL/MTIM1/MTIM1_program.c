/*
Author		: Muhammed Sherif Attia
date		: 18/2/2024
version		: 1.0.0
description : MTIM1_program.c -> Function impel
peri		: for the developer in MCAL only not for the user
*/
/**********************************************/
/************************************************/

/***************	TIM1 Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*TIM1 files*/
#include "MTIM1_interface.h"
#include "MTIM1_private.h"
#include "MTIM1_config.h"
#include "MTIM1_register.h"


/******** global variables *******/
static void(*MTIM1_pvCallBack)(void)=NULL;

/*********************************************/
/*********************************************/


/***************	TIM 1 Functions Implementations	***************/

/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidICU_init											 	*/
/* @Brief 	  :->		@ used to initialize selected timer(1) as ICU source	 		 	*/
/* @parameters   :-> 	@ Copy_udtChaNum: Channel that captures the Input value		 		*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ ICU preScaler must be PreConfiged in config file				  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
void MTIM1_voidICU_init(MTIM1_channel_t Copy_udtChaNum){
	switch (Copy_udtChaNum){
	case MTIM1_CH1:
		/*Select ICU*/
				CLR_BIT(MTIM1->CCMR1,CCRM1_CC1S1);
				SET_BIT(MTIM1->CCMR1,CCRM1_CC1S0);
				/*set the ICU FILTER value=0*/
				CLR_BIT(MTIM1->CCMR1,CCRM1_OC1M_7);
				CLR_BIT(MTIM1->CCMR1,CCRM1_OC1M_6);
				CLR_BIT(MTIM1->CCMR1,CCRM1_OC1M_5);
				CLR_BIT(MTIM1->CCMR1,CCRM1_OC1M_4);
				/*set ICU PRESCALER= no preScaler*/
				CLR_BIT(MTIM1->CCMR1,CCRM1_IC1PSC3);
				CLR_BIT(MTIM1->CCMR1,CCRM1_IC1PSC2);
				/*select the rising edge sense control*/
				SET_BIT(MTIM1->CCER,CCER_CC1P);
				SET_BIT(MTIM1->CCER,CCER_CC1NP);
				/*enable capture on the corresponding PIN*/
				SET_BIT(MTIM1->CCER,CCER_CC1E);
				/* Set prescaler  */
				MTIM1->PSC = TIM1_ICU_PRESCALER;
				/* Set Preload */
				MTIM1->ARR=TIM1_ICU_ARRval;
				/*enable interrupt*/
				SET_BIT(MTIM1->DIER,DIER_CC1IE);
				/*enable timer to start ICU*/
				SET_BIT(MTIM1->CR1,CR1_CEN);
				break;
	case MTIM1_CH2:
		/*Select ICU*/
					CLR_BIT(MTIM1->CCMR1,CCRM1_CC2S1);
					SET_BIT(MTIM1->CCMR1,CCRM1_CC2S0);
					/*set the ICU FILTER value=0*/
					CLR_BIT(MTIM1->CCMR1,CCRM1_OC2M_15);
					CLR_BIT(MTIM1->CCMR1,CCRM1_OC2M_14);
					CLR_BIT(MTIM1->CCMR1,CCRM1_OC2M_13);
					CLR_BIT(MTIM1->CCMR1,CCRM1_OC2M_12);
					/*set ICU PRESCALER= no preScaler*/
					CLR_BIT(MTIM1->CCMR1,CCRM1_IC2PSC3);
					CLR_BIT(MTIM1->CCMR1,CCRM1_IC2PSC2);
					/*select the rising edge sense control*/
					SET_BIT(MTIM1->CCER,CCER_CC2P);
					SET_BIT(MTIM1->CCER,CCER_CC2NP);
					/*enable capture on the corresponding PIN*/
					SET_BIT(MTIM1->CCER,CCER_CC2E);
					/* Set prescaler  */
					MTIM1->PSC = TIM1_ICU_PRESCALER;
					/* Set Preload */
					MTIM1->ARR=TIM1_ICU_ARRval;
					/*enable interrupt*/
					SET_BIT(MTIM1->DIER,DIER_CC2IE);
					/*enable timer to start ICU*/
					SET_BIT(MTIM1->CR1,CR1_CEN);
					break;
	case MTIM1_CH3:
		/*Select ICU*/
				CLR_BIT(MTIM1->CCMR2,CCRM2_CC3S1);
				SET_BIT(MTIM1->CCMR2,CCRM2_CC3S0);
				/*set the ICU FILTER value=0*/
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC3M_7);
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC3M_6);
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC3M_5);
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC3M_4);
				/*set ICU PRESCALER= no preScaler*/
				CLR_BIT(MTIM1->CCMR2,CCRM2_IC3PSC3);
				CLR_BIT(MTIM1->CCMR2,CCRM2_IC3PSC2);
				/*select the rising edge sense control*/
				SET_BIT(MTIM1->CCER,CCER_CC3P);
				SET_BIT(MTIM1->CCER,CCER_CC3NP);
				/*enable capture on the corresponding PIN*/
				SET_BIT(MTIM1->CCER,CCER_CC3E);
				/* Set prescaler  */
				MTIM1->PSC = TIM1_ICU_PRESCALER;
				/* Set Preload */
				MTIM1->ARR=TIM1_ICU_ARRval;
				/*enable interrupt*/
				SET_BIT(MTIM1->DIER,DIER_CC3IE);
				/*enable timer to start ICU*/
				SET_BIT(MTIM1->CR1,CR1_CEN);
				break;
	case MTIM1_CH4:
		/*Select ICU*/
				CLR_BIT(MTIM1->CCMR2,CCRM2_CC4S1);
				SET_BIT(MTIM1->CCMR2,CCRM2_CC4S0);
				/*set the ICU FILTER value=0*/
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC4M_15);
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC4M_14);
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC4M_13);
				CLR_BIT(MTIM1->CCMR2,CCRM2_OC4M_12);
				/*set ICU PRESCALER= no preScaler*/
				CLR_BIT(MTIM1->CCMR2,CCRM2_IC4PSC3);
				CLR_BIT(MTIM1->CCMR2,CCRM2_IC4PSC2);
				/*select the rising edge sense control*/
				SET_BIT(MTIM1->CCER,CCER_CC4P);
				/*enable capture on the corresponding PIN*/
				SET_BIT(MTIM1->CCER,CCER_CC4E);
				/* Set prescaler  */
				MTIM1->PSC = TIM1_ICU_PRESCALER;
				/* Set Preload */
				MTIM1->ARR=TIM1_ICU_ARRval;
				/*enable interrupt*/
				SET_BIT(MTIM1->DIER,DIER_CC4IE);
				/*enable timer to start ICU*/
				SET_BIT(MTIM1->CR1,CR1_CEN);
				break;
	}
}
/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidEnableICU_interrupt									 	*/
/* @Brief 	  :->		@ used to enable ICU interrupt on timer(1) 							*/
/* @parameters   :-> 	@ Copy_udtChaNum: Channel that captures the Input value			 	*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ Timer must be initialized as icu								  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
void MTIM1_voidEnableICU_interrupt(MTIM1_channel_t Copy_udtChaNum){
	switch (Copy_udtChaNum){
								case MTIM1_CH1:		SET_BIT(MTIM1->DIER,DIER_CC1IE);	break;   /*ENABLE INTERRUPT for TIM1 ICU CH 1*/
								case MTIM1_CH2:		SET_BIT(MTIM1->DIER,DIER_CC2IE);	break;   /*ENABLE INTERRUPT for TIM1 ICU CH 2*/
								case MTIM1_CH3:		SET_BIT(MTIM1->DIER,DIER_CC3IE);	break;   /*ENABLE INTERRUPT for TIM1 ICU CH 3*/
								case MTIM1_CH4:		SET_BIT(MTIM1->DIER,DIER_CC4IE);	break;   /*ENABLE INTERRUPT for TIM1 ICU CH 4*/
					}
}
/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidDisableICU_interrupt								 	*/
/* @Brief 	  :->		@ used to disable ICU interrupt on timer(1) 						*/
/* @parameters   :-> 	@ Copy_udtChaNum: Channel that captures the Input value			 	*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ Timer must be initialized as icu								  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
void MTIM1_voidDisableICU_interrupt(MTIM1_channel_t Copy_udtChaNum){
	switch (Copy_udtChaNum){
								case MTIM1_CH1:		CLR_BIT(MTIM1->DIER,DIER_CC1IE);	break;   /*DISABLE INTERRUPT for TIM1 ICU CH 1*/
								case MTIM1_CH2:		CLR_BIT(MTIM1->DIER,DIER_CC2IE);	break;   /*DISABLE INTERRUPT for TIM1 ICU CH 2*/
								case MTIM1_CH3:		CLR_BIT(MTIM1->DIER,DIER_CC3IE);	break;   /*DISABLE INTERRUPT for TIM1 ICU CH 3*/
								case MTIM1_CH4:		CLR_BIT(MTIM1->DIER,DIER_CC4IE);	break;   /*DISABLE INTERRUPT for TIM1 ICU CH 4*/
					}
}
/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidChangeICU_polarity									 	*/
/* @Brief 	  :->		@ used to change ICU sense polarity during runtime					*/
/* @parameters   :-> 	@ Copy_udtChaNum: Channel that captures the Input value			 	*/
/*						@ Copy_udtSenseEDGE: sense polarity for the ICU channel				*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ Timer must be initialized as icu								  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
void MTIM1_voidChangeICU_polarity(MTIM1_channel_t Copy_udtChaNum,MTIM1_ICU_Polarity_t Copy_udtSenseEDGE){
	switch (Copy_udtSenseEDGE){
	case MTIM_RisingEdge:
					switch (Copy_udtChaNum){
								case MTIM1_CH1:	CLR_BIT(MTIM1->CCER,CCER_CC1P); CLR_BIT(MTIM1->CCER,CCER_CC1NP); break;  /*Set timer1 ICU  sense mode as rising edge */
								case MTIM1_CH2:	CLR_BIT(MTIM1->CCER,CCER_CC2P); CLR_BIT(MTIM1->CCER,CCER_CC2NP); break;  /*Set timer1 ICU  sense mode as rising edge */
								case MTIM1_CH3:	CLR_BIT(MTIM1->CCER,CCER_CC3P); CLR_BIT(MTIM1->CCER,CCER_CC3NP); break;  /*Set timer1 ICU  sense mode as rising edge */
								case MTIM1_CH4:	CLR_BIT(MTIM1->CCER,CCER_CC4P); 	 break;								 /*Set timer1 ICU  sense mode as rising edge */
					}
					break;
case MTIM_FallingEdge:
				switch (Copy_udtChaNum){
							case MTIM1_CH1:	SET_BIT(MTIM1->CCER,CCER_CC1P); CLR_BIT(MTIM1->CCER,CCER_CC1NP); break;  /*Set timer1 ICU  sense mode as rising edge */
							case MTIM1_CH2:	SET_BIT(MTIM1->CCER,CCER_CC2P); CLR_BIT(MTIM1->CCER,CCER_CC2NP); break;  /*Set timer1 ICU  sense mode as rising edge */
							case MTIM1_CH3:	SET_BIT(MTIM1->CCER,CCER_CC3P); CLR_BIT(MTIM1->CCER,CCER_CC3NP); break;  /*Set timer1 ICU  sense mode as rising edge */
							case MTIM1_CH4:	SET_BIT(MTIM1->CCER,CCER_CC4P); 	 break;								 /*Set timer1 ICU  sense mode as rising edge */
									}
									break;
}
}
/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_u32ReturnICU_value										 	*/
/* @Brief 	  :->		@ used to return the capture value in the CCRx register				*/
/* @parameters   :->    @ Copy_udtChaNum: Channel that captures the Input value		 		*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ Timer must be initialized as icu								  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
u32 MTIM1_u32ReturnICU_value(MTIM1_channel_t Copy_udtChaNum){
	u32 Local_RetVALUE=0;
	switch (Copy_udtChaNum){
								case MTIM2_5_ch1:	Local_RetVALUE=MTIM1->CCR1	; break;     /*get the value from the CCRx register*/
								case MTIM2_5_ch2:	Local_RetVALUE=MTIM1->CCR2	; break;     /*get the value from the CCRx register*/
								case MTIM2_5_ch3:	Local_RetVALUE=MTIM1->CCR3	; break;     /*get the value from the CCRx register*/
								case MTIM2_5_ch4:	Local_RetVALUE=MTIM1->CCR4	; break;     /*get the value from the CCRx register*/
					}
	return Local_RetVALUE;	/*return the captured value*/
}
/******************************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidSetCallBacK_ICU												 	  */
/* @Brief 	  :->		@ used to set the ISR for timer 1 interrupts							      */
/* @parameters   :-> 	@ Copy_pvCallBackFunc: pointer to the function to be excuted at interrupt fire*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 		  	  */
/*						@ timer must be enabled with RCC								 		  	  */
/*						@ Timer must interrupt must be enabled							  		  	  */
/*						@ timer interrupt must be enabled in NVIC								  	  */
/******************************************************************************************************/
void MTIM1_voidSetCallBacK_ICU(void(*Copy_pvCallBackFunc)(void)){
	MTIM1_pvCallBack=Copy_pvCallBackFunc;        /*Set the ISR for TIMER 5 interrupt*/
}

/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/************************Interrupt handlers for timers 2:5**********************************/
void TIM1_CC_IRQHandler(void){
	MTIM1_pvCallBack();
}



