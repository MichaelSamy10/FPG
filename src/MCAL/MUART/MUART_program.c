/*
 * MUART_program.c
 *
 *  Created on: Jan 24, 2024
 *      Author: BROTHERS
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MUART_interface.h"
#include "MUART_config.h"
#include "MUART_private.h"
#include "MUART_register.h"

void (*Gpv_MUSART_CallBACK_Func)(void)= NULL;

void MUSART_voidInit(void){
	/*set bud rate to 115200 Bp/s*/
		MUSART1->BRR =0x0000008B;
	/*set stop bit*/
		CLR_BIT(MUSART1->CR2,12);
		CLR_BIT(MUSART1->CR2,13);
	/*word length*/
		CLR_BIT(MUSART1->CR1,12);
	/*set sampling*/
		CLR_BIT(MUSART1->CR1,15);
		/*one Sample Bit*/
		SET_BIT(MUSART1->CR3,11);
	/*enable transmit*/
		SET_BIT(MUSART1->CR1,3);
	/*enable receive*/
		SET_BIT(MUSART1->CR1,2);
}

void MUSART_voidSendData(u8 Copy_u8Data){
MUSART1->DR=Copy_u8Data;
while(GET_BIT(MUSART1->SR,7)==0){
		asm("NOP");
	}
}
u8 MUSART_voidReciveData(void){

	while(!(GET_BIT(MUSART1->SR,5))){
			asm("NOP");
	}
return (u8) MUSART1->DR;
}

u8 MUSART_voidRecieveAsynchronous(void){
	SET_BIT(MUSART1->CR1,5);
	return (u8) MUSART1->DR;
}

void MUSART_voidEnable(void){
	SET_BIT(MUSART1->CR1,13);
}

void MUSART_voidDisable(void){
	CLR_BIT(MUSART1->CR1,13);
}

void MUSART_voidSendString(u8 *Copy_pu8Ddata){
	u8 L_u8SizeOfArray = (sizeof(Copy_pu8Ddata)/sizeof(Copy_pu8Ddata[0]));
	for(u8 L_u8iterrator=0;L_u8iterrator<L_u8SizeOfArray;L_u8iterrator++){
		MUSART1->DR=Copy_pu8Ddata[L_u8iterrator];
		while(GET_BIT(MUSART1->SR,7)==0){
				asm("NOP");
			}
	}
}

void MUSART_voidSetCallBack(void(*vp_Fumc)(void)){
	Gpv_MUSART_CallBACK_Func=vp_Fumc;
}


void USART1_IRQHandler(void){
	if(Gpv_MUSART_CallBACK_Func!=NULL){
		Gpv_MUSART_CallBACK_Func();
	}
}
