/**
  Source File for Button Detection

  Company:
    Microchip Technology Inc.

  File Name:
    Buttons.c

  Summary:
    This is the source file which has specific function for Button Detection

  Description:
    This module contains all the code related to a button press management on the PicDem 2 Plus demo board.
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
#include <xc.h>
#include "Buttons.h"

/**
 Section: Macro Definitions
*/
#define DEB_TIMEOUT  2                      //Debounce value (# of Timer0 ticks)

#define RA4_BUTTON	 PORTAbits.RA4
#define RB0_BUTTON	 PORTBbits.RB0

volatile BUTMSK_T TempButtons;  // Temporary Buffer (just local) for up to 8 buttons

#define RA4_ARMED()   (TempButtons.But1Pressed == 1)
#define RB0_ARMED()   (TempButtons.But2Pressed == 1)

#define ARM_RA4()     TempButtons.But1Pressed = 1
#define NEUT_RA4()    TempButtons.But1Pressed = 0
#define ARM_RB0()     TempButtons.But2Pressed = 1
#define NEUT_RB0()    TempButtons.But2Pressed = 0

/*User defined variables*/
uint8_t debCnt1 = 0,                         // Debounce counter for button 1
      	debCnt2 = 0;                         // Debounce counter for button 2

void Buttons_Initialize(void)
{
    // Initialize all Buttons
    Buttons.But1Pressed = Buttons.But2Pressed = Buttons.But3Pressed = Buttons.But4Pressed =
    Buttons.But5Pressed = Buttons.But6Pressed = Buttons.But7Pressed = Buttons.But8Pressed =
    TempButtons.But1Pressed = TempButtons.But2Pressed = TempButtons.But3Pressed =
    TempButtons.But4Pressed = TempButtons.But5Pressed = TempButtons.But6Pressed =
    TempButtons.But7Pressed = TempButtons.But8Pressed = 0;
}

void CheckButtons(void)
{
    // If button 1 (RA4) is pressed
    if(!RA4_BUTTON)
    {
        // If already debouncing
        if(debCnt1)
        {
            // If time out elapsed
            if(!--debCnt1)
            {
            // Set the mask for button 1 (RA4) (Valid press)
            SET_RA4();

            // Neutralize temporary mask for button 1
            NEUT_RA4();
            }
        }
        // Not yet debouncing => first detection
        else
        {
        // Initialize debounce count
        debCnt1 = DEB_TIMEOUT;

         // Save temporary state for RA4
        ARM_RA4();
        }
    }
    // Button 1 (RA4) is released
    else
    {
        // Reset debounce time out
        debCnt1 = 0;

        // Neutralize temporary mask for button 1
        NEUT_RA4();
    }

    // If button 2 (RB0) is pressed
    if(!RB0_BUTTON)
    {
        // If already debouncing
        if(debCnt2)
        {
            // If debounce time's up
            if(!--debCnt2)
            {
            // Set the mask for buttone 2 (RB0) (Valid press)
            SET_RB0();

            // Neutralize temporary mask for button 2 (RB0)
            NEUT_RB0();
            }
        }
        // Not yet debouncing => first detection
        else
        {
            // Initialize debounce count
            debCnt2 = DEB_TIMEOUT;

            // Arm The temporary key detection
            ARM_RB0();
        }
    }
    // Button 2 (RB0) is released
    else
    {
        // Reset debounce time out
        debCnt2 = 0;

        // Clear temporary mask for button 2 (RB0)
        NEUT_RB0();
    }
}

uint8_t GetButtons(void)
{
    // Read all buttons
    uint8_t result = (7 << Buttons.But8Pressed) | (6 << Buttons.But7Pressed) |
                     (5 << Buttons.But6Pressed) | (4 << Buttons.But5Pressed) |
                     (3 << Buttons.But4Pressed) | (2 << Buttons.But3Pressed) |
                     (1 << Buttons.But2Pressed) | (0 << Buttons.But1Pressed);

    // Return memorized keys
    return(result);
}
/**
 End of File
*/