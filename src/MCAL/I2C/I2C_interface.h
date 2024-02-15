/*
 * I2C_interfcae.h
 *
 *  Created on: Feb 14, 2024
 *      Author: Maghraby Store
 */

#ifndef HAL_I2C_I2C_INTERFACE_H_
#define HAL_I2C_I2C_INTERFACE_H_



void I2C_Master_init(unsigned long SCL_Clock);
void I2C_start(void);
void I2C_write_address(unsigned char address);
void I2C_write_data(unsigned char data);
void I2C_stop(void);


// I2C Configuration macros

	// I2C_SCLK_SPEED

#define I2C_SCLK_SPEED_SM	100000
#define I2C_SCLK_SPEED_FM4K	400000
#define I2C_SCLK_SPEED_FM2K	200000
#define I2C_SCLK_SPEED_FM3K	300000

#define I2C_ACK_ENABLE		1
#define I2C_ACK_DISABLE 	0


#define  I2C_ENABLE_SR		ENABLE
#define  I2C_DISABLE_SR		DISABLE

#define I2C_READY	 		0
#define I2C_BUSY_IN_TX 		1
#define I2C_BUSY_IN_RX 		2

#endif /* HAL_I2C_I2C_INTERFACE_H_ */
