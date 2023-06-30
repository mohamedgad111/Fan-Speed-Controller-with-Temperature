 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Mohamed Gad
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/* Creating an enum which contain the values taken from data sheet for the value of ADC_Reference Voltage

        */
typedef enum
{
	Aref,
	AVCC,
	AREF=3
}ADC_ReferenceVolatge;

/* Creating an enum which contain the values taken from data sheet for the value of ADC_PreScaler

        */

typedef enum
{
	F_adc_2,
	F_adc_4=2,
	F_adc_8=3,
	F_adc_16=4,
	F_adc_32=5,
	F_adc_64=6,
	F_adc_128=7
}ADC_Prescaler;


/* Creating a configuration structure for ADC  which contain two enums created before

        */

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;


}ADC_ConfigType;





/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
