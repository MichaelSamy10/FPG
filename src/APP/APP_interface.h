/*
 * APP_interface.h
 *
 *  Created on: Mar 9, 2024
 *      Author: BROTHERS
 */

#ifndef APP_APP_INTERFACE_H_
#define APP_APP_INTERFACE_H_

#define FORWARD				0
#define BACKWARD			1
#define LEFT				2
#define RIGHT				3
#define FORWARD_RIGHT		4
#define FORWARD_LEFT		5
#define BACKWARD_RIGHT		6
#define BACKWARD_LEFT		7



void Car_Control();

void LD_IRsenseRight(void);
void LD_IRsenseLeft(void);
/**/

void Obstacle_SenseBack(void);
void Obstacle_SenseForward(void);

void AutoParking(void);

void Move_Car_To(u8 Copy_u8Direction);

#endif /* APP_APP_INTERFACE_H_ */
