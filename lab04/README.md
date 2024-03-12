# Microcontroller Systems and Interfacing

## Week 4 experimental lab

### 1 Measure and display the ambient light level

Write a program that prints the value of A0. Build a circuit that produces a voltage proportional to the ambient light
level. Connect the potential divider output to an analogue input. Display the light level as a self-calibrated
percentage.

### 2 Measure and display a temperature

Find the LM35 temperature sensor in your hardware kit. (The number
is printed on the device.) Find the 5 V and GND pins on the LM35.
Connect the LM35 to the circuit.

#### 2.1 Convert the value read from A0 into a temperature.

Convert the raw A0 values into centigrade degrees.
Improve the precision of your conversion.

### 3 Challenges and mini-projects

#### 3.1 Make a ‘light theremin’

Use ambient light to control the frequency of an audio tone played on a loudspeaker. The
dimmer the ambient light, the higher the frequency of the audio tone. This will create
a musical instrument similar to a theremin that can be controlled (for example) by your
hand moving over the light sensor.
To make your instrument more expressive, create a ‘null zone’ where the tone will be
switched off to make the instrument become silent. There are at least three ways to set
where the null zone begins: (1) by using a potentiometer to set a threshold value above
which you use noTone() instead of tone(), or (2) by choosing a fixed threshold
(maybe 95% of maximum brightness or higher) where the instrument becomes silent,
or (3) by combining both approaches and making a potentiometer control the threshold
of silence as a percentage of maximum light level. Try all three. From the perspective
of a performing artist, which one works best?

#### 3.2 Make a nightlight

Use ambient light to control whether the built-in LED (connected to pin 13) is switched on or off. As the light
level falls, the LED should be switched on. A real-world application of this could be a nightlight, or even a
streetlight, which turns on automatically at night.
Adapt your system to control the ‘auto’ setting of car headlights. Car headlights do not react immediately
to changes in ambient light level. Instead they wait for a short while before turning on or off. This prevents the
headlights from turning on briefly when you drive under a bridge or through a short tunnel during the day, and
prevents them from turning off briefly if you drive under a bright light at night. When you detect a change in
light level (from dark to light, or light to dark) make your system wait 3 seconds before reacting.

#### 3.3 Make a ‘light beam counter’

Use the ambient light level to count objects that move past the photocell. (A source of
light pointing at the photocell, such as a torch or desk lamp, might help.) Every time
an object moves past the sensor, increase the count by 1 and display it on the serial
monitor.

#### 3.4 Increase the resolution of your temperature sensor

The microcontroller’s analogue-to-digital converter normally converts an input voltage range of 0 V–5 V to a digital
range of 0–1023.
The input voltage range can be changed by applying a reference voltage VREF to the AREF pin (next to digital pin 13)
and then calling analogReference(EXTERNAL) in your setup() function. The microcontroller’s analogue-to-digital
converter will then convert an input voltage range of 0 V–VREF to a digital range of 0–1023.
Use a potentiometer to create a variable analogue voltage. Connect this to one terminal of a 10 kΩ resistor, and the
other terminal of the resistor to the AREF pin (not IOREF!) of the microcontroller. (The resistor is important.) Set
your multimeter to its 20 V range. (From ‘off’, turn the selector knob three positions anti-clockwise.) Measure the
voltage between the AREF side of the resistor and GND. Set the potentiometer so that this voltage is exactly 1.00 V. (
Don’t forget to turn your multimeter off.)
Modify your code to use the new range of input values, which will be 0 for 0 V, and 1023 for 1 V (100 ◦C). Your
temperature resolution should now be much better, approximately 0.1 ◦C.