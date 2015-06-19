/**
  Header File for StateBuzzer.c

  Company:
    Microchip Technology Inc.

  File Name:
    StateBuzzer.h

  Summary:
    Header file for StateBuzzer.c

  Description:
    This file contains the function prototypes for the Sound or Buzzer functions used within the program.
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

#ifndef _STATEBUZZER_H
#define	_STATEBUZZER_H

#ifdef	__cplusplus
extern "C" {
#endif

 /**
  Section: Included Files
*/
#include <stdint.h>

/**
  @Summary
    Function to display the buzzer selection text

  @Description
    This function is called to display the Buzzer selection screen only,
    then return to the caller.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void DisplayBuzMenu(void);

/**
  @Summary
    Function to display the buzzer parameters

  @Description
    This function is called to display current buzzer settings and activate
    the sound on the buzzer. It starts by setting a duty cycle of 46% to be
    able to get an audible sound, then waits for a user action: Either they
    selects to alter the duty cycle, or exits the buzzer mode.

  @Preconditions
    None

  @Param
    pwm_freq - Duty cycle to be set and displayed.

  @Returns
    None

  @Comment
    If the serial transmission is enabled, this function will output the
    the displayed data (duty cycle valuer) to the serial communication line
    regularly.
*/
void DisplayBuzzerData(uint8_t pwm_freq);

/**
  @Summary
    Function to Send sound information to buzzer to generate sound

  @Description
    This function allows the application to turn the buzzer on
    or off, according to the command set by the caller.

  @Preconditions
    None

  @Param
    onoff - Turns the buzzer on if TRUE,otherwise shuts it off
    pwm_period - Adjust the Period of the PWM effecting pitch/tone

  @Returns
    None

  @Comment
    If the serial transmission is enabled, this function will output the
    the displayed data (duty cycle valuer) to the serial communication line
    regularly.
*/
void SNDSound(uint8_t onoff, uint8_t pwm_period);

#ifdef	__cplusplus
}
#endif

#endif	/* _STATEBUZZER_H */

