/*
Author		: Muhammed Sherif Attia
date		: 18/2/2024
version		: 1.0.0
description : MTIM1_interface.h -> function prototypes
peri		: for the developer in MCAL only not for the user
*/
#ifndef MCAL_MTIM1_MTIM1_INTERFACE_H_
#define MCAL_MTIM1_MTIM1_INTERFACE_H_
/*********************************************/
/*********************************************/
/******************************	user defined MACROS		******************************/


/******************************	user defined DATA TYPES		******************************/
/***************	TIM1 select Channel ***************/
typedef enum{
	MTIM1_CH1,
	MTIM1_CH2,
	MTIM1_CH3,
	MTIM1_CH4
}MTIM1_channel_t;
/***************	TIM1 select Polarity ***************/
typedef enum{
	MTIM1_RisingEdge,
	MTIM1_FallingEdge,
}MTIM1_ICU_Polarity_t;


/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidICU_init											 	*/
/* @Brief 	  :->		@ used to initialize selected timer(1) as ICU source	 		 	*/
/* @parameters   :-> 	@ Copy_udtChaNum: Channel that captures the Input value		 		*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ ICU preScaler must be PreConfiged in config file				  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
void MTIM1_voidICU_init(MTIM1_channel_t Copy_udtChaNum);
/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidEnableICU_interrupt									 	*/
/* @Brief 	  :->		@ used to enable ICU interrupt on timer(1) 							*/
/* @parameters   :-> 	@ Copy_udtChaNum: Channel that captures the Input value			 	*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ Timer must be initialized as icu								  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
void MTIM1_voidEnableICU_interrupt(MTIM1_channel_t Copy_udtChaNum);
/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidDisableICU_interrupt								 	*/
/* @Brief 	  :->		@ used to disable ICU interrupt on timer(1) 						*/
/* @parameters   :-> 	@ Copy_udtChaNum: Channel that captures the Input value			 	*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ Timer must be initialized as icu								  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
void MTIM1_voidDisableICU_interrupt(MTIM1_channel_t Copy_udtChaNum);
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
void MTIM1_voidChangeICU_polarity(MTIM1_channel_t Copy_udtChaNum,MTIM1_ICU_Polarity_t Copy_udtSenseEDGE);
/********************************************************************************************/
/* @Name  	  :->		@ MTIM1_u32ReturnICU_value										 	*/
/* @Brief 	  :->		@ used to return the capture value in the CCRx register				*/
/* @parameters   :->    @ Copy_udtChaNum: Channel that captures the Input value		 		*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 	*/
/*						@ timer must be enabled with RCC								 	*/
/*						@ Timer must be initialized as icu								  	*/
/*						@ the GPIO pin corresponding to the cahannel must be set as alt-func*/
/********************************************************************************************/
u32 MTIM1_u32ReturnICU_value(MTIM1_channel_t Copy_udtChaNum);
/******************************************************************************************************/
/* @Name  	  :->		@ MTIM1_voidSetCallBacK_ICU												 	  */
/* @Brief 	  :->		@ used to set the ISR for timer 1 interrupts							      */
/* @parameters   :-> 	@ Copy_pvCallBackFunc: pointer to the function to be excuted at interrupt fire*/
/* @PreRequsteis :->	@ RCC MUST be initialized								 		 		  	  */
/*						@ timer must be enabled with RCC								 		  	  */
/*						@ Timer must interrupt must be enabled							  		  	  */
/*						@ timer interrupt must be enabled in NVIC								  	  */
/******************************************************************************************************/
void MTIM1_voidSetCallBacK_ICU(void(*Copy_pvCallBackFunc)(void));

#endif /* MCAL_MTIM1_MTIM1_INTERFACE_H_ */
