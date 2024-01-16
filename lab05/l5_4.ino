void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  int ta = analogRead(A0);
  int tb = 1023 - ta;
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delayMicroseconds(ta);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delayMicroseconds(tb);
}