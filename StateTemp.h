/**
   Header File for StateTemp.c

  Company:
    Microchip Technology Inc.

  File Name:
    StateTemp.h

  Summary:
    Header file for StateTemp.c

  Description:
    This file contains the function prototypes for the Temp sensor functionality.
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

#ifndef _STATETEMP_H
#define	_STATETEMP_H

#ifdef	__cplusplus
extern "C" {
#endif

 /**
  Section: Included Files
*/
#include <stdint.h>

/**
  @Summary
    Function to display the temperature selection text

  @Description
    This function is called to display the temperature selection screen
    only, then return to the caller.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void DisplayTempMenu(void);

/**
  @Summary
   Function to display the current temperature reading

  @Description
    This function is called to display current temperature reading from
    the probe. It takes the specified raw reading, converts it into a real
    displayable ASCII value, and sends it out to the LCD.

  @Preconditions
    None

  @Param
    Thermal Raw reading acquired from the probe (through I2C).

  @Returns
    None

  @Comment
    If the serial transmission is enabled, this function will output the
    the displayed data (converted temperature value) to the serial
    communication line regularly.
*/
void DisplayTemperature(uint8_t thermal,uint8_t type);

#ifdef	__cplusplus
}
#endif

#endif	/* _STATETEMP_H */

