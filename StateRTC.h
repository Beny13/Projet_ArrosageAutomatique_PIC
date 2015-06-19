/**
   Header File for StateRTC.h

  Company:
    Microchip Technology Inc.

  File Name:
    StateRTC.h

  Summary:
    This is a header file RTC module.

  Description:
    This file contains the function prototypes for the Real Time Clock.
    Allowing for a change in Hours/Minutes while tracking Seconds.
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

#ifndef _STATERTC_H
#define	_STATERTC_H

#ifdef	__cplusplus
extern "C" {
#endif

 /**
  Section: Included Files
*/
#include <stdint.h>
#include <stdbool.h>
#include "./lcd.h"
    
/**
  Section: Data Types Definitions
*/
typedef struct
        {
          uint8_t  	Sec;                      // Buffer for seconds
          uint8_t     	Min;                      // Buffer for minutes
          uint8_t	Hour;                     // Buffer for hours
          uint8_t       Day;                      // Buffer for day of the month
          uint8_t       Month;                    // Buffer for month
          uint16_t 	Year;                     // Buffer for the year
        } DATE_TIME;

bool  timeHasChgd = 0;			          // Time update flag

extern DATE_TIME dateTime;

#define Max_Sec		60		          // Secounds in a minute
#define Max_Min		60		          // Minutes in a Hour
#define Max_Hr		24		          // Hours in a Day
#define Roll_Back      255		          // If decremented past 0

/**
  @Summary
    Function to display the clock selection text

  @Description
    This function is called to display the clock selection screen
    only, then returns to the caller.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void DisplayClockMenu(void);

/**
  @Summary
    Function to display the current system time and selection

  @Description
    This function is called after the user has confirmed the "Clock"
    mode to display current system time. The user is offered the
    possibility to set the time using the RA4 button.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    If the serial transmission is enabled, this function will output the
    the displayed data (actual system time) to the serial
    communication line regularly.
*/
void DisplayTime(void);

/**
  @Summary
    Function to set time function

  @Description
    This function is called after the user has selected to set the system
    time. Depending on the the user's choice, it offers either additional
    clock setting options, allowing the setting of minutes or hours.

  @Preconditions
    None

  @Param
    val - User selection (minutes/sec, ...)
    cMenu - Current menu (or level).

  @Returns
    None
*/
void SetTime(uint8_t val,uint8_t cMenu);

/**
  @Summary
    Function to make time adjustments

  @Description
    This routine is called when the user selects to set the time, after entering
    the time display mode (e.g. state). It first waits for the user to specify
    whether the hours or minutes are to be updated. Then calls the related
    time update routine.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void StateClockSet(void);

/**
  @Summary
    Function to Increment date/time(every second)

  @Description
    This function is called every second to increment the
    system date/time.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    Time is handled in 24 hours format.
*/
void RTCIncDateTime(void);

/**
  @Summary
    Function to add 1mn to Date/time (User time setting)

  @Description
    This funciton is called from within the Clock_Set menu
    allowing the user to adjust minutes. This function will
    increment the clock.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void RTCIncMinutes(void);

/**
  @Summary
    Function to subtract  1mn from Date/time (User time setting)

  @Description
    This funciton is called from within the Clock_Set menu
    allowing the user to adjust minutes. This function will
    decrement the clock.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void RTCDecMinutes(void);

/**
  @Summary
    Function to add 1hr to  Date/time (User time setting)

  @Description
    This funciton is called from within the Clock_Set menu
    allowing the user to adjust hours. This function will
    increment the clock.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void RTCIncHrs(void);

/**
  @Summary
    Function to subtract 1hr to  Date/time (User time setting)

  @Description
    This funciton is called from within the Clock_Set menu
    allowing the user to adjust hours. This function will
    decrement the clock.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void RTCDecHrs(void);

/**
  @Summary
    Function when timer 1 interrupt is detected(interrupt service routine)

  @Description
     Interrupt Service Routine is called by the Interrupt Manager.

  @Preconditions
    Initialize  the TMR1 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void RTCisr(void);

#ifdef	__cplusplus
}
#endif

#endif	/* _STATERTC_H */

