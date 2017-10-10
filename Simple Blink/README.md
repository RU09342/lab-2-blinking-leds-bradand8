# Simple Blink 
One of the most basic introductory programs for an MSP 430 microprocessor is to blink one of the built in LEDs. Must include the msp430 library for the code to work.

``` #include <msp430.h> ```

## Base Code
Blinking an LED occurs by XORing the pin corresponding to the LED with a 1 on that bit. This switches the value of the LED pin between 0 and 1, hence turning the LED on and off and making it blink. All codes for the MSP430 processors require that the watchdog timer be stopped before implementing code. The Port 1 Select line of code will set Port 1 as a general Input/Output. This is not necessary as the port defaults as I/O. 

``` P1SEl &= ~0x01;    ```

Using the port direction command tells a particular pin on the port whether it will be an input or an output. 
  1. PXDIR = 0,  port is an input
  2. PXDIR = 1,  port is an output
  
  The output register, PXOUT, contains the value to be output from the port. The output register is used for the LED outputs.
  The input register, PxIN, contains a value input to the port. The input register enables pullup/pulldown resistors for button inputs.
  
  
  Below is a generic simple LED blink code for MSP430 microrocessors. Using a continuous loop and an arbitrary variable, the LED is toggled with a delay corresponding to the value of the variable. The loop decrements the variable from a set value and toggles the LED when the value becomes 0. A higher value for the variable equates to a longer delay, however the direct conversion to seconds is unknown at this time.
  
  ``` 
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
```

## The LED simple Blink was tested successfully on the following processors
* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

The only change necessary is for the microprocessors in the FR Family;  MSP430FR2311, MSP430FR5994, MSP430FR6989.
Right after the the Watchdog timer is stopped, an additional line of code is necessary to prevent the processor from unwantedly reseting pins. The necessary line is shown below.

```  PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode ```



## Improvements
Develop a way to convert the variable clock ticks to the unit of seconds to set a specific delay.

