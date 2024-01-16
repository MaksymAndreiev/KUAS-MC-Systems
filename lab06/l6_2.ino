void setup() {
  for (int i = 2; i<6; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 2; i < 6; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  for (int i = 5; i > 1; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}
