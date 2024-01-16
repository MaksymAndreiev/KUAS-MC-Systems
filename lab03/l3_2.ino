void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potential = analogRead(A1); 
  digitalWrite(12, HIGH);
  delayMicroseconds(1000 + potential);
  digitalWrite(12, LOW);
}
