/**
 * Multi Extra BreadBoard Blink
 * Bradley Anderson
 * Created 10/7/2017
 */



#include <msp430.h>

/**
 * main.c
 */
int main(void)
{
    volatile int i;         //integer value to delay first LED
    volatile int j;         //integer value to delay second LED
    volatile int k;         //Integer value to delay 3rd LED
    volatile int l;         //Integer value to delay 4th LED

        WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

        P1SEL &= ~0x01;     //Selects Port 1 pins as general I/O
        P1DIR |= (BIT0|BIT4|BIT5|BIT6);       //sets bit 0 of P1, Bit 4 of P1, Bit 5 of P1 and bit 6 of P1 as outputs

        i=j=k=l=0;

        for (;;){   //Initializes and empty loop for LED 1, 2, 3, and 4.

           i++;   //Increments i throughout loop
           j++;   //Increments j throughout loop
           k++;   //    "      k    "         "
           l++;   //    "      l    "         "

           if(i>10000) {     //As i increments, when it passes 10000 its value is reset and LED 1 is toggled
               i=0;
               P1OUT^= BIT0;
           }
           if(j>20000){    //As j increments, when it passes 20000 its value is reset and LED 2 is toggled
               j=0;
               P1OUT^= BIT6;
              }
           if(k>5000){    //As j increments, when it passes 5000 its value is reset and LED 3 is toggled
                          j=0;
                          P1OUT^= BIT4;
           }

           if(l>15000){    //As j increments, when it passes 15000 its value is reset and LED 4 is toggled
                                         j=0;
                                         P1OUT^= BIT5;
           }
        }
}

