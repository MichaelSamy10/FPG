#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "HAL/LCD/LCD_interface.h"

int main()
{
	/* Init System Clock  */
	MRCC_voidInitializeSystemClock();
	/* Enable PORTA Clock */
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	/* Init Systick*/
	MSTK_voidIntialize();

	MGPIO_voidSetPinMode(MGPIO_u8PORTA,0,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,1,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,2,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,4,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,5,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,6,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA,7,MGPIO_u8OUTPUT);

	CLCD_voidInit();
	CLCD_voidMoveCursor(0,7);
	CLCD_voidSendString("FPG");
	CLCD_voidMoveCursor(1,5);
	CLCD_voidSendString("PROJECT");

	while(1)
	{

	}

}
