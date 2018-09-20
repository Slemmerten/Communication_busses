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
#include "I2C_Comm.h"

void getTemp(uint8_t slaveAddr)
{   
    uint8_t tempMsb, tempLsb = 0; //Variable for storing temperature bytes
    char buf[256]; //Buffer for writing temperature to uart
    int status = I2C_Master_MasterSendStart(slaveAddr, 1); //Read from slave
    if(status == I2C_Master_MSTR_NO_ERROR )
    {
        //Get the bytes and print to uart using the temperature converter
        tempMsb = I2C_Master_MasterReadByte(I2C_Master_ACK_DATA);
        tempLsb = I2C_Master_MasterReadByte(I2C_Master_NAK_DATA);
        sprintf(buf,"The Temperature of slave %d: %.1f deg\r\n",slaveAddr,temperatureConverter(tempMsb,tempLsb));
        UART_1_PutString(buf);
    }
    else
    { 
        //Print the error
        sprintf(buf,"Erro in sending start: errno %d\r\n",status);
        UART_1_PutString(buf);
    }
    I2C_Master_MasterSendStop(); //Stop
    CyDelay(1000); //Delay
}

/* [] END OF FILE */
