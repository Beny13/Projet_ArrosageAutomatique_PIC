/**
  Macros for display on LCD and UART Header File

  Company:
    Microchip Technology Inc.

  File Name:
    DisplayMacros.h

  Summary:
    LCD and UART messages

  Description:
      This file contains the macros created to create the displays used on the LCD for menus and UART messages.
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

#ifndef _DISPLAYMACROS_H
#define	_DISPLAYMACROS_H

#ifdef	__cplusplus
extern "C" {
#endif

/// @brief	Boot up info screen. [Splash Menu]
#define MICROCHIP()                                         \
	do                                                  \
	{                                                   \
            LCDPutStr("   Microchip");                      \
            LCDGoto(0,1);                                   \
            LCDPutStr(" PICDEM 2 PLUS");                    \
	}while (0);

/// @brief	Voltmeter function select display.
#define	VOLTMETER()                                         \
	do                                                  \
	{                                                   \
            LCDGoto(0,0);                                   \
            LCDPutStr("   Voltmeter");                      \
	}while (0);

#define BUZZER()                                            \
	do                                                  \
	{                                                   \
            LCDGoto(0,0);                                   \
            LCDPutStr("     Buzzer");                       \
	}while (0);

/// @brief	Temperature function select display.
#define TEMPERATURE()                                       \
	do                                                  \
	{                                                   \
            LCDGoto(0,0);                                   \
            LCDPutStr("  Temperature");                     \
	}while (0);

/// @brief	Clock function select display.
#define CLOCK()						    \
	do						    \
	{						    \
            LCDGoto(0,0);			            \
            LCDPutStr("     Clock");                        \
	} while (0);

/***************************** FAULT MACROS ****************************************/

/// @brief	I2C Communication Error. Check Address in I2C.C
#define COMFAULT()					   \
	do						   \
	{						   \
	    LCDGoto(0,0);				   \
	    LCDPutStr("   Temp Sensor  ");                 \
	    LCDGoto(0,1);			           \
	    LCDPutStr("   Comms Error  ");                 \
	} while (1);

/// @brief	I2C Timout Fault. Increase TO_MAX value in I2C.C
#define TOFAULT()					   \
	do						   \
	{						   \
	    LCDGoto(0,0);			           \
	    LCDPutStr("   Temp Sensor  ");                 \
	    LCDGoto(0,1);			           \
	    LCDPutStr(" Timeout  Fault ");                 \
	} while (1);

/***************************** VALUE MACROS ****************************************/

/// @brief	Display Voltage and convert Volt value to be displayed on screen.
#define VOLTAGE()						\
	do							\
	{							\
	    LCDGoto(0,0);					\
	    LCDPutStr("Volts = ");                              \
	    LCDPutChar(volt/100+'0');                           \
	    LCDPutChar('.');					\
	    LCDPutChar((volt / 10)%10+'0');                     \
	    LCDPutChar((volt /1)% 10+'0');                      \
	    LCDPutStr(" V   ");                                 \
	    LCDGoto(0,1);				        \
	    LCDPutChar('[');					\
	    LCDPutChar((ADC_Conversion/1000)+'0');              \
	    LCDPutChar(((ADC_Conversion/100)%10)+'0');          \
	    LCDPutChar(((ADC_Conversion/10)%10)+'0');           \
	    LCDPutChar((ADC_Conversion%10)+'0');                \
	    LCDPutStr("] RB0= Exit");                           \
	} while (0);

/// @brief	Display and convert Duty Cycle Period which affects the buzzer audio output.
#define DUTYCYCLE()                                                 \
	do                                                          \
	{                                                           \
	   LCDGoto(0,0);                                            \
	   LCDPutStr("PWM:");                                       \
	   LCDPutChar(((((pwm_freq/5)-1)*2) / 100) + '0');          \
	   LCDPutChar(((((((pwm_freq/5)-1)*2) /10)/1) % 10) + '0'); \
	   LCDPutChar(((((pwm_freq/5)-1)*2) % 10) + '0');           \
	   LCDPutChar('%');											\
	} while (0);

