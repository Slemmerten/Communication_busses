/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "Temp_Converter.h"



int8_t twosComplement(uint8_t val)
{
	uint8_t mask = (1<<7); //Create mask
    
    //Do twos complement
	if (val & mask)
	{
		return (mask | val);
	}
	else
	{
		return (~mask & val);
	}
}

float temperatureConverter(uint8_t msb, uint8_t lsb)
{
	float pointval = 0; //Variable for storing the point value
	float temperature = twosComplement(msb); //Twos complement
	if (lsb & 1<<7)
	{
		pointval = 0.5; //If msb of lower byte of the temperature is 1, set point value = 0.5
	}
	temperature += pointval; //Add the point value
	return temperature; //Return the temperature
}
/* [] END OF FILE */
