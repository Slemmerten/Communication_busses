#pragma once
#include <stdint.h>
#include <stdio.h>
#include <math.h>

//Helper function that returns twos complement of an 8bit unsigned integer
int8_t twosComplement(uint8_t val);

//Returns the formatted temperature from a LM75 standard
float temperatureConverter(uint8_t msb, uint8_t lsb);

