/**
  Initial state source file

  Company:
    Microchip Technology Inc.

  File Name:
    StateInitial.c

  Summary:
    This is the  user  source file which has specific functions for Board Start up.

  Description:
    This is the user application source file which has functions necessary for the start up process. 
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
#include "StateInitial.h"
#include "app.h"
#include "lcd.h"
#include  "DisplayMacros.h"
#include "./mcc_generated_files/eusart.h"

/**
  Section: Global Variables
*/
uint8_t tmrCount;

void StateInitial(void)
{
    // Welcome message
    DisplaySplashText();

    // Leave splash screen for 2s
    Wait2s();

    // Clear LCD for next display
    DisplayClr();
}

void DisplaySplashText(void)
{
    // Clear LCD
    DisplayClr();

    //Boot up info screen
    MICROCHIP();
}

void Wait2s(void)
{
    tmrCount = 50;
    
    // While still counting
    while(tmrCount)
    {
      ;
    } // Wait here
}
/**
 End of File
*/