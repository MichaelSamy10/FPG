/*
Author		: Muhammed Sherif Attia
date		: 17/2/2024
version		: 1.0.0
description : MTIM2_5_config.h -> pre build config File
peri		: for the developer in MCAL only not for the user
*/
#ifndef MTIM2_5_MTIM2_5_CONFIG_H_
#define MTIM2_5_MTIM2_5_CONFIG_H_
/*
 * COUNNTER/TIMER mode
 * options->
 * 			1- MTIM_CUP
 * 	**		2- MTIM_CDOWN
 */
#define 	 MTIM2_CMODE	MTIM_CUP
#define 	 MTIM3_CMODE	MTIM_CUP
#define		 MTIM4_CMODE	MTIM_CUP
#define 	 MTIM5_CMODE	MTIM_CUP

/**********************************************/
#define TIM2_PRESCALER    0
#define TIM3_PRESCALER    0
#define TIM4_PRESCALER    16
#define TIM5_PRESCALER    0
#endif /* MTIM2_5_MTIM2_5_CONFIG_H_ */
