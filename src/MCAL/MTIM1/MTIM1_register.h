/*
Author		: Muhammed Sherif Attia
date		: 18/2/2024
version		: 1.0.0
description : MTIM1_register.h -> Register File
peri		: for the developer in MCAL only not for the user
*/
#ifndef MCAL_MTIM1_MTIM1_REGISTER_H_
#define MCAL_MTIM1_MTIM1_REGISTER_H_

#define MTIM1_BASE_ADDRESS		0x40010000

typedef struct{
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RCR;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 BDTR;
	u32 DCR;
	u32 DMAR;
}MTIM1_t;

#define 		MTIM1 			((volatile MTIM1_t*)(MTIM1_BASE_ADDRESS))

#endif /* MCAL_MTIM1_MTIM1_REGISTER_H_ */
