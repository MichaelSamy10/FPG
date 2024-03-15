/*
 * BT_program.c
 *
 *  Created on: Mar 9, 2024
 *      Author: MICHAEL
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/MNVIC/MNVIC_interface.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "../../MCAL/MUART6/MUART6_interface.h"
#include "../../APP/APP_interface.h"

#include "BT_interface.h"
#include "BT_config.h"


void BT_voidInit(void)
{
	/* Set UART mode */
	MGPIO_voidSetPinMode(BT_UART_PORT,UART_TX,MGPIO_u8ALTFUNC);
	MGPIO_voidSetPinMode(BT_UART_PORT,UART_RX,MGPIO_u8ALTFUNC);


	MGPIO_voidSetAltFunc(BT_UART_PORT,UART_TX,BT_UART_AF);
	MGPIO_voidSetAltFunc(BT_UART_PORT,UART_RX,BT_UART_AF);

	MNVIC_voidEnableInterrupt(USART6_POS);

	MUSART6_voidInit();

	MUSART6_voidEnable();

	MUSART6_voidEnableInterrupt();

	/*********** Bluetooth Car Control ****************/
	MUSART6_voidSetCallBack(&Car_Control);

}

void BT_voidSendData(u8 Copy_u8Data)
{
	MUSART6_voidSendData(Copy_u8Data);
}





