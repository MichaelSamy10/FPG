/*
Author		: Muhammed Sherif Attia
date		: 21/2/2024
version		: 1.0.0
description : MUSART2_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/

#ifndef MUART_MUART_REGISTER_H_
#define MUART_MUART_REGISTER_H_
/*****************************************************/
/*****************************************************/

/***************	MUSART2 BaseAddress		***************/
#define MUSART2_BASE_ADDRESS  0x40004400

/*****************************************************/
/*****************************************************/

/***************	MUSART2 registers	***************/
typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USART2_t;

/*****************************************************/
/*****************************************************/
/***************	MUSART2 registers ADRRESS		***************/
#define MUSART2 ((volatile USART2_t*)(MUSART2_BASE_ADDRESS))

/*****************************************************/
/*****************************************************/
#endif /* MUART_MUART_REGISTER_H_ */
