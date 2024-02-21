/*
 * MDFI_Program.c
 *
 *  Created on: Jan 29, 2024
 *      Author: hp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MFDI_Interface.h"
#include "MFDI_Private.h"
#include "MFDI_Config.h"
#include "MFDI_Register.h"


void MFDI_voidEraseAppArea(void)
{
	for(u8 L_u8Iterator =1 ; L_u8Iterator<6; L_u8Iterator++ )
	{
		MFDI_voiSectordErase(L_u8Iterator);
	}
}

void MFDI_voiSectordErase(u8 A_u8SectorNum)
{
	if(A_u8SectorNum < 6)
	{
		/* wait the busy flag   1: means write or read */
		while(GET_BIT(MFDI -> SR, 16) == 1);

		/*Check the lick if not unlock*/
		if(GET_BIT(MFDI -> CR, 31) == 1)
		{
			MFDI -> KEYR = MFDI_KEY1;
			MFDI -> KEYR = MFDI_KEY2;
		}

		MFDI->CR &= 0xFFFFFF87;

		/* Set Number of Sector*/
		MFDI -> CR |= A_u8SectorNum<<3;

		/*Set sector Erase*/
		SET_BIT(MFDI-> CR, 1);

		/*Set start bit*/
		SET_BIT(MFDI->CR,16);

		/*wait the busy flag*/
		while(GET_BIT(MFDI -> SR, 16) == 1);

		/*set EOP bit*/
		SET_BIT(MFDI->SR , 0);

		/*clear sector*/
		CLR_BIT(MFDI->CR , 1);

	}
}

void MFDI_voidFlashWrite(u32 A_u32Address, u16* A_u8PtrData, u8 A_u8Len)
{
	/*wait the busy flag*/
	while(GET_BIT(MFDI->SR, 16) == 1);

	/*Check the lick if not unlock*/
	if(GET_BIT(MFDI->CR , 31)==1)
	{
		MFDI->KEYR = MFDI_KEY1;
		MFDI->KEYR = MFDI_KEY2;
	}

	/*Set size --> half word*/
	MFDI->CR &= 0xFFFCFF;
	MFDI->CR |= WRITE_OPERATION <<8;

	for(u8 L_u8Iterator = 0; L_u8Iterator<A_u8Len; L_u8Iterator++)
	{
		/*Set PG*/
		SET_BIT(MFDI->CR , 0);

		*((volatile u16*)A_u32Address) = A_u8PtrData[L_u8Iterator];
		A_u32Address+=2;

		/*wait the busy flag*/
		while(GET_BIT(MFDI->SR , 16) ==1);

		/*Set EOP BIT*/
		SET_BIT(MFDI->SR , 0);

		/*Clear PG*/
		CLR_BIT(MFDI->CR , 0);

	}

}
