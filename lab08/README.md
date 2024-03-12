# Microcontroller Systems and Interfacing

## Week 8 experimental lab

### 1 LED displays

Seven-segment displays contain seven (or eight, including the decimal point) individual LEDs arranged in a pattern that
is convenient for displaying digits (and maybe some letters too).
Unlike bar graph arrays, each LED in a seven-segment display shares one of its terminals with all the other LEDs in the
package.
The shared terminal might be the anode or the cathode, depending on the particular device. (Check the data sheet for
your device to find out which.) If all the anodes are connected together the arrangement
is called common anode; if all the cathodes are connected together,
the arrangement is called common cathode.
A common cathode seven-segment display therefore requires at least 8 pins (seven for the anodes, and a single pin for
the shared cathode connection). Most seven-segment displays also provide a decimal point (the eighth LED), and an
additional common connection, making a total of 10 pins.

#### 1.1 Seven-segment display circuit

Set up a single seven-segment display on your breadboard.

#### 1.2 Seven-segment display software

Create a program to drive the seven-segment display.

### 2 Using a seven-segment display to show digits

To display a digit we have to turn on the segments in an appropriate pattern. For example, the digit 0 will be
displayed if segments
A, B, C, D, E, and F are turned on, corresponding to digital pins 2, 3, 4, 5, 6 and 7
being HIGH, and pins 8 and 9 being LOW.
We can set these pins to their required states
in parallel using ‘setLEDs(0b00111111)’.
(Your setLEDs() function from recent labs
will work for this with little (or no) modification.)

#### 2.1 Designing the digits

Design a pattern of segments corresponding
to the digits 1 to 8. Convert your patterns to the corresponding H
(high) and L (low) values for each segment. Finally, convert the H and L values for each
segment into a series of 1 and 0 bits. The
equivalent integer value is the numeric
argument for setLEDs() that will display
the digit. You can write it directly in binary or
convert it to the equivalent decimal number.

#### 2.2 Displaying the digits

Write a function displayDigit(digit) that calls setLEDs() with the correct parameter for the given digit. Test your
function with the loop() shown on the right.

### 3 Digital input

Add two switches to a circuit and make them do something. Make the counter change just once each time a switch is pressed.

### 4 Hardware Debouncing

OPTIONAL: Cure the switch bounce using a small capacitor.

### 5 Software debouncing

Remove the debouncing capacitor(s) from your circuit.
Modify your program to implement the following debouncing strategy:
1. if the input pin is HIGH then do nothing (the switch is not pressed)
2. otherwise, the input pin is LOW:
   1) perform the associated action (increment or decrement the counter),
   2) wait for a short time (using the delay() function) to let the switch ‘settle’.

Improve your debouncing strategy.
