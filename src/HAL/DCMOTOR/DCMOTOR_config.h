/*
 * DCMOTOR_config.h
 *
 *  Created on: Feb 13, 2024
 *      Author: MICHAEL
 */

#ifndef HAL_DCMOTOR_DCMOTOR_CONFIG_H_
#define HAL_DCMOTOR_DCMOTOR_CONFIG_H_


/* PWM Port and pin */
#define TIMER3_CH1_PORT				MGPIO_u8PORTA
#define TIMER3_CH1_PIN				6
#define TIMER4_CH1_PORT				MGPIO_u8PORTB
#define TIMER4_CH1_PIN				6

/* Direction Pin Controls for Motor 1 */
#define DCMOTOR1_CONTROL_PORT		MGPIO_u8PORTB
#define DCMOTOR1_CONTROL_PIN0		0
#define DCMOTOR1_CONTROL_PIN1		1

/* Direction Pin Controls for Motor 2 */
#define DCMOTOR2_CONTROL_PORT		MGPIO_u8PORTB
#define DCMOTOR2_CONTROL_PIN0		2
#define DCMOTOR2_CONTROL_PIN1		3

/* Motor PWM */
#define MOTOR1_PWM_TIMER			MTIM_3
#define MOTOR1_PWM_CHANNEL			MTIM2_5_ch1
#define MOTOR2_PWM_TIMER			MTIM_4
#define MOTOR2_PWM_CHANNEL			MTIM2_5_ch1



#endif /* HAL_DCMOTOR_DCMOTOR_CONFIG_H_ */