/// @brief	Look up table for Key based on Frequency change resulting from PWM Period change.
// -PWM:0%		Case 5: 	[Frequency:	10 KHz]
// -PWM:2%		Case 10: 	[Frequency:	5 KHz]
// -PWM:4%		Case 15: 	[Frequency:	4 KHz]
// -PWM:6%		Case 20: 	[Frequency:	3 KHz]
// -PWM:8%		Case 25: 	[Frequency:	2.45 KHz]
// -PWM:10%		Case 30: 	[Frequency:	2 KHz]
// -PWM:12%		Case 35: 	[Frequency:	1.73 KHz]
// -PWM:14%		Case 40: 	[Frequency:	1.52 KHz]
// -PWM:16%		Case 45: 	[Frequency:	1.36 KHz]
// -PWM:18%		Case 50: 	[Frequency:	1.23 KHz]
// -PWM:20%		Case 55: 	[Frequency:	1.16 KHz]
// -PWM:22%		Case 60: 	[Frequency:	1.03 KHz]
// -PWM:24%		Case 65: 	[Frequency:	950 Hz]
// -PWM:26%		Case 70: 	[Frequency:	880 Hz]
// -PWM:28%		Case 75: 	[Frequency:	823 Hz]
// -PWM:30%		Case 80: 	[Frequency:	775 Hz]
// -PWM:32%		Case 85: 	[Frequency:	730 Hz]
// -PWM:34%		Case 90: 	[Frequency:	690 Hz]
// -PWM:36%		Case 95: 	[Frequency:	653 Hz]
// -PWM:38%		Case 100: 	[Frequency:	620 Hz]
// -PWM:40%		Case 105: 	[Frequency:	590 Hz]
// -PWM:42%		Case 110: 	[Frequency:	560 Hz]
// -PWM:44%		Case 115: 	[Frequency:	530 Hz]
// -PWM:46%		Case 120: 	[Frequency:	510 Hz]
// -PWM:48%		Case 125: 	[Frequency:	495 Hz]
// -PWM:50%		Case 130: 	[Frequency:	478 Hz]
// -PWM:52%		Case 135: 	[Frequency:	460 Hz]
// -PWM:54%		Case 140: 	[Frequency:	442 Hz]
// -PWM:56%		Case 145: 	[Frequency:	427 Hz]
// -PWM:58%		Case 150: 	[Frequency:	414 Hz]
// -PWM:60%		Case 155: 	[Frequency:	400 Hz]
// -PWM:62%		Case 160: 	[Frequency:	390 Hz]
// -PWM:64%		Case 165: 	[Frequency:	375 Hz]
// -PWM:66%		Case 170: 	[Frequency:	365 Hz]
// -PWM:68%		Case 175: 	[Frequency:	355 Hz]
// -PWM:70%		Case 180: 	[Frequency:	345 Hz]
// -PWM:72%		Case 185: 	[Frequency: 335 Hz]
// -PWM:74%		Case 190: 	[Frequency:	326 Hz]
// -PWM:76%		Case 195: 	[Frequency:	318 Hz]
// -PWM:78%		Case 200: 	[Frequency:	310 Hz]
// -PWM:80%		Case 205: 	[Frequency:	300 Hz]
// -PWM:82%		Case 210: 	[Frequency:	295 Hz]
// -PWM:84%		Case 215: 	[Frequency:	290 Hz]
// -PWM:86%		Case 220: 	[Frequency:	284 Hz]
// -PWM:88%		Case 225: 	[Frequency:	277 Hz]
// -PWM:90%		Case 230: 	[Frequency:	270 Hz]
// -PWM:92%		Case 235: 	[Frequency:	264 Hz]
// -PWM:94%		Case 240: 	[Frequency:	259 Hz]
// -PWM:96%		Case 245: 	[Frequency:	254 Hz]
// -PWM:98%		Case 250: 	[Frequency: 249 Hz]
// -PWM:100%	Case 255: 	[Frequency:	245 Hz]

