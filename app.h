/**
  User Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This is the user application header file which has application specific functions.

  Description:
    This is the user application header file which has functions necessary to execute the user application.

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

#ifndef _APP_H
#define	_APP_H

/**
  Section: Included Files
*/
#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

/**
  Section: Data Types Definitions
*/
extern uint8_t tmrCount;                                //Software timer counter

/**
  @Summary
    Function for the initial state

  @Description
    This function is called when the application starts and enters the
    Splash display mode for 2 seconds before automatically moving on to
    the Voltmeter mode (state). The main state machine enters this state
    only once at start up. 

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void StateInitial(void);


/**
  @Summary
    Function for the voltage state

  @Description
    This routine is called each time the user selects the Voltmeter (e.g. state).
    This is the main handler for the Voltmeter. It first displays the correct text (Voltmeter menu)
    and either goes to the actual voltage display (actual reading) or moves to next mode
    (Buzzer), depending on what the user selects.
 
  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void StateVoltage(void);

/**
  @Summary
    Function for the Buzzer state

  @Description
    This routine is called each time the user selects the Buzzer
    mode (e.g. state). This is the main handler for the Buzzer. It
    first displays the correct text (Buzzer menu) and either goes to
    the buzzer activation/adjustment screen or moves on to next mode
    (Temperature), depending on what the user selects.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void StateBuzzer(void);

/**
  @Summary
    Function for the Temperature state

  @Description
    This routine is called each time the application enters the
    temperature mode (e.g. state). This is the Temperature state handler.
    It first displays the correct text (or menu) where the user can either
    select to goes to display the temperature readings or move go to the
    next mode (Clock). This is depending on what the user has chosen.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void StateTemperature(void);

/**
  @Summary
    Function for the Real Time Clock state

  @Description
    This routine is called each time the user selects the clock
    mode (e.g. state). This is the clock states main handler. It first
    displays the selection menu text and either goes to displaying current
    system time or returns to original state (Voltmeter), depending on the
    option the user picks.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void StateClock(void);

#ifdef	__cplusplus
}
#endif

#endif	/* _APP_H */

