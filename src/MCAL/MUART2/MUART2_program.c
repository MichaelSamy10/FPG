/*
 * MUART_program.c
 *
 *  Created on: Jan 24, 2024
 *      Author: BROTHERS
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MUART2_config.h"
#include "MUART2_interface.h"
#include "MUART2_private.h"
#include "MUART2_register.h"

void (*Gpv_MUSART2_CallBACK_Func)(void)= NULL;

void MUSART2_voidInit(void){
	/*set bud rate to 115200 Bp/s*/
		MUSART2->BRR =0x0000008B;
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

void MUSART2_voidSendData(u8 Copy_u8Data){
MUSART2->DR=Copy_u8Data;
while(GET_BIT(MUSART2->SR,7)==0){
		asm("NOP");
	}
}
u8 MUSART2_voidReciveData(void){

	while(!(GET_BIT(MUSART2->SR,5))){
			asm("NOP");
	}
return (u8) MUSART2->DR;
}

u8 MUSART2_voidRecieveAsynchronous(void){
	SET_BIT(MUSART2->CR1,5);
	return (u8) MUSART2->DR;
}

void MUSART2_voidEnable(void){
	SET_BIT(MUSART2->CR1,13);
}

void MUSART2_voidDisable(void){
	CLR_BIT(MUSART2->CR1,13);
}

void MUSART2_voidSendString(u8 *Copy_pu8Ddata){
	u8 L_u8Iterator=0;
		while ( Copy_pu8Ddata[L_u8Iterator] != '\0')
			{
				MUSART2->DR = Copy_pu8Ddata[L_u8Iterator];
				while( GET_BIT(MUSART2->SR,7) == 0 );
				L_u8Iterator++;
			}
}

void MUSART2_voidSetCallBack(void(*vp_Fumc)(void)){
	Gpv_MUSART_CallBACK_Func=vp_Fumc;
}


void USART2_IRQHandler(void){
	if(Gpv_MUSART2_CallBACK_Func!=NULL){
		Gpv_MUSART2_CallBACK_Func();
	}
}
