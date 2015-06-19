/**
  Header File for StateVoltmeter.c

  Company:
    Microchip Technology Inc.

  File Name:
    StateVoltmeter.h

  Summary:
    Header File for StateVoltmeter.c

  Description:
    This file contains the function prototypes for the Voltmeter functionality.
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

#ifndef _STATEVOLTMETER_H
#define	_STATEVOLTMETER_H

#ifdef	__cplusplus
extern "C" {
#endif

 /**
  Section: Included Files
*/
#include <stdint.h>
#define VOLTAGE_CHANGE 49

/**
  @Summary
    display of the voltmeter selection screen

  @Description
    This function is called to only display the Voltmeter selection screen,
    then directly returns control to the caller.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void DisplayVoltMenu(void);

/**
  @Summary
    Function for displaying specified conversion data

  @Description
    This function is called to display the current voltage on the
    potentiometer. It gets the raw A/D reading and converts it into a
    real voltage data before displaying it.

  @Preconditions
    None

  @Param
    Volt - Raw voltage data (from ADC).

  @Returns
    None

  @Comment
    If serial transmission is enabled, this function will output the
    the displayed data to the serial communication line regularly.
*/
void DisplayVoltage(uint16_t volt);


#ifdef	__cplusplus
}
#endif

#endif	/* _STATEVOLTMETER_H */

