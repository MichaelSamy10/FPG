/*
 * I2C_program.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Maghraby Store
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"I2C_interface.h"
#include"../MRCC/MRCC_interface.h"
#include"I2C_register.h"
#include"../MGPIO/MGPIO_interface.h"



u8 temp=0;
u8 value=0;
	void I2C_Master_init(unsigned long SCL_Clock)
	{
		 //join I2C as a master mode
		        MRCC_voidEnablePeripheralClock()  MRCC_APB1ENR |= (1<<21);  // enable I2C CLOCK
		          MRCC_AHB1ENR |= (1<<1);  // Enable GPIOB CLOCK
		          // Configure the I2C PINs for ALternate Functions
		          //PB8 and PB9 are connected to I2C1_SCL and I2C1_SDA
		          MGPIOB_MODER |= (1<<16)|(1<<18);
		          MGPIOB_OTYPER |= ((1<<8) | (1<<9));
		          MGPIOB_OSPEEDR |= ((3<<16) | (3<<18));
		          MGPIOB_PUPDR |= ((1<<16) | (1<<18));
		          MGPIOB_AFRH |= ((4<<0) | (4<<4));
		            // Reset the I2C
		            I2C_CR1 |= (1<<15); //I2C Peripheral under reset state
		            I2C_CR1 &= ~(1<<15); //I2C Peripheral not under reset
		            // Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
		            I2C_CR2 |= (42 <<0);  // PCLK1 FREQUENCY in MHz
		            I2C_CCR |= (210<<0);  // Configure the clock control registers
		            I2C_TRISE = 43;  // Configure the rise time register
		            I2C_CR1 |= (1<<0);  // Enable I2C

	}

	void I2C_start(void)
	{              //Generate a start condition
        I2C_CR1 |= (1<<8);  // Generate START
        while (!(I2C_SR1 & (1<<0)));  // Wait for SB bit to set to 1
}


	void I2C_write_address(unsigned char address)
	{
	    I2C_DR = addr;  //  send the address
	            while (!(I2C_SR1 & (1<<1)));// wait until the address recieved success
	            temp = I2C_SR1 | I2C_SR2; //clear ADDR
	            }

	void I2C_write_data(unsigned char data)
	{

        while (!(I2C_SR1 & (1<<7)));  // wait for TXE bit to set
        I2C_DR = dat   ;  // wait for BTF bit to set
        while (!(I2C_SR1 & (1<<2))); //waiting while BTF=0 but when BTF=1; Data byte transfer succeeded

}}

	void I2C_stop(void)
	{
		 I2C_CR1 |= (1<<9);//stop generation
		            // Wait until the STOP condition is complete
		           while (I2C_SR2 & (1<<0)); //Cleared by hardware after detecting a Stop condition on the bus
		           // Clear the STOP bit
		           I2C_CR1 &= ~(1<<9);
	}




