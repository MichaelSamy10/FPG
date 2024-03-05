/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MUSART_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/

#ifndef MUART_MUART_REGISTER_H_
#define MUART_MUART_REGISTER_H_
/*****************************************************/
/*****************************************************/

/***************	MUSART1 BaseAddress		***************/
#define MUSART1_BASE_ADDRESS  0x40011000UL

/*****************************************************/
/*****************************************************/

/***************	MUSART1 registers	***************/
typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USART1_t;
/*****************************************************/
/*****************************************************/

/***************	MUSART1 registers ADRRESS		***************/
#define MUSART1 ((volatile USART1_t*)(MUSART1_BASE_ADDRESS))

/*****************************************************/
/*****************************************************/
#endif /* MUART_MUART_REGISTER_H_ */
