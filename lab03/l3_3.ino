void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potential = analogRead(A1); 
  tone(12, 1000 + potential);
  //noTone(12);
}
