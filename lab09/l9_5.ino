#include <TimerOne.h>
void setup() {
  for (int pin = 0; pin <= 12; pin = pin + 1) pinMode(pin, OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  Timer1.attachInterrupt(background);
  Timer1.initialize(1000);
}
void setLED(int segment, int colour) {
  if (0 == colour) digitalWrite(segment, LOW);        // disable segment
  else digitalWrite(segment, HIGH);                   // enable segment
  if (0 == (colour & 0b001)) digitalWrite(10, HIGH);  // red on
  else digitalWrite(10, LOW);                         // red off
  if (0 == (colour & 0b010)) digitalWrite(12, HIGH);  // green on
  else digitalWrite(12, LOW);                         // green off
  if (0 == (colour & 0b100)) digitalWrite(11, HIGH);  // blue on
  else digitalWrite(11, LOW);                         // blue off
}
volatile int value = 0;  // volatile => ‘unpredictable’
int segment = 0;         // currently active segment

void background(void) {
  setLED(segment, 0);  // turn off active
  segment += 1;
  if (segment > 9) segment = 0;
  if (value <= segment) return;
  int colour = 2;                // green
  if (segment >= 6) colour = 3;  // yellow
  if (segment >= 9) colour = 1;  // red
  setLED(segment, colour);       // turn on active segment
}

int Vmin = 1024, Vmax = 0;

void loop(void) {
  int a0 = analogRead(A0);
  Vmin = min(Vmin, a0);
  Vmax = max(Vmax, a0);
  value = map(a0, Vmin, Vmax, 0, 11);                  // value = 0 1 2 ... 8 9 10
  background();
}