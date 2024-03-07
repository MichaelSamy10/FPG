/*
 * LDIR_program.c
 *
 *  Created on: Mar 7, 2024
 *      Author: MICHAEL
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/MGPIO/MGPIO_interface.h"



void LDIR_voidInit(void)
{

		MGPIO_voidSetPinMode(MGPIO_u8PORTA,1,MGPIO_u8INPUT);
		MGPIO_voidSetPullType(MGPIO_u8PORTA,1,MGPIO_u8PullUP);


}
