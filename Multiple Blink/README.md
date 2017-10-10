# Multiple Blink
This is an expansion on the simple blink. Using the same concept, multiple LEDs are toggled in the same program but at different rates.

## General Code
Following the same format as simple blink, the noticible difference is this time there are two integers to allow two LEDs to toggle at different rates. Additionally, depending on the location of the second LED there is another P1DIR BTI to correspond with the second LED. And ofcourse there will now be two if statements instead of one. The code for the G2553 microprocessor is shown below.

``` int main(void)
{
    volatile int i;         //integer value to delay first LED
    volatile int j;         //integer value to delay second LED

        WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

        P1SEL &= ~0x01;     //Selects Port 1 pins as general I/O
        P1DIR |= (BIT0|BIT6);       //sets bit 0 of P1 and bit 6 of P1 as outputs

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
               P1OUT^= BIT6;
           }
        }
}
```

# Differences among processors compared to the G2553
* MSP430G2553      Code given above
* MSP430F5529      Second LED corresponds to P4.7 not P1.6, P1DIR should be P4DIR and P1OUT should be P4OUT for the second LED.
* MSP430FR2311     Second LED corresponds to P2.1 not P1.6, P1DIR should be P2DIR and P1OUT should be P2OUT for the second LED
* MSP430FR5994     Second LED corresponds to P1.1 not P1.6
* MSP430FR6989     Second LED corresponds to P9.7 not P1.6, P1OUT needs to be P9OUT for second if statement

And ofcourse the FR microprocessors require an additional line of code to disable the GPIO resets.

## Extra Work MORE LEDS!
So far the codes to toggle the LEDs on the boards are simply controlling a particular pin. Therefore, essentially all pins can be used to blink an LED provided there are enough LEDs. Using a BreadBoard and 4 LEDs, 4 different pins were set up using the same method as the multi blink to form four differnt blinking speeds. This required that P1DIR be or-ed with 4 bits, and 4 for loops were made. An image of the setup is shown below.

![20171008_133024](https://user-images.githubusercontent.com/31701000/31370065-bbc18c0e-ad56-11e7-914b-26df9f80f44d.jpg)

As can be seen above, wires connect from different pins on the MSP430 to the leds on the breadboard. The full code can be found in the MSP430MultiBlinkExtra folder.
