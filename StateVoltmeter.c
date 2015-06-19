/**
   Voltmeter state source file

  Company:
    Microchip Technology Inc.

  File Name:
    StateVoltmeter.c

  Summary:
    This is the  user  source file which has specific functions for Voltmeter State.

  Description:
    This module contains the functions used to activate the ADC and monitor the POT input as an analog signal.
    The input voltage is then displayed on the LCD.
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
#include "StateVoltmeter.h"
#include "app.h"
#include "lcd.h"
#include "DisplayMacros.h"
#include "Buttons.h"
#include "./mcc_generated_files/adc.h"
#include "./mcc_generated_files/eusart.h"
#include <stdio.h>

void StateVoltage(void)
{
    // Voltmeter menu
    DisplayVoltMenu();

    // Voltmeter Menu Input Loop
    while (1)
    {
        // If Next Mode Selected (by user)
        if(RA4_PRESSED())
        {
            // Event has been used
            RESET_RA4();

            // Clear LCD for next display
            DisplayClr();

            //Return to main function
            return;
        }

        // If Voltmeter mode confirmed
        else if(RB0_PRESSED())
        {
            // Event has been used
            RESET_RB0();

            //continuously displays measured voltage
            while (1)
            {
                //Go get voltage on potentiometer
                uint16_t Volt = ADC_GetConversion(0);

                // Go convert and display voltage value
                DisplayVoltage(Volt);

                // If exit selected
                if(RB0_PRESSED())
                {
                    // Event has been used
                    RESET_RB0();

                    // Clear LCD for next display
                    DisplayClr();

                    // Exit infinite Loop
                    break;
                }

            }
            // Clear LCD for next display
            DisplayClr();

            // Exit infinite Loop
            break;
        }
    }   
}

void DisplayVoltMenu(void)
{
    //Voltmeter function select display.
    VOLTMETER();

    //Display menu select options
    BIGMENU();
}


void DisplayVoltage(uint16_t volt)
{
    uint16_t ADC_Conversion;
  
    ADC_Conversion = volt;

    // Convert to real voltage
    volt = ((volt*VOLTAGE_CHANGE)/10)/10;

    // Display the voltage on LCD
    VOLTAGE();                                              

    //Display ON UART
    SERIALVOLTS();
}
/**
 End of File
*/
