/**
 * Bradley Anderson
 * Button Blink MSP430G2553
 * Date Created 10/7/2017
  */


#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	volatile int i;         //integer value from internal counter


	        P1DIR = 0x01;       //sets bit 0 of P1 as the output
	        P1OUT = BIT3;     //Clears bit 3 of P1 which is the button
	        P1REN = BIT3;       //Enables Pullup resistor on pin 1.3

	        for (;;){   //Initializes an empty loop

	             if((~P1IN&BIT3))    //If the Button (P1.3) is Pressed, allows the LED to toggle
	                    P1OUT ^= 0x01; //Toggles bit 0 on P1 by XORing bit 0 with itself

	                    i = 8000;         //
	                    do i--;           // Initiates a delay between toggling bit 0
	                    while (i != 0);   //

	        }
}
