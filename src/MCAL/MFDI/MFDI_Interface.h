/*
 * MFDI_Interface.h
 *
 *  Created on: Jan 29, 2024
 *      Author: hp
 */

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

void MFDI_voidEraseAppArea(void);

void MFDI_voiSectordErase(u8 A_u8SectorNum);

void MFDI_voidFlashWrite(u32 A_u32Address, u16* A_u8PtrData, u8 A_u8Len);

#endif /* MFDI_INTERFACE_H_ */
