/**
 * Multi Blink F5529
 * Created by Bradley Anderson
 * Last updated 10/8/2017
 */



#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    volatile int i;         //integer value to delay first LED
    volatile int j;         //integer value to delay second LED

        WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer


        P1DIR |= BIT0;       //sets bit 0 of P1
        P4DIR |= BIT7;       //sets bit 7 of P4 as outout
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
               P4OUT^= BIT7;
           }
        }
}


