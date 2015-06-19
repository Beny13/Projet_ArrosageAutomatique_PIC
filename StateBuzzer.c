/**
  Buzzer Module Source File

  @Company
    Microchip Technology Inc.

  @File Name
    StateBuzzer.c

  @Summary
    This is the  user  source file which has specific functions for Buzzer State.

  @Description
   This module contains the functions used to generate a tone from the on board 8 ohm speaker.
   Within these functions is also the ability to modify the Pulse Width Modulation period
   which will change the pitch of the tone.
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
#include "StateBuzzer.h"
#include "app.h"
#include "lcd.h"
#include "DisplayMacros.h"
#include "Buttons.h"
#include "./mcc_generated_files/pin_manager.h"
#include "./mcc_generated_files/epwm1.h"
#include "./mcc_generated_files/tmr4.h"
#include "./mcc_generated_files/eusart.h"

/**
  Section: Global Variables
*/
uint8_t pwm_freq = 5;				      //   Preload of PWM Period
uint8_t	pwm_on	=  0x05;                              //   Duty Cycle of the PWM

void StateBuzzer(void)
{
    // Buzzer menu
    DisplayBuzMenu();

    while (1)
    {
        // If Next Mode Selected (by user)
        if(RA4_PRESSED())
        {
            // Event has been used
            RESET_RA4();

            // Clear LCD for next display
            DisplayClr();

            //Return to main function
            return;
        }

        // If buzzer mode confirmed
        else if(RB0_PRESSED())
        {
            // Event has been used
            RESET_RB0();

            while (1)
            {

                uint8_t sound = 1;

                // Turn the sound On
                SNDSound(sound,pwm_freq);

                // Display parameters
                DisplayBuzzerData(pwm_freq);

                // If exit selected
                if(RB0_PRESSED())
                {
                    //Stop Timer 4
                    TMR4_StopTimer();
                    
                    // Event has been used
                    RESET_RB0();

                    // Clear LCD for next display
                    DisplayClr();

                    // Exit infinite Loop
                    break;
                }
                // If buzzer parameter alteration
                else if(RA4_PRESSED())
                {
                    // Event has been used
                    RESET_RA4();

                    // Ensure PWM_Freq is at correct value
                    if(pwm_freq >= 251)
                    {
                        pwm_freq = 5;
                    }
                    else if(pwm_freq <= 4)
                    {
                        pwm_freq = 5;
                    }
                    else
                    {
                        pwm_freq += 5;

                        // Clear LCD for next display
                        DisplayClr();
                    }
                }
            }
            // Clear LCD for next display
            DisplayClr();
            
            break;
        }
    }
}

void SNDSound(uint8_t onoff, uint8_t pwm_period)
{
    // Load PR4 (Timer 4) with PWM period value
    PR4 = pwm_period;

    // Load CCPR1L with PWM duty cycle
    CCPR1L  = pwm_on;

    //Start Timer 4
    TMR4_StartTimer();

    //Turns the buzzer on if TRUE,otherwise shuts it off
    if (onoff)
    {
  	  P1A_TRIS = 0;
    }
    else
    {
  	  P1A_TRIS = 1;
    }
}

void DisplayBuzMenu(void)
{
    //Buzzer function select display
    BUZZER();

    //Display menu select options
    BIGMENU();
}

void DisplayBuzzerData(volatile uint8_t pwm_freq)
{
    //Display and convert Duty Cycle Period on LCD
    DUTYCYCLE();

    //Key based on Frequency change resulting from PWM Period change on LCD
    KEYS();

    //Display Duty Cycle menu options on LCD
    BUZZMENU();

    //UART display routines for Buzzer mode
    SERIALBUZZ();

    //Key based on Frequency change UART display routine
    SERIAL_KEYS();
}
/**
 End of File
*/