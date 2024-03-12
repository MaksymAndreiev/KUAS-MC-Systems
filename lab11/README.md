# Microcontroller Systems and Interfacing

## Week 11 experimental lab

### 1 Serial Peripheral Interface (SPI) hardware

are many complex devices designed to operate with microcontrollers, such as flash memory (SD) cards, digital-toanalogue
and analogue-to-digital converters, and real-time clocks. These devices often use serial instead of parallel
communication. They behave a bit like a shift register, using one or two serial data signals and a clock to exchange
information with
the microcontroller. The two most common protocols they use are Inter-Integrated Circuit (I2C) and Serial Peripheral
Interface
(SPI). The simpler (and more flexible) of the two is SPI.

#### 1.1 External ADC: MCP3204

Connect a MCP3204 ADC to the microcontroller. Use the following digital pins to carry the SPI signals:
SPI / Arduino MCP3204
SS pin 10 → pin 8 CS
MOSI pin 11 → pin 9 DIN
MISO pin 12 → pin 10 DOUT
SCK pin 13 → pin 11 CLK

Create a test voltage using a potentiometer (or a sensor of your
choice) and connect it to the first
input, CH0.

### 2 SPI communication software

Some microcontrollers (including the Arduino) provide SPI support in hardware. Access to the hardware’s SPI signals is
made
available through a library. Other microcontrollers do not include hardware SPI support, and communicating with SPI
devices
requires manual control of all four SPI signals. We will use both methods to communicate with the MCP3204.

#### 2.1 Using the SPI library

Create a new sketch. Make the SPI library available by including SPI.h at the beginning. Create a definition (using
#define or const int to associate the symbol SSN (‘slave select, active-low’) with pin
number 10. Perform the following initialisation steps in setup():

1. Start the Serial interface at 9600 baud.
2. Configure the SSN pin as an OUTPUT, and set its value
   to inactive.
3. Start the SPI interface using a clock divider of 4, SPI
   mode 0,0, and transfers with most significant bit first.

Create a function int readADC(unsigned char channel) that reads and returns a value from the given ADC
channel. To read from the ADC using SPI, you will have to do the following steps:

1. Enable the ADC by setting SSN active.
2. Use SPI.transfer() to send (and receive) three bytes from the ADC. The first byte contains five zeros, a start bit 1,
   and mode bit 1 (single-ended conversion), and the most significant bit of the three-bit channel number. The second
   byte
   contains the least significant two bits of the channel number, followed by 6 zeros. The third byte can contain
   anything.
3. Collect the values returned by the second and third calls to SPI.transfer(). The least significant four bits of the
   first value are the four most significant bits of the ADC result. The second value contains the eight least
   significant bits
   of the result. Recombine them into a 12-bit result.
4. Turn off the ADC by setting SSN inactive.
5. Return the result from the ADC.

Test your sketch with a loop() that prints the results of reading channel 0, then pauses for a quarter of a second. (
Don’t forget to open the serial monitor to view the output generated
by the sketch.)

#### 2.2 Implementing SPI manually

Save your sketch from the previous section under a new name. We are going to remove all references to the SPI library
and
generate the necessary SPI signals explicitly. Delete the #include <SPI.h> from the beginning of the sketch.
Keep the defintion for SSN. Add three more definitions for MOSI (pin 11), MISO (pin 12), and SCK (pin 13).
In setup(), delete the four lines that configure the SPI library. Replace them with code that performs the following
actions:

1. Configure MOSI as an OUTPUT.
2. Configure MISO as an INPUT.
3. Configure SCK as an OUPUT and set it to idle (LOW).

Implement a function void sendBit(int value) that writes the least significant bits of value to the SPI device. You
will have to perform two steps to do this:

1. Write (using digitalWrite()) the least significant bit (only) of value to MOSI.
2. Generate a positive pulse on SCK by setting it HIGH then back to LOW.

Implement a function int recvBit(void) that reads one bit from the SPI device. You will have to perform four steps to
do this:

1. Set SCK active (HIGH) to ensure data is available on MISO.
2. Use digitalRead() to obtain the value (0 or 1) of MISO.
3. Set SCK inactive (LOW) to end the clock cycle.
4. Return the bit that was read from MISO.

Delete the three lines in readADC() that refer to SPI.transfer(). Replace them with code that explicitly initiates a
conversion. (Refer to the timing diagram in Appendix B.) Your code will perform the following steps:

1. Use sendBit() to send a 1 (start bit) followed by another 1 (single-ended mode) to the ADC. (We do not need to send
   the initial 5 zeros that were necessary when using the byte-oriented SPI library.)
2. Use sendBit() to write the least significant three bits of channel to the ADC.
3. Use sendBit() to write two ‘don’t care’ bits to the ADC.
4. Use recvBit() to read 12 bits from the ADC. For each bit read you will have to shift adval one bit left, then add to
   it the bit read from the ADC. At the end of this you will have reconstructed the 12 bits of ADC result.
5. Return the final value of adval.

### 3 Challenges

Modify loop() (in either of your sketches) to display the values of all four ADC channels. Connect one or more voltage
sources to the other ADC input channels and verify that the sketch prints the correct results. Disable (comment out) the
Serial.println() and delay() from loop() in your two sketches. Modify loop to perform many conversions (call readADC()
many times). Use millis() to record the time before and after performing the
conversions. Calculate how many conversions per second are being peformed. Connect a MCP4822 digital-to-analogue
converter (DAC) and use it to generate a sine wave. (See the appendix for the relevant
parts of the data sheet.) Note: VDD must be connected to 5 V and VSS must be connected to GND. Be very careful to get
this right! To check the sine wave, connect the DAC output to an ADC input channel and display the results on the serial
plotter. Note that you can share the SCK and MOSI signals between the ADC and the DAC but you will need two SPI
protocols, two different ‘slave select’ pins (one for the ADC and a new one for the DAC), and a new LDAC signal for the
DAC.
