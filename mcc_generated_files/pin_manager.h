/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB® Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.10.3
        Device            :  PIC16F1937
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X 2.26
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS               TRISA0
#define channel_AN0_LAT                LATA0
#define channel_AN0_PORT               RA0
#define channel_AN0_ANS                ANSA0
#define channel_AN0_SetHigh()    do { LATA0 = 1; } while(0)
#define channel_AN0_SetLow()   do { LATA0 = 0; } while(0)
#define channel_AN0_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define channel_AN0_GetValue()         RA0
#define channel_AN0_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define channel_AN0_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set IO_RA1 aliases
#define IO_RA1_TRIS               TRISA1
#define IO_RA1_LAT                LATA1
#define IO_RA1_PORT               RA1
#define IO_RA1_ANS                ANSA1
#define IO_RA1_SetHigh()    do { LATA1 = 1; } while(0)
#define IO_RA1_SetLow()   do { LATA1 = 0; } while(0)
#define IO_RA1_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define IO_RA1_GetValue()         RA1
#define IO_RA1_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define IO_RA1_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set IO_RA2 aliases
#define IO_RA2_TRIS               TRISA2
#define IO_RA2_LAT                LATA2
#define IO_RA2_PORT               RA2
#define IO_RA2_ANS                ANSA2
#define IO_RA2_SetHigh()    do { LATA2 = 1; } while(0)
#define IO_RA2_SetLow()   do { LATA2 = 0; } while(0)
#define IO_RA2_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define IO_RA2_GetValue()         RA2
#define IO_RA2_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define IO_RA2_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set IO_RA3 aliases
#define IO_RA3_TRIS               TRISA3
#define IO_RA3_LAT                LATA3
#define IO_RA3_PORT               RA3
#define IO_RA3_ANS                ANSA3
#define IO_RA3_SetHigh()    do { LATA3 = 1; } while(0)
#define IO_RA3_SetLow()   do { LATA3 = 0; } while(0)
#define IO_RA3_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define IO_RA3_GetValue()         RA3
#define IO_RA3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define IO_RA3_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()   do { ANSA3 = 0; } while(0)
// get/set IO_RA4 aliases
#define IO_RA4_TRIS               TRISA4
#define IO_RA4_LAT                LATA4
#define IO_RA4_PORT               RA4
#define IO_RA4_ANS                ANSA4
#define IO_RA4_SetHigh()    do { LATA4 = 1; } while(0)
#define IO_RA4_SetLow()   do { LATA4 = 0; } while(0)
#define IO_RA4_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define IO_RA4_GetValue()         RA4
#define IO_RA4_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define IO_RA4_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define IO_RA4_SetDigitalMode()   do { ANSA4 = 0; } while(0)
// get/set IO_RA5 aliases
#define IO_RA5_TRIS               TRISA5
#define IO_RA5_LAT                LATA5
#define IO_RA5_PORT               RA5
#define IO_RA5_ANS                ANSA5
#define IO_RA5_SetHigh()    do { LATA5 = 1; } while(0)
#define IO_RA5_SetLow()   do { LATA5 = 0; } while(0)
#define IO_RA5_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define IO_RA5_GetValue()         RA5
#define IO_RA5_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define IO_RA5_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define IO_RA5_SetDigitalMode()   do { ANSA5 = 0; } while(0)
// get/set IO_RA7 aliases
#define IO_RA7_TRIS               TRISA7
#define IO_RA7_LAT                LATA7
#define IO_RA7_PORT               RA7
#define IO_RA7_SetHigh()    do { LATA7 = 1; } while(0)
#define IO_RA7_SetLow()   do { LATA7 = 0; } while(0)
#define IO_RA7_Toggle()   do { LATA7 = ~LATA7; } while(0)
#define IO_RA7_GetValue()         RA7
#define IO_RA7_SetDigitalInput()    do { TRISA7 = 1; } while(0)
#define IO_RA7_SetDigitalOutput()   do { TRISA7 = 0; } while(0)

