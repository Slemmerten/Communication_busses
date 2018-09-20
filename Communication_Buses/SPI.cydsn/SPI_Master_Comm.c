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
#include "SPI_Master_Comm.h"

volatile const uint8_t turnON = 0b00000001;
volatile const uint8_t turnOFF = 0b00000000;
volatile const uint8_t requestStatus = 0b00000011;

void turnOnLed()
{
    SPIM_1_WriteTxData(turnON); //Write turn on
}

void turnOffLed()
{
    SPIM_1_WriteTxData(turnOFF); //Write turn off
    
}

uint8_t getLedStatus()
{
    SPIM_1_WriteTxData(requestStatus); //Request status of led
    
    for (uint32_t i = 0; i < 8; i++){
         SPIM_1_WriteTxData(0b11111111);
    } //Write 8 times to push the value back to the master
    
    return SPIM_1_ReadRxData(); //return data read
}


/* [] END OF FILE */
