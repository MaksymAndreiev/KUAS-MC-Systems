const int CLR = 2; // asynchronous clear (active low)
const int CLK  = 3; // serial data clock (positive edge)
const int D    = 4; // serial data input

void posPulse(int pin) {
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}

void negPulse(int pin) {
  digitalWrite(pin, LOW);
  digitalWrite(pin, HIGH);
}

void setup() {
  pinMode(CLR, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(D, OUTPUT);
  digitalWrite(CLR, HIGH);
  digitalWrite(CLK, LOW);
  digitalWrite(D, LOW);
  negPulse(CLR);
}

void loop() {
  digitalWrite(D, HIGH);
  for (int i = 0; i < 8; i++) {
    posPulse(CLK); // send pulse
  }
  
  delay(500); // wait for 500ms

  // Set all LEDs OFF
  digitalWrite(D, LOW);
  for (int i = 0; i < 8; i++) {
    posPulse(CLK); // send pulse
  }
  
  delay(500);
}