// get/set IO_RB0 aliases
#define IO_RB0_TRIS               TRISB0
#define IO_RB0_LAT                LATB0
#define IO_RB0_PORT               RB0
#define IO_RB0_WPU                WPUB0
#define IO_RB0_ANS                ANSB0
#define IO_RB0_SetHigh()    do { LATB0 = 1; } while(0)
#define IO_RB0_SetLow()   do { LATB0 = 0; } while(0)
#define IO_RB0_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define IO_RB0_GetValue()         RB0
#define IO_RB0_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define IO_RB0_SetPullup()    do { WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()   do { WPUB0 = 0; } while(0)
#define IO_RB0_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()   do { ANSB0 = 0; } while(0)
// get/set IO_RB1 aliases
#define IO_RB1_TRIS               TRISB1
#define IO_RB1_LAT                LATB1
#define IO_RB1_PORT               RB1
#define IO_RB1_WPU                WPUB1
#define IO_RB1_ANS                ANSB1
#define IO_RB1_SetHigh()    do { LATB1 = 1; } while(0)
#define IO_RB1_SetLow()   do { LATB1 = 0; } while(0)
#define IO_RB1_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define IO_RB1_GetValue()         RB1
#define IO_RB1_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define IO_RB1_SetPullup()    do { WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()   do { WPUB1 = 0; } while(0)
#define IO_RB1_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()   do { ANSB1 = 0; } while(0)
// get/set IO_RB2 aliases
#define IO_RB2_TRIS               TRISB2
#define IO_RB2_LAT                LATB2
#define IO_RB2_PORT               RB2
#define IO_RB2_WPU                WPUB2
#define IO_RB2_ANS                ANSB2
#define IO_RB2_SetHigh()    do { LATB2 = 1; } while(0)
#define IO_RB2_SetLow()   do { LATB2 = 0; } while(0)
#define IO_RB2_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define IO_RB2_GetValue()         RB2
#define IO_RB2_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define IO_RB2_SetPullup()    do { WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()   do { WPUB2 = 0; } while(0)
#define IO_RB2_SetAnalogMode()   do { ANSB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()   do { ANSB2 = 0; } while(0)
// get/set IO_RB3 aliases
#define IO_RB3_TRIS               TRISB3
#define IO_RB3_LAT                LATB3
#define IO_RB3_PORT               RB3
#define IO_RB3_WPU                WPUB3
#define IO_RB3_ANS                ANSB3
#define IO_RB3_SetHigh()    do { LATB3 = 1; } while(0)
#define IO_RB3_SetLow()   do { LATB3 = 0; } while(0)
#define IO_RB3_Toggle()   do { LATB3 = ~LATB3; } while(0)
#define IO_RB3_GetValue()         RB3
#define IO_RB3_SetDigitalInput()    do { TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISB3 = 0; } while(0)

