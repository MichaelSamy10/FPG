#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "MRCC_interface.h"
#include "MUART_interface.h"
#include "MFDI_interface.h"
#include "WWDG_interface.h"
#include "PARSING_interface.h"

#define BOOT_u8REQUESTFLAG					0x08008000
#define READ_REQUEST_FLAG					(*((volatile u16*)0x08008000))
#define SCB_VTOR   							(*((volatile u32*)0xE000ED08))

void APP1(void);
void APP2(void);

typedef void (*Application)(void);

Application AddrAPP1;
Application AddrAPP2;

void main(void) {
	/* System clock init for 16MHz from HSI */
	MRCC_voidInitializeSystemClock();
	/* Enable GPIOA Peripheral */
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, MRCC_GPIOA_EN);
	/* Enable USART Peripheral */
	MRCC_voidEnablePeripheralClock(MRCC_APB2, MRCC_USART1_EN);
	/* Enable FDI Peripheral */
	MRCC_voidEnablePeripheralClock(MRCC_AHB1LP, MRCC_FLITFLP_EN);
	/* Set USART pins as Alternative functions */
	MGPIO_voidSetPinMode(MGPIO_u8PORTA, GPIO_u8AF9, MGPIO_u8ALTFUNC);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA, GPIO_u8AF10, MGPIO_u8ALTFUNC);
	/* Set USART pins as Alternative functions */
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA, GPIO_u8AF9, 7);
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA, GPIO_u8AF10, 7);
	/* Init USART */
	MUSART_voidInit();

    /*FLAGS*/
	u16 Update = 0;
	u16 No_update = 1;
	u16 Corruption = 2;

	// Array of Data
	u8 BOOT_u8RecData[100];

	// Flag to first in bootloader
	u8 BOOT_u8FinRecFlag = 0;

	//index of Data
	u32 BOOT_u32RecCounter = 0;

	//index of Erase pages
	u32 BOOT_u32EraseCounter = 0;

	//Check Sum
	u8 Check_s32Sum = 0;
	u32 Check_s32Counter = 1;
	u8 BOOT_u8Digit0;
	u8 BOOT_u8Digit1;
	u8 BOOT_u8Data;
	u8 Check_sum_Validation;

	// flag to start and end Erase operation
	u32 BOOT_u32EraseFlag = 1;

	if (READ_REQUEST_FLAG == 0) {

		while (BOOT_u8FinRecFlag == 0) {

			BOOT_u8RecData[BOOT_u32RecCounter] =
					MUSART_voidRecieveAsynchronous();
			if (BOOT_u8RecData[BOOT_u32RecCounter] == '\n') {
				if (BOOT_u32EraseFlag == 1) {
					for (BOOT_u32EraseCounter = 3; BOOT_u32EraseCounter < 5;
							BOOT_u32EraseCounter++) {
						MFDI_voiSectordErase(BOOT_u32EraseCounter);
					}
					BOOT_u32EraseFlag = 0;
				}

				Check_s32Sum = 0;
				Check_s32Counter = 1;

				while (Check_s32Counter < BOOT_u32RecCounter - 2) {
					BOOT_u8Digit0 = PARSING_u8AsciToHex(
							BOOT_u8RecData[Check_s32Counter]);

					BOOT_u8Digit1 = PARSING_u8AsciToHex(
							BOOT_u8RecData[Check_s32Counter + 1]);

					BOOT_u8Data = (BOOT_u8Digit0 << 4) | (BOOT_u8Digit1);

					Check_s32Sum = Check_s32Sum + BOOT_u8Data;

					Check_s32Counter = Check_s32Counter + 2;

				}
				Check_s32Sum = ~(Check_s32Sum - 1);

				// Validation
				BOOT_u8Digit0 = PARSING_u8AsciToHex(
						BOOT_u8RecData[BOOT_u32RecCounter - 2]);

				BOOT_u8Digit1 = PARSING_u8AsciToHex(
						BOOT_u8RecData[BOOT_u32RecCounter - 1]);

				Check_sum_Validation = (BOOT_u8Digit0 << 4) | (BOOT_u8Digit1);

				if (Check_s32Sum != Check_sum_Validation) {
					//Data Corruption
					MGPIO_voidSetPinValue(MGPIO_u8PORTA, 4, MGPIO_u8HIGH);
					MFDI_voiSectordErase(2);
					MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &Corruption, 1);
					WWDG_voidReset(10);
				}
				PARSING_voidWriteData(BOOT_u8RecData);

				MUSART_voidSendString((u8*) "ok");
				BOOT_u32RecCounter = 0;

				if (BOOT_u8RecData[8] == '1') {
					MFDI_voiSectordErase(2);
					MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &No_update, 1);
					WWDG_voidReset(10);
				}

			} else {
				BOOT_u32RecCounter++;
			}

		}

	}

	else if (READ_REQUEST_FLAG == 1) {
		APP1();
	}

	else {

		APP2();
	}

}

void APP1(void) {

	SCB_VTOR = 0x0800C00;
	AddrAPP1 = *((Application*) 0x0800C004);
	AddrAPP1();

}
void APP2(void) {
	SCB_VTOR = 0x08020000;

	AddrAPP2 = *((Application*) 0x08020004);
	AddrAPP2();
}
