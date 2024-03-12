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

void setLEDs(int pattern) {
  for (int i = 7; i >= 0; i--)
    if ((pattern >> i) & 1) {
      digitalWrite(D, HIGH);
    } else {
      digitalWrite(D, LOW);
    }
    posPulse(CLK);
  }
}

void loop() {
  for (int i = 0; i < 256; i++) { 
    setLEDs(i);
    delay(500);
  }
}