#define KEYS()                                                                                  \
	do											\
	{											\
	    LCDPutStr(" Key:");									\
	    switch (pwm_freq)									\
	    {											\
	        case 10: 	LCDPutStr("D8#");	break;					\
		case 15: 	LCDPutStr("B7 ");	break;					\
		case 20: 	LCDPutStr("F7#");	break;					\
		case 25: 	LCDPutStr("D7#");	break;					\
		case 30: 	LCDPutStr("C7 ");	break;					\
		case 35: 	LCDPutStr("A6 ");	break;					\
		case 40: 	LCDPutStr("G6 ");	break;					\
		case 45: 	LCDPutStr("F6 ");	break;					\
		case 50: 	LCDPutStr("D6#");	break;					\
		case 55: 	LCDPutStr("D6 ");	break;					\
		case 60: 	LCDPutStr("C6");	break;					\
		case 65: 	LCDPutStr("A5#");	break;					\
		case 70: 	LCDPutStr("A5 ");	break;					\
		case 75: 	LCDPutStr("G5#");	break;					\
		case 80: 	LCDPutStr("G5 ");	break;					\
		case 85: 	LCDPutStr("F5#");	break;					\
		case 90: 	LCDPutStr("F5 ");	break;					\
		case 95: 	LCDPutStr("E5 ");	break;					\
		case 100: 	LCDPutStr("D5#");	break;					\
		case 105: 	LCDPutStr("D5 ");	break;					\
		case 110: 	LCDPutStr("C5#");	break;					\
		case 115: 	LCDPutStr("C5 ");	break;					\
		case 125: 	LCDPutStr("B4 ");	break;					\
		case 135: 	LCDPutStr("A4#");	break;					\
		case 140: 	LCDPutStr("A4 ");	break;					\
		case 150: 	LCDPutStr("G4#");	break;					\
		case 160: 	LCDPutStr("G4 ");	break;					\
		case 170: 	LCDPutStr("F4#");	break;					\
		case 180: 	LCDPutStr("F4 ");	break;					\
		case 190: 	LCDPutStr("E4 ");	break;					\
		case 200: 	LCDPutStr("D4#");	break;					\
		case 210: 	LCDPutStr("D4 ");	break;					\
		case 220: 	LCDPutStr("C4#");	break;					\
		case 240: 	LCDPutStr("C4 ");	break;					\
		case 255: 	LCDPutStr("B3 ");	break;					\
		default: 	LCDPutStr("---");	break;					\
	}															\
    } while (0);


/// @brief	Display and convert TC74 temperature reading.
#define TEMPREADING()							\
	do								\
	{								\
	    LCDGoto(0,0);                                               \
	    LCDPutStr("Temp = ");                                       \
	    if (negValue == 1)						\
	    {                                                           \
                LCDPutChar('-');	                                \
            }                                                           \
	    else							\
	    {								\
		if (!(thermal/100))					\
		{                                                       \
                    LCDPutChar(' ');	                                \
                }			                                \
		else                                                    \
                {                                                       \
		    LCDPutChar(thermal/100+'0');                        \
                }                                                       \
	    }								\
	    LCDPutChar(thermal/10+'0');					\
	    LCDPutChar(thermal % 10+'0');                               \
	    LCDPutChar(223);                                            \
	    if (type == 1)					        \
	    {	                                                        \
                LCDPutStr("[F]   ");                                    \
            }                                                           \
	    else if(!type)					        \
	    {	                                                        \
                LCDPutStr("[C]   ");                                    \
            }                                                           \
	    LCDGoto(0,1);						\
	    if (type == 1)						\
	    {	                                                        \
                LCDPutStr("RA4=[C] RB0=Exit");                          \
            }                                                           \
	    else if (!type)					        \
	    {	                                                        \
                LCDPutStr("RA4=[F] RB0=Exit");                          \
            }                                                           \
	} while (0);
// Character [223] creates the degree symbol

/// @brief	Display the RTC time value.
#define SHOWTIME()                                                      \
	do							        \
	{							        \
	    LCDGoto(0,0);                                               \
	    LCDPutStr("TIME  ");                                        \
            LCDPutChar(dateTime.Hour/10+'0');                           \
            LCDPutChar(dateTime.Hour % 10+'0');                         \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Min/10+'0');                            \
            LCDPutChar(dateTime.Min % 10+'0');                          \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Sec/10+'0');                            \
            LCDPutChar(dateTime.Sec % 10+'0');                          \
	} while (0);

/// @brief	Display the RTC time value available for value change.
#define SHOWTIME_SET()                                                  \
	do							        \
	{							        \
	    LCDGoto(0,0);                                               \
            LCDPutChar(dateTime.Hour/10+'0');                           \
            LCDPutChar(dateTime.Hour % 10+'0');                         \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Min/10+'0');                            \
            LCDPutChar(dateTime.Min % 10+'0');                          \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Sec/10+'0');                            \
            LCDPutChar(dateTime.Sec % 10+'0');                          \
	    LCDPutChar(' ');                                            \
	    LCDPutChar(' ');                                            \
	} while (0);

/***************************** MENU MACROS *****************************************/

/// @brief	Display menu select options.
#define BIGMENU()                                                       \
	do                                                              \
	{                                                               \
	   LCDGoto(0,1);                                                \
	   LCDPutStr("RA4=Next RB0=Now");                               \
	} while (0);

/// @brief	Display exit menu options.
#define SMALLMENU()                                                     \
	do								\
	{								\
	   LCDGoto(0,1);                                                \
	   LCDPutStr("      RB0 = Exit");                               \
	} while (0);

