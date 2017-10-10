/**
 * Simple Blink MSP430F5529
 * Created by Code Composer Studio
 * Edited by Bradley Anderson
 * Edited on 10/7/2017
 */

#include <msp430.h>				//Includes MSP430 library


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output

	volatile unsigned int i;		// creates a volatile integer i for the while loop

	while(1)                        //creates continuous loop
	{
		P1OUT ^= 0x01;				// toggle P1.0 by xoring the bit with 1
		for(i=30000; i>0; i--);     // delay
	}
}
