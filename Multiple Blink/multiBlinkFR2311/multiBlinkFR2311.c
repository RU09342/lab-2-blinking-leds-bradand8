//Bradley Anderson
//MultiBlinkFR2311
//Date created 10/7/2017



#include <msp430.h> 


/**
 * main.c
 */
void main(void)
{
    volatile int i;         //integer value to delay first LED
    volatile int j;         //integer value to delay second LED
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	   PM5CTL0 &= ~LOCKLPM5;                    // Disable the GPIO power-on default high-impedance mode
	                                            // to activate previously configured port settings
	    P1DIR |= 0x01;                          // Set P1.0 to output direction
	    P2DIR |= 0x01;                          // Set P2.0 to output direction

        i=j=0;

        for (;;){   //Initializes and empty loop for LED 1 and 2

           i++;   //Increments i throughout loop
           j++;   //Increments j throughout loop

           if(i>10000) {     //As i increments, when it passes 10000 its value is reset and LED 1 is toggled
               i=0;
               P1OUT^= BIT0;
           }
           if(j>20000){    //As j increments, when it passes 20000 its value is reset and LED 2 is toggled
               j=0;
               P2OUT^= BIT0;
           }
        }


}