#define IO_RB3_SetPullup()    do { WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()   do { WPUB3 = 0; } while(0)
#define IO_RB3_SetAnalogMode()   do { ANSB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()   do { ANSB3 = 0; } while(0)
// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISB4
#define IO_RB4_LAT                LATB4
#define IO_RB4_PORT               RB4
#define IO_RB4_WPU                WPUB4
#define IO_RB4_ANS                ANSB4
#define IO_RB4_SetHigh()    do { LATB4 = 1; } while(0)
#define IO_RB4_SetLow()   do { LATB4 = 0; } while(0)
#define IO_RB4_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define IO_RB4_GetValue()         RB4
#define IO_RB4_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define IO_RB4_SetPullup()    do { WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()   do { WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()   do { ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define IO_RB5_TRIS               TRISB5
#define IO_RB5_LAT                LATB5
#define IO_RB5_PORT               RB5
#define IO_RB5_WPU                WPUB5
#define IO_RB5_ANS                ANSB5
#define IO_RB5_SetHigh()    do { LATB5 = 1; } while(0)
#define IO_RB5_SetLow()   do { LATB5 = 0; } while(0)
#define IO_RB5_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define IO_RB5_GetValue()         RB5
#define IO_RB5_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define IO_RB5_SetPullup()    do { WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()   do { WPUB5 = 0; } while(0)
#define IO_RB5_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()   do { ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISB6
#define IO_RB6_LAT                LATB6
#define IO_RB6_PORT               RB6
#define IO_RB6_WPU                WPUB6
#define IO_RB6_SetHigh()    do { LATB6 = 1; } while(0)
#define IO_RB6_SetLow()   do { LATB6 = 0; } while(0)
#define IO_RB6_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define IO_RB6_GetValue()         RB6
#define IO_RB6_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define IO_RB6_SetPullup()    do { WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()   do { WPUB6 = 0; } while(0)
// get/set IO_RB7 aliases
#define IO_RB7_TRIS               TRISB7
#define IO_RB7_LAT                LATB7
#define IO_RB7_PORT               RB7
#define IO_RB7_WPU                WPUB7
#define IO_RB7_SetHigh()    do { LATB7 = 1; } while(0)
#define IO_RB7_SetLow()   do { LATB7 = 0; } while(0)
#define IO_RB7_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define IO_RB7_GetValue()         RB7
#define IO_RB7_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define IO_RB7_SetPullup()    do { WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()   do { WPUB7 = 0; } while(0)
// get/set T1OSO aliases
#define T1OSO_TRIS               TRISC0
#define T1OSO_LAT                LATC0
#define T1OSO_PORT               RC0
#define T1OSO_SetHigh()    do { LATC0 = 1; } while(0)
#define T1OSO_SetLow()   do { LATC0 = 0; } while(0)
#define T1OSO_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define T1OSO_GetValue()         RC0
#define T1OSO_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define T1OSO_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

// get/set T1OSI aliases
#define T1OSI_TRIS               TRISC1
#define T1OSI_LAT                LATC1
#define T1OSI_PORT               RC1
#define T1OSI_SetHigh()    do { LATC1 = 1; } while(0)
#define T1OSI_SetLow()   do { LATC1 = 0; } while(0)
#define T1OSI_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define T1OSI_GetValue()         RC1
#define T1OSI_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define T1OSI_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set P1A aliases
#define P1A_TRIS               TRISC2
#define P1A_LAT                LATC2
#define P1A_PORT               RC2
#define P1A_SetHigh()    do { LATC2 = 1; } while(0)
#define P1A_SetLow()   do { LATC2 = 0; } while(0)
#define P1A_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define P1A_GetValue()         RC2
#define P1A_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define P1A_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS               TRISC3
#define SCL_LAT                LATC3
#define SCL_PORT               RC3
#define SCL_SetHigh()    do { LATC3 = 1; } while(0)
#define SCL_SetLow()   do { LATC3 = 0; } while(0)
#define SCL_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define SCL_GetValue()         RC3
#define SCL_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS               TRISC4
#define SDA_LAT                LATC4
#define SDA_PORT               RC4
#define SDA_SetHigh()    do { LATC4 = 1; } while(0)
#define SDA_SetLow()   do { LATC4 = 0; } while(0)
#define SDA_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define SDA_GetValue()         RC4
#define SDA_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS               TRISC5
#define IO_RC5_LAT                LATC5
#define IO_RC5_PORT               RC5
#define IO_RC5_SetHigh()    do { LATC5 = 1; } while(0)
#define IO_RC5_SetLow()   do { LATC5 = 0; } while(0)
#define IO_RC5_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define IO_RC5_GetValue()         RC5
#define IO_RC5_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

// get/set TX aliases
#define TX_TRIS               TRISC6
#define TX_LAT                LATC6
#define TX_PORT               RC6
#define TX_SetHigh()    do { LATC6 = 1; } while(0)
#define TX_SetLow()   do { LATC6 = 0; } while(0)
#define TX_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define TX_GetValue()         RC6
#define TX_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

// get/set RX aliases
#define RX_TRIS               TRISC7
#define RX_LAT                LATC7
#define RX_PORT               RC7
#define RX_SetHigh()    do { LATC7 = 1; } while(0)
#define RX_SetLow()   do { LATC7 = 0; } while(0)
#define RX_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define RX_GetValue()         RC7
#define RX_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS               TRISD0
#define IO_RD0_LAT                LATD0
#define IO_RD0_PORT               RD0
#define IO_RD0_ANS                ANSD0
#define IO_RD0_SetHigh()    do { LATD0 = 1; } while(0)
#define IO_RD0_SetLow()   do { LATD0 = 0; } while(0)
#define IO_RD0_Toggle()   do { LATD0 = ~LATD0; } while(0)
#define IO_RD0_GetValue()         RD0
#define IO_RD0_SetDigitalInput()    do { TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISD0 = 0; } while(0)

