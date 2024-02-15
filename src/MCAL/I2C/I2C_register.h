/*
 * I2C_register.h
 *
 *  Created on: Feb 14, 2024
 *      Author: Maghraby Store
 */

#ifndef HAL_I2C_I2C_REGISTER_H_
#define HAL_I2C_I2C_REGISTER_H_

/*
 * I2C_register.h
 *
 *  Created on: Feb 14, 2024
 *      Author: Maghraby Store
 */

#ifndef HAL_I2C_I2C_REGISTER_H_
#define HAL_I2C_I2C_REGISTER_H_


/*#define I2C_CR1    *((volatile (u8*))(0x00)
#define I2C_CR2    *((volatile (u8*))(0x04)
#define I2C_OAR1   *((volatile (u8*))(0x08)
#define I2C_OAR2   *((volatile (u8*))(0x0C)
#define I2C_DR     *((volatile (u8*))(0x10)
#define I2C_SR1    *((volatile (u8*))(0x14)
#define I2C_SR2    *((volatile (u8*))(0x18)
#define I2C_CCR    *((volatile (u8*))(0x1C)
#define I2C_FLTR   *((volatile (u8*))(0x20)
#define I2C_TRISE   *((volatile (u8*))(0x2C)*/











#endif /* HAL_I2C_I2C_REGISTER_H_ */


#define I2C_BASE_ADDRESS             0x40005400

typedef struct {

u32 CR1  ;
u32 CR2  ;
u32 OAR1 ;
u32 OAR2 ;
u32 DR   ;
u32 SR1  ;
u32 SR2  ;
u32 CCR  ;
u32 FLTR ;
u32 TRISE;


}I2C_t;

#define I2C            ((volatile I2C_t *)(I2C_BASE_ADDRESS))



#endif /* HAL_I2C_I2C_REGISTER_H_ */
