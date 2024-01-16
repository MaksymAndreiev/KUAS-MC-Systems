void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int value0 = analogRead(A0);
  int value1 = analogRead(A1);
  Serial.print("Value of A0: ");
  Serial.print(value0);
  Serial.print(", value of A1: ");
  Serial.print(value1);
  Serial.println();
  delay(700);
}

