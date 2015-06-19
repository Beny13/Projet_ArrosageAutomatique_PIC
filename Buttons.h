/**
  Header File for Module Buttons.c

  Company:
    Microchip Technology Inc.

  File Name:
    Buttons.h

  Summary:
    Header File for Button Detection functions in Buttons.C module

  Description:
    This file contains the function prototypes for input switchs used to determine a single or multiple button push.
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

#ifndef _BUTTONS_H
#define	_BUTTONS_H

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
typedef struct
        {
          uint8_t But1Pressed : 1;
          uint8_t But2Pressed : 1;
          uint8_t But3Pressed : 1;
          uint8_t But4Pressed : 1;
          uint8_t But5Pressed : 1;
          uint8_t But6Pressed : 1;
          uint8_t But7Pressed : 1;
          uint8_t But8Pressed : 1;
        } BUTMSK_T;

BUTMSK_T Buttons;     // buffer for up to 8 buttons

#define RA4_PRESSED()  (Buttons.But1Pressed)
#define RB0_PRESSED()  (Buttons.But2Pressed)
#define BOTH_PRESSED() ((Buttons.But1Pressed) && (Buttons.But2Pressed))
#define BUT_PRESSED()  ((Buttons.But1Pressed) || (Buttons.But2Pressed) || \
                        (Buttons.But3Pressed) || (Buttons.But4Pressed) || \
                        (Buttons.But5Pressed) || (Buttons.But6Pressed) || \
                        (Buttons.But7Pressed) || (Buttons.But8Pressed))

#define SET_RA4()     Buttons.But1Pressed = 1
#define RESET_RA4()   Buttons.But1Pressed = 0
#define SET_RB0()     Buttons.But2Pressed = 1
#define RESET_RB0()   Buttons.But2Pressed = 0

/**
  @Summary
    Function to debounce and determine button press

  @Description
    This function monitors RB0 and RA4 buttons on the PicDem 2
    Plus board. It starts a debounce period (filtering mechanical bounces)
    before validating a button press.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    This routine is meant to be called on a regular basis In this application,
    it is called when Timer0 interrupt (TMR0IF) occurs.
*/
void CheckButtons(void);

/**
  @Summary
    Function which returns which button has been pressed

  @Description
    This function returns to the caller what buttons have been  pressed.

  @Preconditions
    None

  @Param
    None

  @Returns
    All pressed buttons since last button read.

  @Comment
    This function is capable of returning a button press from
    RA4 or RB0 or both depending on the buttons pressed.
*/
uint8_t GetButtons(void);

/**
  @Summary
    Initialisation routine

  @Description
    This function is called to initialize the button management
    environment, for proper operation. It mainly resets the buton
    state flags, so they start n the released mode.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    This routine should be called only once at start up.
*/
void Buttons_Initialize(void);

#ifdef	__cplusplus
}
#endif

#endif	/* _BUTTONS_H */

