/**
    Header File for StateInitial.c

  Company:
    Microchip Technology Inc.

  File Name:
    StateInitial.h

  Summary:
     Header file for StateInitial.c

  Description:
    This file contains the function prototypes for the initial display module. 
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

#ifndef _STATEINITIAL_H
#define	_STATEINITIAL_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
  @Summary
    Function to Display the Welcome Text

  @Description
    This function is called to just display the splash screen when the app
    starts up, then immediately returns to the caller (state main handler).

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void DisplaySplashText(void);

/**
  @Summary
     Function for 2s delay used to display the splash screen

  @Description
    This function is called to take and keep control of the CPU for 2 seconds & return to caller.
    It uses a software Timer (tmrCount) that's decremented by the TIMER0 interrupt
    
  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void Wait2s(void);

#ifdef	__cplusplus
}
#endif

#endif	/* _STATEINITIAL_H */

