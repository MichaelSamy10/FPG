/*
 * I2C_program.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Maghraby Store
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../MRCC/MRCC_interface.h"
#include"../MGPIO/MGPIO_interface.h"

#include"I2C_interface.h"
#include"I2C_register.h"



u8 temp=0;
u8 value=0;
	void I2C_Master_init(unsigned long SCL_Clock)
	{

		            // Reset the I2C
		            I2C->CR1 |= (1<<15); //I2C Peripheral under reset state
		            I2C->CR1 &= ~(1<<15); //I2C Peripheral not under reset
		            // Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
		            I2C->CR2 |= (42 <<0);  // PCLK1 FREQUENCY in MHz
		            I2C->CCR |= (210<<0);  // Configure the clock control registers
		            I2C->TRISE = 43;  // Configure the rise time register
		            I2C->CR1 |= (1<<0);  // Enable I2C

	}

	void I2C_start(void)

     {              //Generate a start condition
        I2C->CR1 |= (1<<8);  // Generate START
        while (!(I2C->SR1 & (1<<0)));  // Wait for SB bit to set to 1
     }

	/*void I2C_repeated_start(void){
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
				while(READ_BIT(TWCR,TWINT)==0); //wait to finish
				while ((TWSR & 0XF8) != 0x10); // repeated start condition has been transmitted
	}*/
	void I2C_write_address(unsigned char address)

	   {
	    I2C->DR = address;  //  send the address
	            while (!(I2C->SR1 & (1<<1)));// wait until the address recieved success
	            temp = I2C->SR1 | I2C->SR2; //clear ADDR
	   }

	void I2C_write_data(unsigned char data)
	{

        while (!(I2C->SR1 & (1<<7)));  // wait for TXE bit to set
        I2C->DR = data   ;  // wait for BTF bit to set
        while (!(I2C->SR1 & (1<<2))); //waiting while BTF=0 but when BTF=1; Data byte transfer succeeded
	}

	void I2C_stop(void)
	{
		 I2C->CR1 |= (1<<9);//stop generation
		            // Wait until the STOP condition is complete
		           while (I2C->SR2 & (1<<0)); //Cleared by hardware after detecting a Stop condition on the bus
		           // Clear the STOP bit
		           I2C->CR1 &= ~(1<<9);
	}

unsigned char I2C_read_with_NACK(void){
	   u8 receivedData = 0;
	          I2C->CR1 &= ~(1<<10);  // clear the ACK bit
	            temp = I2C->SR1 | I2C->SR2;  // read SR1 and SR2 to clear the ADDR bit.... EV6 condition
	           I2C->CR1 |= (1<<9);  // Stop I2C
	            while (!(I2C->SR1 & (1<<6)));  // wait for RxNE to set
	           receivedData = I2C->DR; // Read the data from the DATA REGISTER
	        return receivedData;


	}




