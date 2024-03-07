/*
 * DCMOTOR_config.h
 *
 *  Created on: Feb 13, 2024
 *      Author: MICHAEL
 */

#ifndef HAL_DCMOTOR_DCMOTOR_CONFIG_H_
#define HAL_DCMOTOR_DCMOTOR_CONFIG_H_


/* PWM Port and pin */
#define MOTOR1_PORT					MGPIO_u8PORTA
#define MOTOR1_PIN					6
#define MOTOR2_PORT					MGPIO_u8PORTB
#define MOTOR2_PIN					6

/* Direction Pin Controls for Motor 1 */
#define MOTOR1_CONTROL_PORT		MGPIO_u8PORTB
#define MOTOR1_CONTROL_PIN0		0
#define MOTOR1_CONTROL_PIN1		1

/* Direction Pin Controls for Motor 2 */
#define MOTOR2_CONTROL_PORT		MGPIO_u8PORTB
#define MOTOR2_CONTROL_PIN0		2
#define MOTOR2_CONTROL_PIN1		3

/* Motor PWM */
#define MOTOR1_PWM_TIMER			MTIM_3
#define MOTOR1_PWM_CHANNEL			MTIM2_5_ch1
#define MOTOR2_PWM_TIMER			MTIM_4
#define MOTOR2_PWM_CHANNEL			MTIM2_5_ch1



#endif /* HAL_DCMOTOR_DCMOTOR_CONFIG_H_ */
