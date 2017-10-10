# Off Board Blink
**NOTE:** This can only be done for the MSP430G2553 because the actual chip can be removed from the development board. For this part of the lab, the chip was pre-programmed with the multiblink code from an earlier. Afterward the chip was removed and put onto a breadboard. Then connections were made from the chip to LEDs and when powered up the LEDs would toggle. The only pin connections needed are:

- Power to the VCC pin
- Ground to the GND pin
- The two output pins to two seperate LEDs with a 1K Ohm resistor between each LED and ground for safety measures
- Power to the reset pin


## Powering the Chip
To avoid damaging the chip, power was connect by a wire from the VCC pin on the development board, onto the breadboard. Thus ensuring the voltage entering the chip was the amount it was designed to handle.


## Implemented LED Circuit
Below is an image of the setup for the Offboard Blink on a breadboard. 



![20171008_182517](https://user-images.githubusercontent.com/31701000/31401387-b835d526-adc0-11e7-8b1b-42d05addc42c.jpg)
