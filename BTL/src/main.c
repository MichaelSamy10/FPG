/********************************INCLUDES**********************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "MCAL/MIWD/IWDG_interface.h"
#include "MCAL/MWWDG/WWDG_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/Mflash/FLASH_Interface.h"
#include "SERVICE/APARSER/PARSING_interface.h"

/***************************************************************************/
/********************************GLOBAL VARIABLES**************************/

u8 u8_TimeoutFlag = 0;
u8 RecieveBuffer[100];
u16 data;
u8 u8RecCounter = 0;
u8 u8WriteReq = 1;
u8 TransferFlag = 0;
u8 x=0;
//FLAGS
u16 Update = '0';
u16 No_update = '1';
u16 Corruption = '2';
//Check Sum
u8 Check_s32Sum = 0;
u32 Check_s32Counter = 1;
u8 BOOT_u8Digit0;
u8 BOOT_u8Digit1;
u8 BOOT_u8Data;
u8 Check_sum_Validation;


/*************************************************************************/
/********************************DEFINES********************************/
#define BOOT_u8REQUESTFLAG					0x08008000
#define READ_REQUEST_FLAG					(*((volatile u16*)0x08008000))
#define SCB_VTOR	                        (*((volatile u32*)0xE000ED08))

/************************************************************************/
/*******************************GLOBAL FUNCTIONS************************/
void jump(void);
void APP1(void);
void APP2(void);

typedef void (*Application)(void);

/*Pointer point to the Application Location */
Application AddrAPP1;
Application AddrAPP2;

void APP2(void) {
	CLCD_voidClearDisplay();
			CLCD_voidMoveCursor(0, 0);
			CLCD_voidSendString("Corruption occurred ");
	SCB_VTOR = 0x0800C000;
	AddrAPP1 = *((Application*) 0x0800C004);
	AddrAPP1();

}
void APP1(void) {
	CLCD_voidClearDisplay();
	CLCD_voidSendString("welcome to fpg");
	SCB_VTOR = 0x08020000;
	AddrAPP2 = *((Application*) 0x08020004);
	AddrAPP2();
}

