# Microcontroller Systems and Interfacing

## Week 10 experimental lab

### 1 Serial to parallel conversion

Using many LEDs (e.g., several seven-segment displays or bar graphs) is difficult, because only a few digital outputs
are
available. If each signal (LED) has one dedicated output pin, we are limited to at most 20 signals (digital pins 0 to 13
plus
analogue pins 0 to 5 configured as digital outputs). To connect N > 20 LEDs, or other devices, needs a different
approach.
Instead of N parallel connections (giving each output signal a dedicated output pin) we can use a single pin and send a
series of N single-bit values. Each value represents one of the N different signals. This serial signal will be received
by an
external serial to parallel converter and converted back to the N parallel signals that we need. One simple device that
can
perform serial to parallel conversion is a shift register.

#### 1.1 Build a bar-graph display interface using a shift register

Disconnect your Arduino USB cable. Do not connect it again until you have completed and then double-checked your
circuit. If your shift register is not properly connected, you will destroy it!
Connect a 74HC164 shift register to the Arduino. The inputs
can be connected directly to the microcontroller digital pins
as follows:
D2 → CLR (pin 9 on 74HC164)
D3 → CLK (pin 8)
D4 → DA and DB (pins 1 and 2)
Don’t forget to connect 5 V and GND from the microcontroller to the VCC and GND pins (respectively) on the shift
register.
Connect the shift register outputs to the first eight
LEDs of a normal (not RGB) bar-graph array.
**Check again that the shift register and the LED display are correctly oriented!**

#### 1.2 Create a program to test the shift register’s operation

Write a pair of functions called posPulse(pin) and negPulse(pin).
In the setup() function, use pinMode() (or DDRD) to configure digital pins 2, 3,
and 4 as OUTPUTs. Then use digitalWrite() (or PORTD) to initialise them as
follows:
signal pin initial state explanation
CLR D2 HIGH disable the clear signal (which is active-low)
CLK D3 LOW ready to clock data in on a rising edge
D D4 LOW data value ‘0’ (optional)

Still in the setup() function, add a line of code that uses
your negPulse(pin) function to generate a negative pulse
on the CLR pin.

In the loop() function, test the register’s operation by shifting a single bit through all eight stages. Add several
lines of code
that perform the following sequence of actions:

1. Set D to ‘1’ (HIGH).
2. Shift D into the register by generating a positive pulse on CLK.
3. Set D to ‘0’ (LOW).
4. Repeat eight times:
    1) generate a delay for 100 ms.
    2) Shift D into the register by generating a positive pulse on CLK.
5. generate a delay for 500 ms.

#### 1.3 Program the LEDs to make patterns

Make all of the LEDs flash on and off together. Make the LEDs count in binary. Make the LEDs light up in the
opposite order. Turn on LEDs 1, 3, 5 and 7 at full brightness, and LEDs 2, 4, 6 and 8 at half brightness. Flash LEDs 1,
3, 5 and 7 at full brightness, while flashing LEDs 2, 4, 6 and 8 at half brightness.

### 2 Challenges

Use an array to make lots of patterns. Add another shift register to your circuit. Use a more complex shift register.
