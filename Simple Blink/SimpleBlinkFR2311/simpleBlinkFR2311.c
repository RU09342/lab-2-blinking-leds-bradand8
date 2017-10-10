//***************************************************************************************
//  Created by Texas Instruments, Inc
//  Created on July 2013
//  Edited by Bradley Anderson
//  Edited on 10/4/2017
//***************************************************************************************

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction

    for(;;) {
        volatile unsigned int i;            // creates volatile integer i for the while loop

        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR with 1

        i = 10000;                          // Sets the delay between toggling the LED
        do i--;
        while(i != 0);
    }
}
