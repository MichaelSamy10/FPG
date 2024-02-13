#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "HAL/LCD/LCD_interface.h"
//#include "MCAL/MTIM2_5/MTIM2_5_interface.h"
#include "HAL/DCMOTOR/DCMOTOR_interface.h"

int main()
{
<<<<<<< HEAD

	/* Init System Clock  */
	MRCC_voidInitializeSystemClock();
	/* Enable PORTA Clock */
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOA_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);

	DCMOTOR_voidInit();
	DCMOTOR_voidSetSpeed(DCMOTOR_1,2000,1500);
	DCMOTOR_voidSetSpeed(DCMOTOR_2,2000,1500);

	DCMOTOR_voidSetDirection(DCMOTOR_1,DCMOTOR_FORWARD_DIRECTION);
	DCMOTOR_voidSetDirection(DCMOTOR_2,DCMOTOR_BACKWARD_DIRECTION);

	/* Init Systick*/
	MSTK_voidIntialize();


	//MGPIO_voidSetPinMode(MGPIO_u8PORTA,2,MGPIO_u8OUTPUT);
	//MGPIO_voidSetPinMode(MGPIO_u8PORTA,4,MGPIO_u8OUTPUT);
	//MGPIO_voidSetPinMode(MGPIO_u8PORTA,5,MGPIO_u8OUTPUT);
	//MGPIO_voidSetPinMode(MGPIO_u8PORTA,6,MGPIO_u8OUTPUT);
	//MGPIO_voidSetPinMode(MGPIO_u8PORTA,7,MGPIO_u8OUTPUT);

	//CLCD_voidInit();
	//CLCD_voidMoveCursor(0,7);
	//CLCD_voidSendString("FPG");
	//CLCD_voidMoveCursor(1,5);
	//CLCD_voidSendString("PROJECT");






=======
	/* Edit Timer */
>>>>>>> branch 'musherif' of https://github.com/MichaelSamy10/FPG/
	while(1)
	{

	}

}
