/*
Author		: Muhammed Sherif Attia
date		: 21/2/2024
version		: 1.0.0
description : MUSART2_program.c -> Functions impelemntations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	MUSART2 Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*MUSART2 files*/
#include "MUART2_interface.h"
#include "MUART2_config.h"
#include "MUART2_private.h"
#include "MUART2_register.h"
/*********************************************/
/*********************************************/

/***************	Global variables	***************/
void (*Gpv_MUSART2_CallBACK_Func)(void)= NULL;
/*********************************************/
/*********************************************/

/***************	MUSART2 Functions Implementations	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidInit												 	*/
/* @Brief 	  :->		@ used to initialize USART 2 Configs							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART2_voidInit(void){
	/*set bud rate to 9600 Bp/s*/
		MUSART2->BRR =MUSART2_BAUD_RATE;
	/*set stop bit*/
		CLR_BIT(MUSART2->CR2,12);
		CLR_BIT(MUSART2->CR2,13);
	/*word length*/
		CLR_BIT(MUSART2->CR1,12);
	/*set sampling*/
		CLR_BIT(MUSART2->CR1,15);
		/*one Sample Bit*/
		SET_BIT(MUSART2->CR3,11);
	/*enable transmit*/
		SET_BIT(MUSART2->CR1,3);
	/*enable receive*/
		SET_BIT(MUSART2->CR1,2);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidSendData											 	*/
/* @Brief 	  :->		@ used to send data using USART 2								 	*/
/* @parameters   :-> 	@ Copy_u8Data-> data to be sent										*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART2_voidSendData(u8 Copy_u8Data){
	MUSART2->DR=Copy_u8Data;
	while(GET_BIT(MUSART2->SR,7)==0){
			asm("NOP");
		}
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidReciveData										 	*/
/* @Brief 	  :->		@ used to receive data using USART 2							 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
u8 MUSART2_voidReciveData(void){

	while(!(GET_BIT(MUSART2->SR,5))){
			asm("NOP");
	}
return (u8) MUSART2->DR;
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidRecieveAsynchronous								 	*/
/* @Brief 	  :->		@ used to receive data using USART 2 interrupt					 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
u8 MUSART2_voidRecieveAsynchronous(void){
	//SET_BIT(MUSART2->CR1,5);
	return (u8) MUSART2->DR;
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidEnableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART2_voidEnableInterrupt(void)
{
	SET_BIT(MUSART2->CR1,5);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidDisableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART2_voidDisableInterrupt(void)
{
	CLR_BIT(MUSART2->CR1,5);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidEnable											 	*/
/* @Brief 	  :->		@ used to Enable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART2_voidEnable(void){
	SET_BIT(MUSART2->CR1,13);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidDisable											 	*/
/* @Brief 	  :->		@ used to Disable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART2_voidDisable(void){
	CLR_BIT(MUSART2->CR1,13);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidSendString										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ Copy_pu8Ddata-> Pointer to string data to be sent					*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART2_voidSendString(u8 *Copy_pu8Ddata){
	u8 L_u8Iterator=0;
		while ( Copy_pu8Ddata[L_u8Iterator] != '\0')
			{
				MUSART2->DR = Copy_pu8Ddata[L_u8Iterator];
				while( GET_BIT(MUSART2->SR,7) == 0 );
				L_u8Iterator++;
			}
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidSetCallBack										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ vp_Fumc-> Pointer to ISR CALLBACK func							*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART2_voidSetCallBack(void(*vp_Fumc)(void)){
	Gpv_MUSART2_CallBACK_Func=vp_Fumc;
}

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/****	USART2 interrupt handler ****/
void USART2_IRQHandler(void){
	if(Gpv_MUSART2_CallBACK_Func!=NULL){
		Gpv_MUSART2_CallBACK_Func();
	}
}
