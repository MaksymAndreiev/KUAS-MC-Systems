# Microcontroller Systems and Interfacing

## Week 7 experimental lab

### 1 Using LED ‘bar graph’ arrays

Replace the individual LEDs in last week’s experiment with a single LED array. Replace resistors with resistor network.

#### 1.1 Displaying information on the LED array

Use the LED array to display ambient light level from A0 input.

#### 1.2 Make a ‘USS Enterprise turbolift display simulator’

Modify your ‘moving dot’ program from the last lab to cover all 10 LEDs.

### 2 Using all available digital outputs

Connect a second LED array and resistor network.

#### 2.1 Avoiding the limit of 16-bit ints

Fix setLEDs() so that it can handle 20 pins (20-bit integers).
Create a 20-bit counter and display its value using setLEDs.
Figure out the speed of counter. Make your counter faster.

### 3 Direct access to the microcontroller’s I/O pins

Program PORTD directly. Program PORTB and PORTC directly.
