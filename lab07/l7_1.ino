void setup() {
  DDRD = 0b11111111;
  DDRB = 0b00111111;
  DDRC = 0b00111111;
}

void setLEDs(long pattern) {
  if (0b000000000000000000001 & pattern) digitalWrite(0, HIGH);  else digitalWrite(0, LOW);
  if (0b000000000000000000010 & pattern) digitalWrite(1, HIGH);  else digitalWrite(1, LOW);
  if (0b000000000000000000100 & pattern) digitalWrite(2, HIGH);  else digitalWrite(2, LOW);
  if (0b000000000000000001000 & pattern) digitalWrite(3, HIGH);  else digitalWrite(3, LOW);
  if (0b000000000000000010000 & pattern) digitalWrite(4, HIGH); else digitalWrite(4, LOW);
  if (0b000000000000000100000 & pattern) digitalWrite(5, HIGH);else digitalWrite(5, LOW);
  if (0b000000000000001000000 & pattern) digitalWrite(6, HIGH);else digitalWrite(6, LOW);
  if (0b000000000000010000000 & pattern) digitalWrite(7, HIGH);else digitalWrite(7, LOW);
  if (0b000000000000100000000 & pattern) digitalWrite(8, HIGH);else digitalWrite(8, LOW);
  if (0b000000000001000000000 & pattern) digitalWrite(9, HIGH);else digitalWrite(9, LOW);
  if (0b000000000010000000000 & pattern) digitalWrite(10, HIGH);else digitalWrite(10, LOW);
  if (0b000000000100000000000 & pattern) digitalWrite(11, HIGH);else digitalWrite(11, LOW);
  if (0b000000001000000000000 & pattern) digitalWrite(12, HIGH);else digitalWrite(12, LOW);
  if (0b000000010000000000000 & pattern) digitalWrite(13, HIGH);  else digitalWrite(13, LOW);
  if (0b000000100000000000000 & pattern) digitalWrite(14, HIGH);  else digitalWrite(14, LOW);
  if (0b000001000000000000000 & pattern) digitalWrite(15, HIGH);  else digitalWrite(15, LOW);
  if (0b000010000000000000000 & pattern) digitalWrite(16, HIGH);  else digitalWrite(16, LOW);
  if (0b000100000000000000000 & pattern) digitalWrite(17, HIGH);  else digitalWrite(17, LOW);
  if (0b001000000000000000000 & pattern) digitalWrite(18, HIGH);  else digitalWrite(18, LOW);
  if (0b010000000000000000000 & pattern) digitalWrite(19, HIGH);  else digitalWrite(19, LOW);
  if (0b100000000000000000000 & pattern) digitalWrite(20, HIGH); else digitalWrite(20, LOW);
}

int counter;

void loop() {
  // for (long i = 0; i < 20; i++) {
  //   setLEDs(1 << i);
  //   delay(100);
  // }
  // for (long i = 19; i >= 0; i--) {
  //   setLEDs(1 << i);
  //   delay(100);
  // }
  // // setLEDs(1);
  for (counter = 0; counter < int(pow(2, 20)); counter++){
    setLEDs(counter);
  }
  // counter += 1;
  delay(100);
}
