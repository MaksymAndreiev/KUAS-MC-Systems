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
  for (int i = 7; i >= 0; i--){
    if ((pattern >> i) & 1) {
      digitalWrite(D, HIGH);
    } else {
      digitalWrite(D, LOW);
    }
    posPulse(CLK);
  }
}

void loop() {
  // Pattern for full brightness LEDs (1, 3, 5, 7)
  int fullBright = 0b01010101;

  // Pattern for half brightness LEDs (2, 4, 6, 8)
  int halfBright = 0b10101010;

  for(int i = 0; i < 20; i++) { // Repeat enough times to visually perceive the brightness difference
    setLEDs(fullBright | halfBright); // Turn on both full and half brightness LEDs
    delay(1); // Short delay
    setLEDs(fullBright); // Turn off half brightness LEDs
    delay(10); // Short delay
  }
  
  delay(1000); // Wait for 1 second before repeating the cycle
}

