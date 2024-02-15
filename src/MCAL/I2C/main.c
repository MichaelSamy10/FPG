/*
 * main.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Maghraby Store
 */




#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"MRCC_interface.h"
#include"MGPIO_interface.h"
#include"I2C_interface.h"

int main (void){
	I2C_Master_init();
	    I2C_start();

        I2C_write_address(0x08);
        I2C_write_data(0x01);
        I2C_stop();

}
