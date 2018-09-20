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
#include <stdio.h>
#include "project.h"
#include "SPI_Master_Comm.h"

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    SPIM_1_Start();
    UART_1_PutString("SPI communication application started\r\n");
    UART_1_PutString("q: Turn on led\r\n");
    UART_1_PutString("w: Turn off led\r\n");
    UART_1_PutString("e: Get led status\r\n");
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'q' :
        {
            UART_1_PutString("Led ON!\r\n");
            turnOnLed();
        }
        break;
        case 'w':
        {
            UART_1_PutString("Led OFF!\r\n");
            turnOffLed();
        }
        break;
        case 'e':
        {
            char buf[256];
            uint8_t ledStatus = getLedStatus();
            sprintf(buf,"Led status is %d\r\n", ledStatus);
            UART_1_PutString(buf);
        }
        default :
        {
            // nothing
        }
        break;
    }
}
/* [] END OF FILE */