/// @brief	Display Duty Cycle menu options.
#define BUZZMENU()                                                      \
	do								\
	{								\
	    LCDGoto(0,1);                                               \
  	    LCDPutStr("RA4=+2% RB0=Exit");                              \
	} while (0);

/// @brief	Display Clock setting options.
#define CLOCKSET()                                                      \
	do								\
	{								\
	    LCDGoto(0,1);                                               \
	    LCDPutStr("RA4=Set RB0=Menu");                              \
	} while (0);

/// @brief	Display Clock_Set select options.
#define CLOCKOPT()                                                      \
	do							        \
	{							        \
	    LCDGoto(0,0);                                               \
	    LCDPutStr("RA:[HR] ");                                      \
            LCDPutChar(dateTime.Hour/10+'0');                           \
            LCDPutChar(dateTime.Hour % 10+'0');                         \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Min/10+'0');                            \
            LCDPutChar(dateTime.Min % 10+'0');                          \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Sec/10+'0');                            \
            LCDPutChar(dateTime.Sec % 10+'0');                          \
	    LCDGoto(0,1);                                               \
	    LCDPutStr("RB:[MIN]  TIME ");                               \
	} while (0);

/// @brief	Display Hour setting options.
#define	CLOCK_HRS()                                                     \
	do							        \
	{							        \
	    LCDGoto(0,0);                                               \
            LCDPutChar(dateTime.Hour/10+'0');                           \
            LCDPutChar(dateTime.Hour % 10+'0');                         \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Min/10+'0');                            \
            LCDPutChar(dateTime.Min % 10+'0');                          \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Sec/10+'0');                            \
            LCDPutChar(dateTime.Sec % 10+'0');                          \
	    LCDPutStr("  *[HRS]");                                      \
	    LCDGoto(0,1);                                               \
	    LCDPutStr("RA:");                                           \
	    if (set == 0)                                               \
	    {							        \
		LCDPutChar('+');                                        \
		LCDPutChar('+');                                        \
	    }							        \
            else if (set == 1)                                          \
	    {							        \
		LCDPutChar('-');                                        \
		LCDPutChar('-');                                        \
	    }							        \
	    LCDPutStr("    RB:Next");                                   \
        } while (0);

/// @brief	Display Minute setting options.
#define	CLOCK_MIN()                                                     \
	do							        \
	{							        \
	    LCDGoto(0,0);                                               \
            LCDPutChar(dateTime.Hour/10+'0');                           \
            LCDPutChar(dateTime.Hour % 10+'0');                         \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Min/10+'0');                            \
            LCDPutChar(dateTime.Min % 10+'0');                          \
	    LCDPutChar(':');                                            \
            LCDPutChar(dateTime.Sec/10+'0');                            \
            LCDPutChar(dateTime.Sec % 10+'0');                          \
	    LCDPutStr("  *[MIN]");                                      \
	    LCDGoto(0,1);                                               \
	    LCDPutStr("RA:");                                           \
	    if (set == 0)                                               \
	    {							        \
		LCDPutChar('+');                                        \
		LCDPutChar('+');                                        \
	    }							        \
            else if (set == 1)                                          \
	    {							        \
		LCDPutChar('-');                                        \
		LCDPutChar('-');                                        \
	    }							        \
	    LCDPutStr("    RB:Next");                                   \
	} while (0);


/***************************** SERIAL MACROS **********************************/

/// @brief	Send Voltage info over serial RS232 connector.

#define SERIALVOLTS()                                                   \
	do								\
	{								\
            printf("\r\nVolts = ");                                     \
            EUSART_Write(volt/100+'0');                                 \
	    EUSART_Write('.');                                          \
	    EUSART_Write((volt / 10)%10+'0');                           \
	    EUSART_Write((volt /1)% 10+'0');                            \
	    printf(" V    ADC Count:");                                 \
	    EUSART_Write('[');					        \
	    EUSART_Write((ADC_Conversion/1000)+'0');                    \
	    EUSART_Write(((ADC_Conversion/100)%10)+'0');                \
	    EUSART_Write(((ADC_Conversion/10)%10)+'0');                 \
	    EUSART_Write((ADC_Conversion%10)+'0');                      \
	    EUSART_Write(']');                                          \
	} while (0);
// Carriage return
// Line Feed

