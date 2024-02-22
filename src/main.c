
#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"
#include"MCAL/MRCC/MRCC_interface.h"
#include"MCAL/MGPIO/MGPIO_interface.h"
#include"MCAL/I2C/I2C_interface.h"


int main (void){

	//LCD_voidInit();
	unsigned char x;

	I2C_Master_init(1600000);

	I2C_start(); // transmit start condition
	I2C_write_address(0b10100000); // transmit device address and Write
	I2C_write_data(0b00000000); // transmit word address
	I2C_write_data(0x32); // transmit data
	I2C_stop(); // transmit stop condition

	/*read from the location 0b00000000000*/

	I2C_start(); // transmit start condition
	I2C_write_address(0b10100000); // transmit device address and Write
	I2C_write_data(0b00000000); // transmit word address
	//I2C_repeated_start(); // transmit repeated start condition
	I2C_write_address(0b10100001); // transmit device address and read
	//x=I2C_read_with_NACK();
	I2C_stop();
	//LCD_voidSendCharacter(x);

	while(1)
	{

	}
}
