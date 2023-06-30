/******************************************************************************
 *
 * Module: PWM Driver
 *
 * File Name: timer_pwm.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Mohamed Gad
 *
 *******************************************************************************/



#include "common_macros.h"
#include "gpio.h"
#include "avr/io.h"
#include "timer_pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0=0;

	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,CS01);

	OCR0=duty_cycle;
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

}
