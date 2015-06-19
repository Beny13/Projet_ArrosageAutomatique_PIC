/**
  Temperature state source file

  Company:
    Microchip Technology Inc.

  File Name:
    StateTemp.c

  Summary:
    This is the user  source file which has specific functions for Temperature State.

  Description:
    This is the application source file which has functions necessary functions for Temperature State.
*/

/*
Copyright (c) 2013 - 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

/**
  Section: Included Files
*/
#include "StateTemp.h"
#include "app.h"
#include "lcd.h"
#include "DisplayMacros.h"
#include "Buttons.h"
#include "./mcc_generated_files/i2c.h"
#include "./mcc_generated_files/eusart.h"
#include <xc.h>

/**
  Section: Global Variables
*/
uint8_t readValue;
uint8_t TC74_cmd = 0;                            // read temperature command
I2C_MESSAGE_STATUS    I2C_status = I2C_MESSAGE_COMPLETE;
uint8_t count = 0;
uint16_t I2C_Address = 0x4D;                      // slave device address

/* This routine is called each time the user selects the temperature state) */
void StateTemperature(void)
{
    uint8_t tempValue =0;
    uint8_t degreeType = 0;
    uint8_t sChange = 0;

    // Temperature menu text
    DisplayTempMenu();

    while (1)
    {     
        // If next mode selected (by user)
        if(RA4_PRESSED())
        {
            // Event has been used
            RESET_RA4();

            // Clear LCD for next display
            DisplayClr();

            //return to the main function
            return;
        }

        // If temperature mode confirmed
        else if(RB0_PRESSED())
        {
            // Event has been used
            RESET_RB0();

            // Infinite loop
            while (1)
            {
                 // i2c master write transaction with the supplied parameters
                I2C_MasterWrite( &TC74_cmd, 1, I2C_Address, &I2C_status);
                while (I2C_MESSAGE_PENDING  == I2C_status);

                //i2c master read transaction with the supplied parameters
                I2C_MasterRead( &readValue, 1, I2C_Address, &I2C_status);
                while (I2C_MESSAGE_PENDING  == I2C_status );

                // Get current temperature reading
                tempValue = readValue;

                // Display current reading
                DisplayTemperature(tempValue,degreeType);

                // User chooses to exit
                if(RB0_PRESSED())
                {
                    // Event has been used
                    RESET_RB0();

                    // Clear LCD for next display
                    DisplayClr();

                    //exits the infinite loop
                    break;
                }

                //unit change
                else if(RA4_PRESSED())
                {
                    // Event has been used
                    RESET_RA4();

                    if(sChange == 1)
                    {
                        sChange = 0;
                        degreeType = 1;
                    }
                    else
                    {
                        sChange = 1;
                        degreeType = 0;
                    }
                }
             }

            // Clear LCD for next display
            DisplayClr();

            //go to main function
            break;
        }
    }    
} 

void DisplayTempMenu(void)
{
    //Temperature function select display
    TEMPERATURE();

    //Display menu select options
    BIGMENU();
}

void DisplayTemperature(uint8_t thermal,uint8_t type)
{
    volatile uint8_t negValue;
    
    // Check to see if Celsius Temperature is Negative
    if (thermal >= 128)
    {
        thermal = 256 - thermal;
        negValue = 1;
    }
    else
    {
        thermal = thermal;
        negValue = 0;
    }

    // Display the Celsius Temperature as a Fahrenheit value
    if (type == 1)
    {
        if (negValue == 0)
        {
            thermal = (((thermal*9)/5)+32);
        }
        else if (negValue == 1)
	{
           // Values larger then 18; Fahrenheit goes negative.
	   if (thermal < 18)
           {
                thermal = (((thermal)*9)/5);
                thermal = 32-thermal;
                negValue = 0;
           }
	   else
           {
                thermal = ((((thermal)*9)/5)-32);
                negValue = 1;
           }
         }
    }

    //Display and convert TC74 temperature reading
    TEMPREADING();

    //Send TC74 Temperature info over serial RS232 connector.
    SERIALTEMP();
}
/**
 End of File
*/





