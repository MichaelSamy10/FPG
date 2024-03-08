/*
 * Ultrasonic_config.h
 *
 *  Created on: Feb 19, 2024
 *      Author: MICHAEL
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_
#define HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_


#define TRIG_PORT 			MGPIO_u8PORTB
#define TRIG_PIN  			7

#define ECHO_PORT 			MGPIO_u8PORTB
#define ECHO_PIN  			6

#define US_TIMER			MTIM_4
#define US_TIMER_CHANNEL	MTIM2_5_ch1

#endif /* HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_ */