#define IO_RD0_SetAnalogMode()   do { ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()   do { ANSD0 = 0; } while(0)
// get/set IO_RD1 aliases
#define IO_RD1_TRIS               TRISD1
#define IO_RD1_LAT                LATD1
#define IO_RD1_PORT               RD1
#define IO_RD1_ANS                ANSD1
#define IO_RD1_SetHigh()    do { LATD1 = 1; } while(0)
#define IO_RD1_SetLow()   do { LATD1 = 0; } while(0)
#define IO_RD1_Toggle()   do { LATD1 = ~LATD1; } while(0)
#define IO_RD1_GetValue()         RD1
#define IO_RD1_SetDigitalInput()    do { TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISD1 = 0; } while(0)

#define IO_RD1_SetAnalogMode()   do { ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()   do { ANSD1 = 0; } while(0)
// get/set IO_RD2 aliases
#define IO_RD2_TRIS               TRISD2
#define IO_RD2_LAT                LATD2
#define IO_RD2_PORT               RD2
#define IO_RD2_ANS                ANSD2
#define IO_RD2_SetHigh()    do { LATD2 = 1; } while(0)
#define IO_RD2_SetLow()   do { LATD2 = 0; } while(0)
#define IO_RD2_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define IO_RD2_GetValue()         RD2
#define IO_RD2_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

#define IO_RD2_SetAnalogMode()   do { ANSD2 = 1; } while(0)
#define IO_RD2_SetDigitalMode()   do { ANSD2 = 0; } while(0)
// get/set IO_RD3 aliases
#define IO_RD3_TRIS               TRISD3
#define IO_RD3_LAT                LATD3
#define IO_RD3_PORT               RD3
#define IO_RD3_ANS                ANSD3
#define IO_RD3_SetHigh()    do { LATD3 = 1; } while(0)
#define IO_RD3_SetLow()   do { LATD3 = 0; } while(0)
#define IO_RD3_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define IO_RD3_GetValue()         RD3
#define IO_RD3_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISD3 = 0; } while(0)

#define IO_RD3_SetAnalogMode()   do { ANSD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()   do { ANSD3 = 0; } while(0)
// get/set IO_RD4 aliases
#define IO_RD4_TRIS               TRISD4
#define IO_RD4_LAT                LATD4
#define IO_RD4_PORT               RD4
#define IO_RD4_ANS                ANSD4
#define IO_RD4_SetHigh()    do { LATD4 = 1; } while(0)
#define IO_RD4_SetLow()   do { LATD4 = 0; } while(0)
#define IO_RD4_Toggle()   do { LATD4 = ~LATD4; } while(0)
#define IO_RD4_GetValue()         RD4
#define IO_RD4_SetDigitalInput()    do { TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISD4 = 0; } while(0)

#define IO_RD4_SetAnalogMode()   do { ANSD4 = 1; } while(0)
#define IO_RD4_SetDigitalMode()   do { ANSD4 = 0; } while(0)
// get/set IO_RD5 aliases
#define IO_RD5_TRIS               TRISD5
#define IO_RD5_LAT                LATD5
#define IO_RD5_PORT               RD5
#define IO_RD5_ANS                ANSD5
#define IO_RD5_SetHigh()    do { LATD5 = 1; } while(0)
#define IO_RD5_SetLow()   do { LATD5 = 0; } while(0)
#define IO_RD5_Toggle()   do { LATD5 = ~LATD5; } while(0)
#define IO_RD5_GetValue()         RD5
#define IO_RD5_SetDigitalInput()    do { TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISD5 = 0; } while(0)

