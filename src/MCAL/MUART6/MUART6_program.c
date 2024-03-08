/*
Author		: Muhammed Sherif Attia
date		: 21/2/2024
version		: 1.0.0
description : MUSART6_program.c -> Functions impelemntations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	MUSART6 Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*MUSART6 files*/
#include "MUART6_config.h"
#include "MUART6_interface.h"
#include "MUART6_private.h"
#include "MUART6_register.h"
/*********************************************/
/*********************************************/

/***************	Global variables	***************/
void (*Gpv_MUSART6_CallBACK_Func)(void)= NULL;
/*********************************************/
/*********************************************/

/***************	MUSART6 Functions Implementations	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidInit												 	*/
/* @Brief 	  :->		@ used to initialize USART 2 Configs							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART6_voidInit(void){
	/*set bud rate to 9600 Bp/s*/
		MUSART6->BRR =MUSART6_BAUD_RATE;
	/*set stop bit*/
		CLR_BIT(MUSART6->CR2,12);
		CLR_BIT(MUSART6->CR2,13);
	/*word length*/
		CLR_BIT(MUSART6->CR1,12);
	/*set sampling*/
		CLR_BIT(MUSART6->CR1,15);
		/*one Sample Bit*/
		SET_BIT(MUSART6->CR3,11);
	/*enable transmit*/
		SET_BIT(MUSART6->CR1,3);
	/*enable receive*/
		SET_BIT(MUSART6->CR1,2);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidSendData											 	*/
/* @Brief 	  :->		@ used to send data using USART 2								 	*/
/* @parameters   :-> 	@ Copy_u8Data-> data to be sent										*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART6_voidSendData(u8 Copy_u8Data){
	MUSART6->DR=Copy_u8Data;
	while(GET_BIT(MUSART6->SR,7)==0){
			asm("NOP");
		}
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidReciveData										 	*/
/* @Brief 	  :->		@ used to receive data using USART 2							 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
u8 MUSART6_voidReciveData(void){

	while(!(GET_BIT(MUSART6->SR,5))){
			asm("NOP");
	}
return (u8) MUSART6->DR;
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidRecieveAsynchronous								 	*/
/* @Brief 	  :->		@ used to receive data using USART 2 interrupt					 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
u8 MUSART6_voidRecieveAsynchronous(void){
	//SET_BIT(MUSART6->CR1,5);
	return (u8) MUSART6->DR;
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidEnableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART6_voidEnableInterrupt(void)
{
	SET_BIT(MUSART6->CR1,5);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidDisableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART6_voidDisableInterrupt(void)
{
	CLR_BIT(MUSART6->CR1,5);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidEnable											 	*/
/* @Brief 	  :->		@ used to Enable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART6_voidEnable(void){
	SET_BIT(MUSART6->CR1,13);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidDisable											 	*/
/* @Brief 	  :->		@ used to Disable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART6_voidDisable(void){
	CLR_BIT(MUSART6->CR1,13);
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidSendString										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ Copy_pu8Ddata-> Pointer to string data to be sent					*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART6_voidSendString(u8 *Copy_pu8Ddata){
	u8 L_u8Iterator=0;
		while ( Copy_pu8Ddata[L_u8Iterator] != '\0')
			{
				MUSART6->DR = Copy_pu8Ddata[L_u8Iterator];
				while( GET_BIT(MUSART6->SR,7) == 0 );
				L_u8Iterator++;
			}
}
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidSetCallBack										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ vp_Fumc-> Pointer to ISR CALLBACK func							*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART6_voidSetCallBack(void(*vp_Fumc)(void)){
	Gpv_MUSART6_CallBACK_Func=vp_Fumc;
}

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/****	USART2 interrupt handler ****/
void USART6_IRQHandler(void){
	if(Gpv_MUSART6_CallBACK_Func!=NULL){
		Gpv_MUSART6_CallBACK_Func();
	}
}
