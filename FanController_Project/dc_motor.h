/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the ATmega32 ADC driver
 *
 * Author: Mohamed Gad
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#define DC_MOTOR_INPUT1_PORT_ID           PORTB_ID
#define DC_MOTOR_INPUT1_PIN_ID            PIN0_ID

#define DC_MOTOR_INPUT2_PORT_ID           PORTB_ID
#define DC_MOTOR_INPUT2_PIN_ID            PIN1_ID

#define DC_MOTOR_ENABLE_PORT_ID           PORTB_ID
#define DC_MOTOR_ENABLE_PIN_ID            PIN3_ID

#include "std_types.h"


typedef enum
{
	STOP,
	CW,
	A_CW=3
}DcMotor_State;

void DcMotor_init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif










