

#include "avr/io.h"
#include<avr/io.h>
#include"lcd.h"
#include"gpio.h"
#include"timer_pwm.h"
#include"dc_motor.h"
#include "lm35_sensor.h"
#include"adc.h"
#include<util/delay.h>


typedef enum
{
	OFF,
	ON
}FAN_MODE;


int main (void)
{
	uint8 temp=0;
	FAN_MODE FAN_State;

	LCD_init();
	DcMotor_init();

	ADC_ConfigType ADC_Config ={AREF,F_adc_8};
	ADC_init(&ADC_Config);


	temp = LM35_getTemperature();

	_delay_ms(300);

	while (1)
	{
		temp = LM35_getTemperature();

		if(temp<30)
		{
			FAN_State = OFF;
			DcMotor_Rotate(STOP,0);

			LCD_displayStringRowColumn(0,4,"Fan is OFF");

			LCD_displayStringRowColumn(1,4," Temp =   ");

			LCD_moveCursor(1,12);

			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');

			}


		}

		else if(temp>=30 && temp<60)
		{
			FAN_State = ON;

			DcMotor_Rotate(CW,25);

			LCD_displayStringRowColumn(0,4,"Fan is ON  ");

			LCD_displayStringRowColumn(1,4," Temp =   ");

			LCD_moveCursor(1,12);

			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');

			}


		}


		else if(temp>=60 && temp<90)
		{
			FAN_State = ON;
			DcMotor_Rotate(CW,50);

			LCD_displayStringRowColumn(0,4,"Fan is ON  ");

			LCD_displayStringRowColumn(1,4," Temp =   ");

			LCD_moveCursor(1,12);

			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');

			}


		}


		else if(temp>=90 && temp<120)
		{
			FAN_State = ON;
			DcMotor_Rotate(CW,75);

			LCD_displayStringRowColumn(0,4,"Fan is ON  ");

			LCD_displayStringRowColumn(1,4," Temp =   ");

			LCD_moveCursor(1,12);

			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');

			}


		}

		else if (temp>=120)
		{
			FAN_State = ON;
			DcMotor_Rotate(CW,100);

			LCD_displayStringRowColumn(0,4,"Fan is ON  ");

			LCD_displayStringRowColumn(1,4," Temp =   ");

			LCD_moveCursor(1,12);

			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');

			}


		}



	}
}


