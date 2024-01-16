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
  digitalWrite(D, HIGH);  // Set D to ‘1’ (HIGH)
  posPulse(CLK);          // Shift D into the register by generating a positive pulse on CLK
  digitalWrite(D, LOW);   // Set D to ‘0’ (LOW)

  for(int i = 0; i < 8; i++) { // Repeat eight times
    delay(100);                // generate a delay for 100 ms
    posPulse(CLK);             // Shift D into the register by generating a positive pulse on CLK
  }
  delay(500); // generate a delay for 500 ms
}
