/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Mohamed Gad
 *
 *******************************************************************************/


#include "dc_motor.h"
#include "gpio.h"
#include "avr/io.h"
#include "timer_pwm.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_init(void)
{
/*
 * Setup the following pins of DC motor Input1 , Input2 , Enable as outputs
 */
	GPIO_setupPinDirection(DC_MOTOR_INPUT1_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_INPUT2_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_ENABLE_PORT_ID,DC_MOTOR_ENABLE_PIN_ID,PIN_OUTPUT);

	/*
	 * Initialize the motor with logic low (STOP)
	 */

	GPIO_writePin(DC_MOTOR_INPUT1_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_INPUT2_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);

}


void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	uint8 duty_cycle=((float)speed/100)*255;  // Converting the duty cycle into value from 0-100
	PWM_Timer0_Start(duty_cycle);

    switch(state)
    {
    case STOP:
    	GPIO_writePin(DC_MOTOR_INPUT1_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
    	GPIO_writePin(DC_MOTOR_INPUT2_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
    	break;

    case CW:
    	GPIO_writePin(DC_MOTOR_INPUT1_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_HIGH);
    	GPIO_writePin(DC_MOTOR_INPUT2_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
    	break;

    case A_CW:
    	GPIO_writePin(DC_MOTOR_INPUT1_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
    	GPIO_writePin(DC_MOTOR_INPUT2_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_HIGH);
    	break;


    }


}





