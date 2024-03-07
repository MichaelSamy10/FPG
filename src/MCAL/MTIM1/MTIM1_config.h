/*
Author		: Muhammed Sherif Attia
date		: 18/2/2024
version		: 1.0.0
description : MTIM1_config.h -> pre build config File
peri		: for the developer in MCAL only not for the user
*/
#ifndef MCAL_MTIM1_MTIM1_CONFIG_H_
#define MCAL_MTIM1_MTIM1_CONFIG_H_

/**********************************************/
/*
 * set the preScaler value for ICU mode->
 *
 */
#define TIM1_ICU_PRESCALER 				15

/*
 * set the ARR value for PWM mode->
 *
 */
#define	TIM1_ICU_ARRval					65535


#endif /* MCAL_MTIM1_MTIM1_CONFIG_H_ */
