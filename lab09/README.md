# Microcontroller Systems and Interfacing

## Week 9 experimental lab

### 1 RGB LED arrays

Attach the RGB LED array and its three current-limiting resistors to the
microcontroller.

### 2 Programming the RGB LEDs

Configure the output pins. Turn on the one of the RGB LEDs.
Make segment A flash red instead of white.
Make segment A flash green instead of red. Make segment A flash blue instead of green. Make segment A flash in this
sequence: red green blue white.

#### 2.1 Accessing every LED independently

Turn on all three colours, one at a time, in the A segment. Create a utility function to control the colour of a
segment.
Test your setLED() function.

#### 2.2 Displaying multiple colours

Display three colours on the array, at the same time. Make different combinations of colours on the LEDs. Move the LED
code out of loop() to make way for some application code. Add some application code to loop() that updates value.
Display a value that rises steadily from 0 to 10, then falls back to 0, in a repeating cycle.

### 3 Interrupts

An interrupt is a way of diverting the microcontroller from its normal task and asking it to do something different for
a while.
Compare it to answering the telephone while you are in the middle of reading a book. Reading the book is the normal
activity,
the telephone ringing is the interrupt, and then answering the telephone and talking with the other person for a while
is called
servicing the interrupt. When interrupt servicing is finished the telephone call ends and you go back to reading your
book from
the point you were interrupted.
The microcontroller has several
sources of interrupts. One source of
interrupts are the built-in timers that
can generate a timer interrupt at regular intervals. That is the kind of interrupt that we need in order to run
our second, background ‘loop()’
function to update the LEDs.

#### 3.1 The TimerOne interrupt library

A user-friendly interface to timer interrupts is available using the TimerOne library. Before you can use the interface
you will
have to install the library.
Open the ‘Sketch’ menu and then select ‘Include Library’ followed by ‘Manage Libraries...’. A new window will open. In
the search box, type “TimerOne”. The display will update to show the libraries that match. Select ‘TimerOne’ and then
click
the ‘Install’ button that appears. When the progress bar completes, you can close the window.

#### 3.2 Programming with timer interrupts

Timer interrupts are controlled by several functions grouped together inside
an object called Timer1. To set up a periodic timer, two of these functions
must be called in setup(). The first, Timer1.initialize(), initialises the timer and tells it how often (in
microseconds) it should call the
‘background’ function. The second, Timer1.attachInterrupt(),
tells the timer which of our functions is the ‘background’ function.
The program on the right is a minimal example of using the timer interrupt to perform a background task on the RGB LED
array. In setup()
the pins connected to the first two segments and to the red LEDs are configured. All are initially LOW, which disables
the two segments but enables the
red LEDs. (Therefore to turn a segment on we need only set its pin HIGH.)
The timer is then asked to generate 10 interrupts per second (100, 000 µs
interval) and to call the function background() to service the interrupt.
The background() function uses digitalWrite() to toggle
segment B between ‘on’ and ‘off’ states.
The loop() function meanwhile toggles segment A every half a second.
The overall result is that segment A flashes once per second and segment B flashes five times per second.

### 4 A multi-colour bar-graph display with background updates

Display the light level (self-calibrated) on the RGB LED array.