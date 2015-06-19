/* 
 * File:   StateTemperature.h
 * Author: i16156
 *
 * Created on February 25, 2015, 1:52 PM
 */

#ifndef STATETEMPERATURE_H
#define	STATETEMPERATURE_H

#include <stdint.h>

/* Function to display the temperature selection text */
void DisplayTempMenu(void);

/* Function to display the current temp reading */
void DisplayTemperature(uint8_t Thermal,uint8_t Type);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STATETEMPERATURE_H */

