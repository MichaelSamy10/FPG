/*
 * Ultrasonic_config.h
 *
 *  Created on: Feb 19, 2024
 *      Author: MICHAEL
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_
#define HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_


#define TRIG_PORT 			MGPIO_u8PORTA
#define TRIG_PIN  			6

#define ECHO_PORT 			MGPIO_u8PORTA
#define ECHO_PIN  			7

#define US_TIMER_CHANNEL	MTIM1_CH1

#endif /* HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_ */
