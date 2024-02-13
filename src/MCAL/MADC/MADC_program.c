/*
 * MADC_program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: OMAR PC
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MADC_interface.h"
#include "MADC_config.h"
#include "MADC_register.h"



void MADC_voidEnable(void)
{


	/*Enable Continous Mode*/
	SET_BIT(ADC->CR2,1);
	/*Resolution  12 bit */
	SET_BIT(ADC->CR1,24);
	SET_BIT(ADC->CR1,25);
	/*Select Right Ali*/
	SET_BIT(ADC->CR2,11);

	/*Select Channel 0,1*/
	ADC->SQR3=0b00000|(0b00001<<5);

	/*Enable ADC*/
	SET_BIT(ADC->CR2,0);

}
u16 MADC_u16Read(u8 Copy_u8Channel)
{
	ADC->SQR3=(Copy_u8Channel<<0b00000);

	/*Start Convertion*/
	SET_BIT(ADC->CR2,30);

	while((GET_BIT(ADC->SR,1))==0);

	return ADC->DR;

}
