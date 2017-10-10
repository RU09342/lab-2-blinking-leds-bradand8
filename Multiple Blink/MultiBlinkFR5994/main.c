/**
 * Bradley Anderson
 * MultiBlink FR5994
 * Date Created 10/7/2017
 */

#include <msp430.h> 


/**
 * main.c
 */

void main(void)
{

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;

	P1SEL0 &= ~0x01;
	P1SEL1 &= ~0x01;

	P1DIR |= (BIT0|BIT1);       //sets bit 0 of P1 and bit 2 of P1 as outputs

    volatile int i;         //integer value to delay first LED
    volatile int j;         //integer value to delay second LED

    i=j=0;


    for (;;) {   //Initializes and empty loop for LED 1 and 2
       i++;   //Increments i throughout loop
       j++;   //Increments j throughout loop

       if(i>10000) {     //As i increments, when it passes 10000 its value is reset and LED 1 is toggled
           i=0;
           P1OUT^= BIT0;
       }
       if(j>20000){    //As j increments, when it passes 20000 its value is reset and LED 2 is toggled
           j=0;
           P1OUT^= BIT1;
       }
    }
}
