/*
Author		: Muhammed Sherif Attia
date		: 21/2/2024
version		: 1.0.0
description : MUART2_config.h -> PreBuild configurations
peri		: for the developer in MCAL only not for the user
*/

#ifndef MUART2_MUART2_CONFIG_H_
#define MUART2_MUART2_CONFIG_H_


// Baud Rate
// 9600		->(0x00000683)
// 115200 	->(0x0000008B)
// 38400	->(0x000001A1)

#define MUSART2_BAUD_RATE	BAUD_RATE_9600

#endif /* MUART_MUART_CONFIG_H_ */
