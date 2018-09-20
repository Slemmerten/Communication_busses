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
#include "I2C_Comm.h"

int main(void)
{
    //Inits
    I2C_Master_Start();
    I2C_Master_MasterClearStatus();
    UART_1_Start();
    UART_1_PutString("Program started...\r\n");

    for(;;) 
    {
        getTemp(0x48); //First slave
        getTemp(0x49); //Second slave
    }
}

/* [] END OF FILE */
