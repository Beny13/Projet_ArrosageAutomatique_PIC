#include "timeHandler.h"

#include <xc.h>

void RTCisr(void)
{
    // Re-arm the timer of another second
    TMR1H  |= 0x80;

    ++currentSecond;
    if (currentSecond >= SECONDS_PER_HALF) {
        currentSecond = 0;
        halfHasChanged = true;
    }

     // Interrupt has been serviced
    TMR1IF = 0;
}
