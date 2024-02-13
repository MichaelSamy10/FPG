/*
 * MADC_register.h
 *
 *  Created on: Feb 6, 2024
 *      Author: OMAR PC
 */

#ifndef MADC_REGISTER_H_
#define MADC_REGISTER_H_

#define ADC_BASE_ADDRESS       0x40012000


typedef struct
{
	u32 SR;
	u32 CR1;
	u32 CR2;
	u32 SMPR1;
	u32 SMPR2;
	u32 JOFR1;
	u32 JOFR2;
	u32 JOFR3;
	u32 JOFR4;
	u32 HTR;
	u32 LTR;
	u32 SQR1;
	u32 SQR2;
	u32 SQR3;
	u32 JSQR;
	u32 JDR1;
	u32 JDR2;
	u32 JDR3;
	u32 JDR4;
	u32 DR;
	u32 CCR;

}ADC_t;


#define ADC      ((volatile ADC_t *)(ADC_BASE_ADDRESS))

#endif /* MADC_REGISTER_H_ */
