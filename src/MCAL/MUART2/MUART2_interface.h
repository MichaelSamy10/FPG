/*
Author		: Muhammed Sherif Attia
date		: 21/2/2024
version		: 1.0.0
description : MUSART2_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/

#ifndef MUART2_MUART2_INTERFACE_H_
#define MUART2_MUART2_INTERFACE_H_
/*********************************************/
/*********************************************/

/***************	MUSART2 Functions Prototypes	***************/
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidInit												 	*/
/* @Brief 	  :->		@ used to initialize USART 2 Configs							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART2_voidInit(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidSendData											 	*/
/* @Brief 	  :->		@ used to send data using USART 2								 	*/
/* @parameters   :-> 	@ Copy_u8Data-> data to be sent										*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART2_voidSendData(u8 Copy_u8Data);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidReciveData										 	*/
/* @Brief 	  :->		@ used to receive data using USART 2							 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
u8 MUSART2_voidReciveData(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidRecieveAsynchronous								 	*/
/* @Brief 	  :->		@ used to receive data using USART 2 interrupt					 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
u8 MUSART2_voidRecieveAsynchronous(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidEnable											 	*/
/* @Brief 	  :->		@ used to Enable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART2_voidEnable(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidEnableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART2_voidEnableInterrupt(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidDisableInterrupt								 	*/
/* @Brief 	  :->		@ used to enable USART2 interrupt					 				*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/*						@ USART2 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
void MUSART2_voidDisableInterrupt(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidDisable											 	*/
/* @Brief 	  :->		@ used to Disable USART 2 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART2_voidDisable(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidSendString										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ Copy_pu8Ddata-> Pointer to string data to be sent					*/
/* @PreRequsteis :->	@ the Prepheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART2_voidSendString(u8 *Copy_pu8Data);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART2_voidSetCallBack										 	*/
/* @Brief 	  :->		@ used to send String data using USART 2							*/
/* @parameters   :-> 	@ vp_Fumc-> Pointer to ISR CALLBACK func							*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART2 must be initialized										*/
/********************************************************************************************/
void MUSART2_voidSetCallBack(void(*vp_Fumc)(void));

#endif /* MUART_MUART_INTERFACE_H_ */
