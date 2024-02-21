/*
 * MUART_interface.h
 *
 *  Created on: Jan 24, 2024
 *      Author: BROTHERS
 */

#ifndef MUART_MUART_INTERFACE_H_
#define MUART_MUART_INTERFACE_H_

void MUSART2_voidInit(void);

void MUSART2_voidSendData(u8 Copy_u8Data);
u8 MUSART2_voidReciveData(void);

u8 MUSART2_voidRecieveAsynchronous(void);

void MUSART2_voidEnable(void);

void MUSART2_voidDisable(void);

void MUSART2_voidSendString(u8 *Copy_pu8Data);

void MUSART2_voidSetCallBack(void(*vp_Fumc)(void));

#endif /* MUART_MUART_INTERFACE_H_ */
