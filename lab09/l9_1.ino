void setup() {
  for (int i = 0; i <= 12; i++){
    pinMode(i, OUTPUT);
  }
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void loop() {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(0, HIGH); delay(500);
  digitalWrite(0, LOW); delay(500);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(0, HIGH); delay(500);
  digitalWrite(0, LOW); delay(500);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(0, HIGH); delay(500);
  digitalWrite(0, LOW); delay(500);
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(0, HIGH); delay(500);
  digitalWrite(0, LOW); delay(500);
}
