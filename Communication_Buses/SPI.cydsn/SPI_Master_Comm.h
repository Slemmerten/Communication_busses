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
#include "project.h"

extern volatile const uint8_t turnON; //Byte for turning on the led
extern volatile const uint8_t turnOFF; //Byte for turning off the led
extern volatile const uint8_t requestStatus; //Byte for requesting the status of the led

//Turns on the led on the SPI slave
void turnOnLed();

//Turns off the led on the SPI slave
void turnOffLed();

//Gets the status of the led on the SPI slave
uint8_t getLedStatus();
/* [] END OF FILE */
