#include "StateVoltmeter.h"
#include "mcc_generated_files/mcc.h"
#include "app.h"
#include "Buttons.h"
#include "lcd.h"
#include "StateInitial.h"
#include "timeHandler.h"
#include <stdio.h>

#define PARAM_COUNT 45
#define EEPROM_CHECK_ADDRESS 0x0
#define EEPROM_CHECK_FLAG 'y'
#define EEPROM_DATA_START 0x1
#define EEPROM_CURRENT_HALF_ADDRESS 0x2B
#define CURRENT_DATE_HIGH_INDEX 42
#define CURRENT_DATE_LOW_INDEX 43
#define HALF_IN_ONE_WEEK 336

void init()
{
    // initialize the device
    SYSTEM_Initialize();

    // initialize the LCD
    LCD_Initialize();

    // initialize Buttons
    Buttons_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    // Start Timer1 to count half hours
    TMR1_StartTimer();
}

uint16_t uint8to16(uint8_t high, uint8_t low)
{
    return ((uint16_t)high << 8) | low;
}

uint8_t uint16to8High(uint16_t value)
{
    return (uint8_t)value >> 8;
}

uint8_t uint16to8Low(uint16_t value)
{
    return (uint8_t)value;
}

bool checkCalendar(uint8_t* parameters)
{
    uint16_t theTime = uint8to16(parameters[42], parameters[43]);
    int byteToSelect = theTime / 8;
    int shift = theTime % 8;

    if ((0b00000001 << shift) & parameters[byteToSelect])
        return true;

    return false;
}

uint8_t getHumidity()
{
    uint8_t humidity = ADC_GetConversion(0) / 10;
    return humidity > 99 ? 99 : humidity;
}

bool checkHumidity(uint8_t* parameters)
{
    return getHumidity() < parameters[44];
}

void arrosageStart()
{
    PORTB = 0b00001000;
}

void arrosageStop()
{
    PORTB = 0b00000000;
}

void writeToFlash(uint8_t* parameters)
{
    // Writing flag
    eeprom_write(EEPROM_CHECK_ADDRESS, EEPROM_CHECK_FLAG);

    // Writing parameters
    uint8_t currentAddress = EEPROM_DATA_START;
    for (int i = 0; i < PARAM_COUNT; ++i) {
        eeprom_write(currentAddress, parameters[i]);
        ++currentAddress;
    }
}

void saveParametersFromEUSART(uint8_t* parameters)
{
    for (int i = 0; i < PARAM_COUNT; ++i) {
        parameters[i] = EUSART_Read();
    }

    writeToFlash(parameters);
}

void readParametersFromFlash(uint8_t* parameters)
{
    // unsigned char flagAddress = 0x0;
    uint8_t currentAddress = EEPROM_DATA_START;
    for (int i = 0; i < PARAM_COUNT; ++i) {
        parameters[i] = eeprom_read(currentAddress);
        ++currentAddress;
    }
}

bool flashHasParameters()
{
    unsigned char address = 0x0;
    return eeprom_read(address) == 'y';
}

void handleTimer(uint8_t* parameters)
{
    if (halfHasChanged) {
        halfHasChanged = 0;
        uint16_t theTime = uint8to16(parameters[CURRENT_DATE_HIGH_INDEX], parameters[CURRENT_DATE_LOW_INDEX]);
        theTime = (theTime + 1) % HALF_IN_ONE_WEEK;

        parameters[CURRENT_DATE_HIGH_INDEX] = uint16to8High(theTime);
        parameters[CURRENT_DATE_LOW_INDEX] = uint16to8Low(theTime);
    }
}

void int2bin(int a, char* buffer, int buf_size)
{
    buffer += (buf_size - 1);
    for (int i = 7; i >= 0; --i) {
        *buffer-- = (a & 1) + '0';
        a >>= 1;
    }
}


uint8_t display1 = 0;
uint8_t display2 = 0;

void displayParameters(uint8_t* parameters)
{
    if (display1 == parameters[44] && display2 == getHumidity())
        return;

    display1 = parameters[44];
    display2 = getHumidity();

    DisplayClr();
    char buffer[10];

    LCDGoto(0,0);
    sprintf(buffer, "%d", parameters[44]);
    LCDPutStr(buffer);
    LCDGoto(0,1);

    sprintf(buffer, "%d", getHumidity());
    LCDPutStr(buffer);
}

void arrosageLoop()
{
    uint8_t parameters[PARAM_COUNT];

    if (flashHasParameters()) {
        readParametersFromFlash(parameters);
    } else {
        saveParametersFromEUSART(parameters);
    }

    while (true) {
        if (checkHumidity(parameters) && checkCalendar(parameters)) {
            arrosageStart();
        } else {
            arrosageStop();
        }

        if (eusartRxCount > 0) {
            saveParametersFromEUSART(parameters);
        }

        handleTimer(parameters);
        displayParameters(parameters);
    }
}

///////// TESTS
void testPing()
{
    int i = 0;
    char buffer[10];
    while (1) {
        EUSART_Write(EUSART_Read());
        DisplayClr();
        sprintf(buffer,"%d", i);
        LCDPutStr(buffer);
        ++i;
    }
}

void testEEPROM()
{
    while (true) {
        unsigned char address = 0x0;
        eeprom_write(address, 'a');
        if (eeprom_read(0x0) == 'a') {
            LCDPutStr("gg");
        } else {
            LCDPutStr("no");
        }

        DisplayClr();
    }
}

void testFillFakeParameters(uint8_t* parameters)
{
    // Filling calendar
    for (int i = 0; i < 42; ++i) {
        parameters[i] = 0b01010111;
    }

    // Filling fake date
    // From 00:30 to 01:00
    parameters[42] = 0b00000000;
    parameters[43] = 0b00000001;

    // Filling fake humidity
    // 76%
    parameters[44] = 0b01001100;
}

void testFillFakeEEPROM()
{
    uint8_t parameters[PARAM_COUNT];
    testFillFakeParameters(parameters);
    writeToFlash(parameters);
}
//////////// END OF TESTS

void main(void)
{
    init();
    // testFillFakeEEPROM();
    arrosageLoop();
}