# Microcontroller Systems and Interfacing

## Week 12 experimental lab

### 1 Using shields and libraries

Large or sophisticated input/output devices are available as shields that plug directly into the Arduino pins. These
devices
usually require complex software, and so they are often accompanied by a library that provides an easy-to-use interface
to the
hardware.

### 2 Example shield: the LoL Shield

LoL stands for Lots of LEDs. A LoL Shield has 126 LEDs that can be turned
on or off individually. The shield uses 12 of the 14 digital pins to control the
LEDs. The scheme for addressing the individual LEDs is quite complex. To hide
the complexity the designer of the LoL Shield provides a library that provides a
very simple interface for Arduino programs to use.

### 3 Installing the hardware and library

Make sure the LoL Shield library is installed. Plug the LoL Shield into the Arduino.
Test the LoL Shield by running an example program.

### 4 Using the LoL Shield library

Create a program that turns on the LEDs one at a time, in turn,
for 20 ms each. Modify your program to ‘bounce’ a dot around the array of LEDs.
