/*
Author		: Muhammed Sherif Attia
date		: 21/2/2024
version		: 1.0.0
description : MUSART6_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/

#ifndef MUSART6_MUSART6_INTERFACE_H_
#define MUSART6_MUSART6_INTERFACE_H_
/*********************************************/
/*********************************************/

/***************	MUSART6 Functions Prototypes	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidInit												 	*/
/* @Brief 	  :->		@ used to initialize USART 2 Configs							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART6_voidInit(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidSendData											 	*/
/* @Brief 	  :->		@ used to send data using USART 2								 	*/
/* @parameters   :-> 	@ Copy_u8Data-> data to be sent										*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART6_voidSendData(u8 Copy_u8Data);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidReciveData										 	*/
/* @Brief 	  :->		@ used to receive data using USART 2							 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
u8 MUSART6_voidReciveData(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidRecieveAsynchronous								 	*/
/* @Brief 	  :->		@ used to receive data using USART 2 interrupt					 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
u8 MUSART6_voidRecieveAsynchronous(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidEnable											 	*/
/* @Brief 	  :->		@ used to Enable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART6_voidEnable(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidEnableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART6_voidEnableInterrupt(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidDisableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART6_voidDisableInterrupt(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidDisable											 	*/
/* @Brief 	  :->		@ used to Disable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART6_voidDisable(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidSendString										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ Copy_pu8Ddata-> Pointer to string data to be sent					*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART6_voidSendString(u8 *Copy_pu8Data);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART6_voidSetCallBack										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ vp_Fumc-> Pointer to ISR CALLBACK func							*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART6_voidSetCallBack(void(*vp_Fumc)(void));

#endif /* MUART_MUART_INTERFACE_H_ */
