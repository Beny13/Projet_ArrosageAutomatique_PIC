#include "StateTemperature.h"
#include "app.h"
#include "Lcd.h"
#include "DisplayMacros.h"
#include "Buttons.h"
#include "./mcc_generated_files/epwm1.h"



/******************************************************************************
* Function: void StateTemperature(void)
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called each time the application enters the
*           		temperature mode (e.g. state). This is the Temperature state handler.
*           		It first displays the correct text (or menu) where the user can either
*           		selct to goes to display the temperature readings or move go to the
*           		next mode (Clock). This is depending on what the user has chosen.
*
* @note        		None.
*/
/*******************************************************************/

void StateTemperature(void)
{
  uint8_t temp_Value;
  uint8_t degree_Type = 0;
  uint8_t sChange = 0;

  DisplayTempMenu();                                    // Temperature menu text
  if (BUT_PRESSED())                             // If a button press is pending
  {
    if (RB0_PRESSED())                          // If temperature mode confirmed
    {
      RESET_RB0();                                        // Event has been used
      LCDClear();                                            // Clear the screen
      for (;;)                                                  // Infinite loop
      {
        temp_Value = I2CReadTemp();           // Get current temperature reading
        DisplayTemperature(temp_Value,degree_Type);   // Display current reading
        if (BUT_PRESSED())                       // If a button press is pending
        {
          if (RB0_PRESSED())                             // User chooses to exit
          {
            RESET_RB0();                                  // Event has been used
            nState = ST_TEMPERATURE;              // Move on to temperature mode
            LCDClear();                            // Wipe display for next mode
            break;                                     // Exit the infinite loop
          }
	  if (RA4_PRESSED())                             // User chooses to exit
          {
            RESET_RA4();                                  // Event has been used
	    if (sChange == 1)
	    {
	      sChange = 0;
	      degree_Type = 1;
	    }
	    else
	    {
	      sChange = 1;
	      degree_Type = 0;
	    }
          }
        }
      }
    }
    else if (RA4_PRESSED())                   // If next mode selected (by user)
         {
           RESET_RA4();                                   // Event has been used
           nState = ST_CLOCK;                    // Move to clock selection mode
           LCDClear();                             // Clear LCD for next display
         }
  }                                                  // If button press recorded
}                                             	   // Temperature selection mode

/******************************************************************************
* Function: void DisplayTempMenu(void)
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display the temperature selection screen
*           		only, then return to the caller.
*
* @note        		None.
*/
/*******************************************************************/

void DisplayTempMenu(void)
{
  TEMPERATURE();
  BIGMENU();
}

/******************************************************************************
* Function: void DisplayTemperature(unsigned char Thermal)
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display current temperature reading from
*           		the probe. It takes the specified raw reading, converts it into a real
*           		displayable ASCII value, and sends it out to the LCD.
*
* @param			Thermal 	Raw reading acquired from the probe (through I2C).
*
* @note        		If the serial transmission is enabled, this function will output the
*           		the displayed data (converted temperature value) to the serial
*           		communication line regularly.
*/
/*******************************************************************/

void DisplayTemperature(uint8_t Thermal,uint8_t Type)
{
  volatile uint8_t negValue;
  static uint16_t prevTherm;

  if (Thermal >= 128)         // Check to see if Celsius Temperature is Negative
  {
    Thermal = 256 - Thermal;
    negValue = 1;
  }
  else
  {
    Thermal = Thermal;
    negValue = 0;
  }

	// Display the Celsius Temperature as a Fahrenheit value

  if (Type == 1)
  {
    if (negValue == 0)
      {	Thermal = (((Thermal*9)/5)+32);	}
    else if (negValue == 1)
	 {
	   if (Thermal < 18) // Values larger then 18; Fahrenheit goes negative.
	   {
	     Thermal = (((Thermal)*9)/5);
	     Thermal = 32-Thermal;
	     negValue = 0;
	   }
	   else
	   {
	     Thermal = ((((Thermal)*9)/5)-32);
	     negValue = 1;
	   }
         }
  }

  TEMPREADING();

//  if (TickOff)                   // Making sure we wait 16.3 ms between readings
//  {
//    TickOff = FALSE;                                        // Permission used
//    #ifdef SERIAL_COM
//      SERIALTEMP();
//    #endif
//  }
}