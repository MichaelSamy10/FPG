/*
 * I2C_register.h
 *
 *  Created on: Feb 14, 2024
 *      Author: Maghraby Store
 */

#ifndef HAL_I2C_I2C_REGISTER_H_
#define HAL_I2C_I2C_REGISTER_H_

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
u32 TRISE ;
u32 FLTR;


}I2C_t;

#define I2C            ((volatile I2C_t *)(I2C_BASE_ADDRESS))







#endif /* HAL_I2C_I2C_REGISTER_H_ */
