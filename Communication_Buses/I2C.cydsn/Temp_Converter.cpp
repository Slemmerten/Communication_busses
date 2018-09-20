#include "Temp_Converter.h"



int8_t twosComplement(uint8_t val)
{
	uint8_t mask = (1<<7);

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
	float pointval = 0;
	float temperature = twosComplement(msb);
	if (lsb & 1<<7)
	{
		pointval = 0.5;
	}
	temperature += pointval;
	printf("%.1f\n", temperature);
	return temperature;
}