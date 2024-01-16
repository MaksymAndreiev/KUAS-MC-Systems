void setup() {
  Serial.begin(9600);
  for (int i = 2; i<6; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int a0 = analogRead(A0);
  a0 = map(a0, 0, 1023, 0, 100);
  Serial.println(a0);
  if (a0>=20) digitalWrite(2, HIGH); else digitalWrite(2, LOW);
  if (a0>=40) digitalWrite(3, HIGH); else digitalWrite(3, LOW);
  if (a0>=60) digitalWrite(4, HIGH); else digitalWrite(4, LOW);
  if (a0>=80) digitalWrite(5, HIGH); else digitalWrite(5, LOW);
}
