/* 
 * File:   timeHandler.h
 * Author: ben
 *
 * Created on June 19, 2015, 2:30 AM
 */
#ifndef TIMEHANDLER_H
#define	TIMEHANDLER_H

#include <stdbool.h>
#include <stdint.h>

#define SECONDS_PER_HALF 1800

bool halfHasChanged = false;
uint16_t currentSecond = 0;

void RTCisr(void);

#endif	/* TIMEHANDLER_H */

