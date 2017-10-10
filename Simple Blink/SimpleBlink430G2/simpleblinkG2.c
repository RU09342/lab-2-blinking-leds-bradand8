//Simple Blink msp430G2553
//Created by Bradley Anderson
//Date Created 9/30/2017

#include <msp430.h> // includes the msp430 library


/**
 * main.c
 */
int main(void)
{
    volatile int i;         //integer value from internal counter

    	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    	P1SEL &= ~0x01;     //Selects P1 as general I/O
    	P1DIR = 0x01;       //Sets bit 0 of P1 as the output
    	P1OUT &= ~BIT0;     //Clears bit 0

    	for (;;){   //Initializes a continuous loop

    	    P1OUT ^= 0x01; //Toggles P1 bit 0 on and off by XORing bit 0 with a 1.

    	    i = 8000;         //
    	    do i--;           // Initiates a delay between toggling bit 0
    	    while (i != 0);   //
    	}
}



