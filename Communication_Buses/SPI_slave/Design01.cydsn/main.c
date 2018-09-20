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


CY_ISR(ISR_handler)
{
    uint8_t bytesToRead=SPI_GetRxBufferSize();
    while(bytesToRead!=0)
    {
        uint8_t ByteReceived=SPI_ReadRxData();
        if(ByteReceived==0b00000001) //LED turn on message from master
            LED_Write(1u);//turn on LED
        else if(ByteReceived==0b00000000)//LED turn off message from master
            LED_Write(0u);  //turn off LED
        else if(ByteReceived==0b00000011)//LED requist status message from master
            SPI_WriteTxData(LED_Read());//write to master with LED status
 --bytesToRead;
  }
 
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_Start();
    ISR_StartEx(ISR_handler);
    SPI_EnableRxInt();


    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
  //do nothing
    }
}

/* [] END OF FILE */
