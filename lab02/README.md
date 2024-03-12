# Microcontroller Systems and Interfacing

## Week 2 experimental lab

### 1 Communication using the serial monitor

#### 1.1 Serial monitor ‘hello world’

Send the message “hello world” from the microcontroller back to the host computer.

#### 1.2 Sending numeric values to the host computer

Send a changing integer value back to the host computer, instead of a fixed ‘Hello, world’ message.

#### 1.3 Increasing communication speed

In some situations, 9600 bits per second is too slow. Good values to try are 19200 baud (bits per second), or even
115200 bits per second.

#### 1.4 Using non-decimal number bases

Modify your program to send the counter value to the host computer using binary notation.

### 2 Analogue input

Build a circuit to generate a variable voltage using a potentiometer.
Read the value of the voltage and report it to the host computer.

### 3 Plot the value instead of printing it

The Arduino development environment can plot values graphically as well as printing them as text. Close the serial
monitor
window, then open a serial plotter window instead (from the ‘Tools’ menu).

### 4 Use the analogue input to control a digital output

Make the LED blink each time you read the analogue voltage. Make the LED blink at a rate proportional to the input
voltage.

### 5 Challenges

#### 5.1 Print the angle of the potentiometer

The analogue reading varies between 0 and 1023. The potentiometer knob turns through 270 degrees. Modify your first
sketch
so that it prints the angle of the potentiometer knob (in the range 0 to 270) instead of the raw analogue value (in the
range 0 to
1023).

#### 5.2 Print the voltage level present on pin A0

The analogue reading varies between 0 and 1023. These values represent a voltage in the range 0 V to 5 V. Modify your
first
sketch so that it prints the input voltage (in the range 0 V to 5 V) instead of the raw analogue value (in the range 0
to 1023).

#### 5.3 Use the keyboard to control the blink rate of the LED

At the top of the serial monitor window is a text area where
you can type text to send to the microcontroller. On the microcontroller you can use Serial.available() to read
what was typed. The function Serial.available()
tells you how many characters are waiting to be read and
Serial.read() gives you the next unread character. You
can use some conditional statements with these functions to
read text that the user types on the host computer, extract single digits from the text, and use them to set the delay
time.
An incomplete example is shown on the right. Add the
code for the remaining digits so that they set appropriate delay
values.
Don’t forget to press the enter key (or the ‘send’ button)
after typing text into the serial monitor.

#### 5.4 Monitor two analogue inputs at the same time

You have a second potentiometer in your experimental kit. Duplicate the existing circuit to create a second analogue
voltage,
controlled by a second potentiometer, and connect it to pin A1. Modify your serial monitor program to print both input
voltage
values, from A0 and A1, on the same line separated by a space.