#define IO_RD5_SetAnalogMode()   do { ANSD5 = 1; } while(0)
#define IO_RD5_SetDigitalMode()   do { ANSD5 = 0; } while(0)
// get/set IO_RD6 aliases
#define IO_RD6_TRIS               TRISD6
#define IO_RD6_LAT                LATD6
#define IO_RD6_PORT               RD6
#define IO_RD6_ANS                ANSD6
#define IO_RD6_SetHigh()    do { LATD6 = 1; } while(0)
#define IO_RD6_SetLow()   do { LATD6 = 0; } while(0)
#define IO_RD6_Toggle()   do { LATD6 = ~LATD6; } while(0)
#define IO_RD6_GetValue()         RD6
#define IO_RD6_SetDigitalInput()    do { TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISD6 = 0; } while(0)

#define IO_RD6_SetAnalogMode()   do { ANSD6 = 1; } while(0)
#define IO_RD6_SetDigitalMode()   do { ANSD6 = 0; } while(0)
// get/set IO_RD7 aliases
#define IO_RD7_TRIS               TRISD7
#define IO_RD7_LAT                LATD7
#define IO_RD7_PORT               RD7
#define IO_RD7_ANS                ANSD7
#define IO_RD7_SetHigh()    do { LATD7 = 1; } while(0)
#define IO_RD7_SetLow()   do { LATD7 = 0; } while(0)
#define IO_RD7_Toggle()   do { LATD7 = ~LATD7; } while(0)
#define IO_RD7_GetValue()         RD7
#define IO_RD7_SetDigitalInput()    do { TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISD7 = 0; } while(0)

#define IO_RD7_SetAnalogMode()   do { ANSD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()   do { ANSD7 = 0; } while(0)
// get/set IO_RE0 aliases
#define IO_RE0_TRIS               TRISE0
#define IO_RE0_LAT                LATE0
#define IO_RE0_PORT               RE0
#define IO_RE0_ANS                ANSE0
#define IO_RE0_SetHigh()    do { LATE0 = 1; } while(0)
#define IO_RE0_SetLow()   do { LATE0 = 0; } while(0)
#define IO_RE0_Toggle()   do { LATE0 = ~LATE0; } while(0)
#define IO_RE0_GetValue()         RE0
#define IO_RE0_SetDigitalInput()    do { TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISE0 = 0; } while(0)

#define IO_RE0_SetAnalogMode()   do { ANSE0 = 1; } while(0)
#define IO_RE0_SetDigitalMode()   do { ANSE0 = 0; } while(0)
// get/set IO_RE1 aliases
#define IO_RE1_TRIS               TRISE1
#define IO_RE1_LAT                LATE1
#define IO_RE1_PORT               RE1
#define IO_RE1_ANS                ANSE1
#define IO_RE1_SetHigh()    do { LATE1 = 1; } while(0)
#define IO_RE1_SetLow()   do { LATE1 = 0; } while(0)
#define IO_RE1_Toggle()   do { LATE1 = ~LATE1; } while(0)
#define IO_RE1_GetValue()         RE1
#define IO_RE1_SetDigitalInput()    do { TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISE1 = 0; } while(0)

#define IO_RE1_SetAnalogMode()   do { ANSE1 = 1; } while(0)
#define IO_RE1_SetDigitalMode()   do { ANSE1 = 0; } while(0)
// get/set IO_RE2 aliases
#define IO_RE2_TRIS               TRISE2
#define IO_RE2_LAT                LATE2
#define IO_RE2_PORT               RE2
#define IO_RE2_ANS                ANSE2
#define IO_RE2_SetHigh()    do { LATE2 = 1; } while(0)
#define IO_RE2_SetLow()   do { LATE2 = 0; } while(0)
#define IO_RE2_Toggle()   do { LATE2 = ~LATE2; } while(0)
#define IO_RE2_GetValue()         RE2
#define IO_RE2_SetDigitalInput()    do { TRISE2 = 1; } while(0)
#define IO_RE2_SetDigitalOutput()   do { TRISE2 = 0; } while(0)

#define IO_RE2_SetAnalogMode()   do { ANSE2 = 1; } while(0)
#define IO_RE2_SetDigitalMode()   do { ANSE2 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/