/************************************************************************/
int main(void) {

	u8 L_u8RecStatus = ENOK;
	/*Initialize RCC*/
	MRCC_voidInitializeSystemClock();
	/*Initialize GPIOB*/
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, MRCC_GPIOB_EN);
	/*Initialize WATCHDOG*/
	MRCC_voidEnablePeripheralClock(MRCC_APB1, 11);
	/*Initialize GPIOA*/
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, MRCC_GPIOA_EN);
	/*Initialize USART*/
	MRCC_voidEnablePeripheralClock(MRCC_APB2, MRCC_USART1_EN);
	MUSART_voidInit();

	/*Initialize SYSTICK*/

	/*Initialize FLASH DRIVER*/
	MRCC_voidEnablePeripheralClock(MRCC_AHB1LP, MRCC_FLITFLP_EN);
	//LCD PINS
	MGPIO_voidSetPinMode(MGPIO_u8PORTB, 0, MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB, 1, MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB, 2, MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB, 4, MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB, 5, MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB, 6, MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB, 7, MGPIO_u8OUTPUT);
	//button pins
	MGPIO_voidSetPinMode(MGPIO_u8PORTA, 0, MGPIO_u8INPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA, 1, MGPIO_u8INPUT);
	MGPIO_voidSetPullType(MGPIO_u8PORTA, 1, MGPIO_u8PullUP);
	MGPIO_voidSetPullType(MGPIO_u8PORTA, 0, MGPIO_u8PullUP);
	//uart pins
	MGPIO_voidSetPinMode(MGPIO_u8PORTA, 9, MGPIO_u8ALTFUNC);
	MGPIO_voidSetPinMode(MGPIO_u8PORTA, 10, MGPIO_u8ALTFUNC);
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA, 9, GPIO_u8AF7);
	MGPIO_voidSetAltFunc(MGPIO_u8PORTA, 10, GPIO_u8AF7);
	//synchronising with raspberry with sending r and waiting for r
	CLCD_voidInit();
	CLCD_voidClearDisplay();
	CLCD_voidSendString("Searching for ");
	CLCD_voidMoveCursor(1,0);
	CLCD_voidSendString("Update ");
	MSTK_voidIntialize();
	MUSART_voidEnable();
    MSTK_voidSetIntervalSingle(15000000, jump);	//interval 8s
	while( x==0){
	MUSART_voidSendString((u8 *) "R");
	u8 z=MUSART_voidReciveData();
	if(z=='R'){
		x=1;
		MSTK_voidStopTimer();
	}
	}
   //raspberry sends a flag according to update if it exists
	data = MUSART_voidReciveData();
		data-'0';
	MFDI_voidEraseSector(2);
	MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &data, 1);

   //from the flag it jumps
	if (READ_REQUEST_FLAG == '0') {
		MUSART_voidSendString((u8 *) "R");
		CLCD_voidClearDisplay();
			CLCD_voidSendString("Updating ....");

		while (u8_TimeoutFlag == 0) {
			L_u8RecStatus = MUSART_voidRecieveAsynchronous1(&RecieveBuffer[u8RecCounter]);
			if (L_u8RecStatus == EOK) {

				MSTK_voidStopTimer();
				//check end of file
				if (RecieveBuffer[u8RecCounter] == '\n') {
/****************************Erase APPLICATION 1 **************************************/
					if (u8WriteReq == 1) {
						MFDI_voidEraseSector(FLASH_SECTOR_FIVE);
						u8WriteReq = 0;
					}
/***********************************Check SUM ****************************************/

					Check_s32Sum = 0;
					Check_s32Counter = 1;

					while (Check_s32Counter < u8RecCounter - 2) {
						BOOT_u8Digit0 = PARSING_u8AsciToHex(
								RecieveBuffer[Check_s32Counter]);

						BOOT_u8Digit1 = PARSING_u8AsciToHex(
								RecieveBuffer[Check_s32Counter + 1]);

						BOOT_u8Data = (BOOT_u8Digit0 << 4) | (BOOT_u8Digit1);

						Check_s32Sum = Check_s32Sum + BOOT_u8Data;

						Check_s32Counter = Check_s32Counter + 2;

					}
					Check_s32Sum = ~(Check_s32Sum - 1);

					// Validation
					BOOT_u8Digit0 = PARSING_u8AsciToHex(
							RecieveBuffer[u8RecCounter - 2]);

					BOOT_u8Digit1 = PARSING_u8AsciToHex(
							RecieveBuffer[u8RecCounter - 1]);

					Check_sum_Validation = (BOOT_u8Digit0 << 4)
							| (BOOT_u8Digit1);

					if (Check_s32Sum != Check_sum_Validation) {
						//Data Corruption
						MGPIO_voidSetPinValue(MGPIO_u8PORTA, 4, MGPIO_u8HIGH);
						MFDI_voidEraseSector(2);
						MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &Corruption, 1);
						//WWDG_voidReset(10);
						WWDG_voidReset(100);
					}

					PARSING_voidWriteData(RecieveBuffer);


					u8RecCounter = 0;

					if (RecieveBuffer[8] == '1') {
                      MUSART_voidSendString((u8 *) "NOK");
						//MFDI_voidEraseAppArea(FLASH_SECTOR_THREE,FLASH_SECTOR_FOUR);
						//MFDI_voidMoveData(FLASH_SECTOR_FIVE_ADDRESS,FLASH_SECTOR_THREE_ADDRESS,(11*1024));
                      CLCD_voidInit();
                      	CLCD_voidClearDisplay();
                      	CLCD_voidSendString("Update is done");
						MFDI_voidEraseSector(2);
						MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &No_update, 1);
						WWDG_voidReset(100);
					}
					else{
						MUSART_voidSendString((u8 *) "OK");
					}
				} else {
					u8RecCounter++;
				}

			}

		}
	} else if (READ_REQUEST_FLAG == '1') {
		APP1();
	}

	else if (READ_REQUEST_FLAG == '2') {

		APP2();
	} else if (READ_REQUEST_FLAG == '3') {
		MSTK_voidStopTimer();
		CLCD_voidInit();
		CLCD_voidClearDisplay();
		CLCD_voidMoveCursor(0, 0);
		CLCD_voidSendString("update now ?");
		CLCD_voidMoveCursor(1, 0);
		CLCD_voidSendString("Yes        Later");
		while (1) {
			if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 0) == 0) {
				MSTK_voidSetBusyWait(16000);
				if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 0) == 0) {
					MFDI_voidEraseSector(2);
					MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &Update, 1);
					CLCD_voidClearDisplay();
					CLCD_voidMoveCursor(1, 1);
					CLCD_voidSendString("Updating...");
					WWDG_voidReset(100);
				}
			}
			if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 1) == 0) {
				MSTK_voidSetBusyWait(16000);
				if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 1) == 0) {
					MFDI_voidEraseSector(2);
					MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &No_update, 1);
					CLCD_voidClearDisplay();
					CLCD_voidMoveCursor(1, 1);
					CLCD_voidSendString("Update later.");
					MUSART_voidSendString((u8 *) "NO");
					// Your code here to handle updating later
					APP1();

				}
			}

		}

	}

	return 0;
}
void jump(void){
	MSTK_voidStopTimer();
	if(READ_REQUEST_FLAG == '1'){
		APP1();
	}
	else if(READ_REQUEST_FLAG == '2'){
		APP2();
	}
	else if(READ_REQUEST_FLAG == '3'){

		CLCD_voidInit();
				CLCD_voidClearDisplay();
				CLCD_voidMoveCursor(0, 0);
				CLCD_voidSendString("update now ?");
				CLCD_voidMoveCursor(1, 0);
				CLCD_voidSendString("Yes        Later");
				while (1) {
					if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 0) == 0) {
						MSTK_voidSetBusyWait(16000);
						if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 0) == 0) {
							MFDI_voidEraseSector(2);
							MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &Update, 1);
							CLCD_voidClearDisplay();
							CLCD_voidMoveCursor(1, 1);
							CLCD_voidSendString("Updating...");
							WWDG_voidReset(100);
						}
					}
					if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 1) == 0) {
						MSTK_voidSetBusyWait(16000);
						if (MGPIO_u8GetPinValue(MGPIO_u8PORTA, 1) == 0) {
							MFDI_voidEraseSector(2);
							MFDI_voidFlashWrite(BOOT_u8REQUESTFLAG, &No_update, 1);
							CLCD_voidClearDisplay();
							CLCD_voidMoveCursor(1, 1);
							CLCD_voidSendString("Update later.");
							MUSART_voidSendString((u8 *) "NO");
							// Your code here to handle updating later
							//break;// Exit the loop after the action is performed
							//WWDG_voidReset(100);
							APP1();

	}
	}
				}
	}
}