/// @brief	Send Buzzer info over serial RS232 connector.
#define SERIALBUZZ()							\
	do								\
	{                                                               \
            printf("\r\nPWM: ");                                        \
	    EUSART_Write(((((pwm_freq/5)-1)*2) / 100) + '0');		\
	    EUSART_Write(((((((pwm_freq/5)-1)*2) /10)/1) % 10) + '0');  \
	    EUSART_Write(((((pwm_freq/5)-1)*2) % 10) + '0');            \
	} while (0);
// Carriage return
// Line Feed

/// @brief See KEYS()
#define SERIAL_KEYS()                                                                   \
	do                                                                              \
	{									        \
	     printf("          Key:");					                \
	     switch (pwm_freq)							        \
	     {									        \
                 case 10: 	printf("D8#");	break;					\
		 case 15: 	printf("B7 ");	break;					\
		 case 20: 	printf("F7#");	break;					\
		 case 25: 	printf("D7#");	break;					\
		 case 30: 	printf("C7 ");	break;					\
		 case 35: 	printf("A6 ");	break;					\
		 case 40: 	printf("G6 ");	break;					\
		 case 45: 	printf("F6 ");	break;					\
		 case 50: 	printf("D6#");	break;					\
		 case 55: 	printf("D6 ");	break;					\
		 case 60: 	printf("C6");	break;					\
		 case 65: 	printf("A5#");	break;					\
		 case 70: 	printf("A5 ");	break;					\
		 case 75: 	printf("G5#");	break;					\
		 case 80: 	printf("G5 ");	break;					\
		 case 85: 	printf("F5#");	break;					\
		 case 90: 	printf("F5 ");	break;					\
		 case 95: 	printf("E5 ");	break;					\
		 case 100: 	printf("D5#");	break;					\
		 case 105: 	printf("D5 ");	break;					\
		 case 110: 	printf("C5#");	break;					\
		 case 115: 	printf("C5 ");	break;					\
		 case 125: 	printf("B4 ");	break;					\
		 case 135: 	printf("A4#");	break;					\
		 case 140: 	printf("A4 ");	break;					\
		 case 150: 	printf("G4#");	break;					\
		 case 160: 	printf("G4 ");	break;					\
		 case 170: 	printf("F4#");	break;					\
		 case 180: 	printf("F4 ");	break;					\
		 case 190: 	printf("E4 ");	break;					\
		 case 200: 	printf("D4#");	break;					\
		 case 210: 	printf("D4 ");	break;					\
		 case 220: 	printf("C4#");	break;					\
		 case 240: 	printf("C4 ");	break;					\
		 case 255: 	printf("B3 ");	break;					\
		 default: 	printf("---");	break;					\
	    }                                                                           \
	} while(0);

/// @brief	Send TC74 Temperature info over serial RS232 connector.
#define SERIALTEMP()                                                            \
	do									\
	{									\
            printf("\n\rTemp = ");                                              \
	    if (negValue == 1)                                                  \
	    {	                                                                \
                EUSART_Write('-');	                                        \
            }                                                                   \
	    else                                                                \
	    {									\
		if (!(thermal/100))                                             \
		{ 	                                                        \
                    EUSART_Write(' ');	                                        \
                }                                                               \
		else                                                            \
                {                                                               \
		  EUSART_Write(thermal/100+'0');                                \
                }                                                               \
	    }									\
	    EUSART_Write(thermal/10+'0');                                       \
	    EUSART_Write(thermal % 10+'0');                                     \
	    EUSART_Write(248);                                                  \
	    if (type == 1)                                                      \
	    {	                                                                \
                printf("[F]   ");                                               \
            }                                                                   \
	    else if (!type)                                                     \
	    {	                                                                \
                printf("[C]   ");                                               \
            }                                                                   \
	} while (0);
/// @brief	Send Clock info over serial RS232 connector.

#define	SERIALTIME()                                                            \
	do                                                                      \
	{									\
	    if (timeHasChgd)                                                    \
	    {									\
                printf("\r\nSystem Time :");                                    \
		EUSART_Write(dateTime.Hour/10+'0');                             \
		EUSART_Write(dateTime.Hour % 10+'0');                           \
		EUSART_Write(':');                                              \
		EUSART_Write(dateTime.Min/10+'0');                              \
		EUSART_Write(dateTime.Min % 10+'0');                            \
		EUSART_Write(':');                                              \
		EUSART_Write(dateTime.Sec/10+'0');                              \
		EUSART_Write(dateTime.Sec % 10+'0');                            \
		timeHasChgd = 0;                                                \
	    }                                                                   \
	} while (0);

#ifdef	__cplusplus
}
#endif

#endif	/* _DISPLAYMACROS_H */