#ifndef FLASH_FLASH_REGISTER_H_
#define FLASH_FLASH_REGISTER_H_

#define FLASH_BASE_ADDRESS   0x40023C00


typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 OPTCR;
}FDI_t;

#define MFDI     ((volatile FDI_t*)(FLASH_BASE_ADDRESS))
#define MFDI_KEY1  0x45670123
#define MFDI_KEY2  0xCDEF89AB

#define WRITE_HALF_WORD   1


#endif /* FLASH_FLASH_REGISTER_H_ */
