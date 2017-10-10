/**
 * Bradley Anderson
 * Button Blink MSP430FR5994
 * Date Created 10/7/2017
  */


#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;      //Allows the I/O to reset from LPM ish
    volatile int i;         //integer value from internal counter

        P1DIR = 0x01;       //sets bit 0 of P1 as the output
        P5DIR = BIT5;       //sets bit 5 of P5 as an output
        P5REN = BIT5;       //Enables Pullup resistor on pin 5.5
        P5OUT = BIT5;       //Clears bit 1 of P5 making it a Pullup Resistor
    for (;;){   //Initializes an empty loop

         if(~P5IN & BIT5)    //If the Button (P2.1) is Pressed, allows the LED to toggle
                P1OUT ^= 0x01; //Toggles bit 0 on P1 by XORing bit 0 with itself

                i = 8000;         //
                do i--;           // Initiates a delay between toggling bit 0
                while (i != 0);   //

    }
}
