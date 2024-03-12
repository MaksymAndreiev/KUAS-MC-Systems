# Microcontroller Systems and Interfacing

## Week 6 experimental lab

### 1 Using external LEDs

Attach some LEDs to digital pins 2, 3, 4, and 5. Use an appropriate series current-limiting resistor for each LED.

#### 1.1 Making patterns on the LEDs

Modify your program to ‘bounce’ the light back and forth along the line of LEDs.

#### 1.2 Displaying information on the LEDs

Obtain an analogue input on A0. Display the analogue value on the LEDs instead of the serial monitor.

### 2 Managing LED states

Make a ‘wave’ pattern that turns on all LEDs, one at a time, then turns them off again, one at a time.

#### 2.1 Representing the state of all four LEDs

Manipulating the individual state (on/off) of each LED as four separate, independent ‘things’
is not convenient. It would be more convenient to use a single value that represents the state
of all four LEDs.

#### 2.2 Writing a super-useful utility function: setLEDs()

Create an empty ‘skeleton’ for your setLEDs() function.

##### 2.2.1 Exploring binary constants

Make setLEDs() print the numeric value of the patterns parameter. Try changing the numbers in loop() to different binary
numbers. Try slightly longer ones. Print the numbers in binary.

##### 2.2.2 Exploring the digits of a binary number

Print whether each digit of pattern is a ‘0’ or a ‘1’. Print the digit values for various numbers.

##### 2.2.3 Implementing setLEDs()

Try other patterns.
