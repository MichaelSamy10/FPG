/*
Author		: Muhammed Sherif Attia
date		: 24/1/2024
version		: 1.0.0
description : MUSART1_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/

#ifndef MUART_MUART_INTERFACE_H_
#define MUART_MUART_INTERFACE_H_


/*************************************************************************************/
/*************************************************************************************/
/***************	MUSART11 Functions prototypes	***************/


/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidInit												 	*/
/* @Brief 	  :->		@ used to initialize USART 1 Configs							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART1_voidInit(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidSendData											 	*/
/* @Brief 	  :->		@ used to send data using USART 1								 	*/
/* @parameters   :-> 	@ Copy_u8Data-> data to be sent										*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART1 must be initialized										*/
/********************************************************************************************/
void MUSART1_voidSendData(u8 Copy_u8Data);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidReciveData											 	*/
/* @Brief 	  :->		@ used to receive data using USART 1							 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART1 must be initialized										*/
/********************************************************************************************/
u8 MUSART1_voidReciveData(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidRecieveAsynchronous								 	*/
/* @Brief 	  :->		@ used to receive data using USART 1 interrupt					 	*/
/*						@ returns a u8 data from the receiving process						*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART1 must be initialized										*/
/*						@ USART1 interrupt must be enabled using NVIC						*/
/********************************************************************************************/
u8 MUSART1_voidRecieveAsynchronous(void);

/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidEnableInterrupt												 	*/
/* @Brief 	  :->		@ used to Enable USART1 Interrupt	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART1_voidEnableInterrupt(void);

/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidEnableInterrupt												 	*/
/* @Brief 	  :->		@ used to Disable USART1 Interrupt	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART1_voidEnableInterrupt(void);

/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidEnable												 	*/
/* @Brief 	  :->		@ used to Enable USART 1 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART1_voidEnable(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidDisable											 	*/
/* @Brief 	  :->		@ used to Disable USART 1 registers	 							 	*/
/* @parameters   :-> 	@ void																*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/********************************************************************************************/
void MUSART1_voidDisable(void);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidSendString											 	*/
/* @Brief 	  :->		@ used to send String data using USART 1							*/
/* @parameters   :-> 	@ Copy_pu8Ddata-> Pointer to string data to be sent					*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART1 must be initialized										*/
/********************************************************************************************/
void MUSART1_voidSendString(u8 *Copy_pu8Data);
/********************************************************************************************/
/* @Name  	  :->		@ MUSART1_voidSetCallBack										 	*/
/* @Brief 	  :->		@ used to send String data using USART 1							*/
/* @parameters   :-> 	@ vp_Fumc-> Pointer to ISR CALLBACK func							*/
/* @PreRequsteis :->	@ the Peripheral clock must be enabled in the RCC 					*/
/*						@ USART1 must be initialized										*/
/********************************************************************************************/
void MUSART1_voidSetCallBack(void(*vp_Func)(void));

#endif /* MUART_MUART_INTERFACE_H_ */
