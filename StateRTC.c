/**
  Real Time Clock Module Source File

  Company:
    Microchip Technology Inc.

  File Name:
    StateRTC.c

  Summary:
     This is the  user  source file which has specific functions for Real Time Clock State.

  Description:
    This module includes services to create the Real Time Clock and managing system for time.
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
#include "StateRTC.h"
#include "app.h"
#include "lcd.h"
#include "DisplayMacros.h"
#include "Buttons.h"
#include "./mcc_generated_files/tmr1.h"
#include "./mcc_generated_files/eusart.h"
#include <xc.h>

/**
  Section: Global Variables
*/
DATE_TIME dateTime;
uint8_t set;

/* This routine is called each time the user selects the Clock state) */
void StateClock (void)
{
    // Go show the clock selection screen
    DisplayClockMenu();

    while (1)
    {
        //If Next Mode Selected (by user)
        if(RA4_PRESSED())
        {
            // Event has been used
            RESET_RA4();

            // Clear LCD for next display
            DisplayClr();

            //return to main function
            return;
        }

        // If Real Time Clock Mode is confirmed
        else if(RB0_PRESSED())
        {
            // Event has been used
            RESET_RB0();

            //Start Timer 1
            TMR1_StartTimer();

            while (1)
            {
                // Display current time hh:mm:ss
                DisplayTime();

                // If user chose to exit (Menu Option)
                if(RB0_PRESSED())
                {
                    // Event has been used
                    RESET_RB0();

                    // Clear LCD for next display
                    DisplayClr();

                    //break from the loop
                    break;
                }

                // Set time
                else if(RA4_PRESSED())
                {
                        // Event has been used
                        RESET_RA4();

                        //Set time
                        StateClockSet();

                        // Clear LCD for next display
                        DisplayClr();
                }
            }

            // Clear LCD for next display
            DisplayClr();

            //break from the loop
            break;
        }
    }
}

void StateClockSet(void)
{
    // Clear LCD for next display
    DisplayClr();

    while (1)
    {
        // Options menu for clock set
        CLOCKOPT();

        //If hours set option is selected
        if(RA4_PRESSED())
        {
            // Event has been used
            RESET_RA4();

            //flag to decide whether to increment or decrement
            set = 0;

            while (1)
            {
                // Set hours on clock
                CLOCK_HRS();

                //Select whether to increment or decrement
                if(RA4_PRESSED())
                {
                    //Event has been used
                    RESET_RA4();

                    if(set == 0)
                    {
                        //increment hours
                        RTCIncHrs();
                    }
                    else if(set == 1)
                    {
                        //decrement hours
                        RTCDecHrs();
                    }
                }
                // to exit out of set option
                else if(RB0_PRESSED())
                {
                    //Event has been used
                    RESET_RB0();

                    if(set == 0)
                    {
                        set = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;
        }
        //If minutes set option is selected
        else if(RB0_PRESSED())
        {
            // Event has been used
            RESET_RB0();

            //flag to decide whether to increment or decrement
            set = 0;

            while(1)
            {
                // Set minutes on clock
                CLOCK_MIN();

                 //Select whether to increment or decrement
                if(RA4_PRESSED())
                {
                    // Event has been used
                    RESET_RA4();

                    if(set == 0)
                    {
                        //Increment Minutes
                        RTCIncMinutes();
                    }
                    else if(set == 1)
                    {
                        //Decrement Minutes
                        RTCDecMinutes();
                    }
                }
                // to exit out of set option
                else if(RB0_PRESSED())
                {
                    //Event has been used
                    RESET_RB0();
                    
                    if(set == 0)
                    {
                        set = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;
        }
    }
}

void DisplayClockMenu(void)
{
  //Clock function select display
  CLOCK();

  //Display menu select options
  BIGMENU();
}

void DisplayTime(void)
{
  //Display the RTC time value
  SHOWTIME();

  //Display Clock setting options
  CLOCKSET();

  //UART Display routine
  SERIALTIME();
}

void RTCIncDateTime(void)
{
    // Count 1 more second and Check if 1 more minute
    if (++dateTime.Sec == Max_Sec)
    {
        // Reset Seconds
        dateTime.Sec = 0;

        // Count 1 more minute & check If 1 more hour
        if (++dateTime.Min == Max_Min)
        {
            // Reset Minutes
            dateTime.Min = 0;

            // Count one more hour and check if day change
            if (++dateTime.Hour == Max_Hr)
            {
                // Reset Hours
                dateTime.Hour = 0;
            }
        }
    }
}

void RTCIncMinutes(void)
{
    // If time is set, restart seconds
    dateTime.Sec = 0;

    // Increment minutes & check if an hour elapsed
    if (++dateTime.Min == Max_Min)
    {
        // Reset minutes, hour has elapsed
        dateTime.Min = 0;

        // Increment hour if needed, check for day change
        if (++dateTime.Hour == Max_Hr)
	{
                // Reset hours if day has changed
	  	dateTime.Hour = 0;
	}
    }
}

void RTCDecMinutes(void)
{
    // If time is set, restart seconds
    dateTime.Sec = 0;

    // Decrement minutes & check if an hour elapsed
    if (--dateTime.Min == Roll_Back)
    {
        // Reset minutes, hour has elapsed
        dateTime.Min = (Max_Min - 1);

        // Decrement hour if needed, check for day change
        if (--dateTime.Hour == Roll_Back)
	{
            // Reset hours if day has changed
            dateTime.Hour = (Max_Hr - 1);
	}
    }
}

void RTCIncHrs(void)
{
    // If time is set, restart seconds
    dateTime.Sec = 0;

    // Increment hours & check if an day elapsed
    if (++dateTime.Hour == Max_Hr)
    {
        // Reset hours if day has changed
        dateTime.Hour = 0;
    }
}

void RTCDecHrs(void)
{
    // If time is set, restart seconds
    dateTime.Sec = 0;

    // Decrement hours & check if an day elapsed
    if (--dateTime.Hour == Roll_Back)
    {
        // Reset hours if day has changed
        dateTime.Hour = (Max_Hr-1);
    }
}

void RTCisr(void)
{
    // Re-arm the timer of another second
    TMR1H  |= 0x80;

    // Count a new second
    RTCIncDateTime();

    // Time has been updated
    timeHasChgd = 1;

     // Interrupt has been serviced
    TMR1IF = 0;
}
/**
 End of File
*/

