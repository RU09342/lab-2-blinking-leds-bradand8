/**
 * Multi Off Board Blink
 * Created By Bradley Anderson
 * Date Created 10/7/2017
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

        P1SEL &= ~0x01;     //Selects Port 1 pins as general I/O
        P1DIR |= (BIT0|BIT6);       //sets bit 0 of P1 and bit 6 of P1 as outputs

        i=j=0;

        for (;;){   //Initializes and empty loop for LED 1, 2, 3, and 4.

           i++;   //Increments i throughout loop
           j++;   //Increments j throughout loop


           if(i>10000) {     //As i increments, when it passes 10000 its value is reset and LED 1 is toggled
               i=0;
               P1OUT^= BIT0;
           }
           if(j>20000){    //As j increments, when it passes 20000 its value is reset and LED 2 is toggled
               j=0;
               P1OUT^= BIT6;
              }
        }
}

