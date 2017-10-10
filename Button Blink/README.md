# Button Blink
Previously delays have been used to automatically toggle the LEDs on the MSP430 microprocessors. Instead of having the process be completed automated, we can take advantage of the buttons included on the MSP430s to tell the processor when to toggle.

## General Code
The code for the button blink is similiar to the simple blink code. A continuous for loop is still used and a variable determines how fast the LED blinks. However, in this code the bit corresponding to the button needs to be cleared. Additionally, either a pullup or a pulldown resistor must be enabled to allow the button to work. The below line takes care of the pullup resistor for pin 1.3 on the MSP430G2553.

```P1REN = BIT3 ```

Another required register is the PxIN register. This tells the microprocessor when there is an input from the button. The below example negates the PXIN signal and ANDs it with the button so the LED will toggle when the button is pressed, instead of stopping the toggle when the LED is pressed.

```
#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer similia 
	
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
```



## Differences Among Processors
* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

The only differences rely on the PXOUT, PXREN, and PXIN that correspond to the different ports and pins connected to each button for the various MSP430 microprocessors.

