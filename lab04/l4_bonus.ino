void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

int low = 1023;
int high = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  int potential = analogRead(A1);  
  if (value <= low) low = value - 1;
  if (value >= high) high = value + 1;
  value = map(value, low, high, 0, 100);
  potential = map(potential, 0, 1023, 0, 100);
  int thr = potential;
  if (value > thr){noTone(12);}
  else {tone(12, 550*value/100);}
  
}
