void setup() {
  Serial.begin(115200);
}

int low = 1023;
int high = 0;

void loop() {
  int value = analogRead(A0);
  if (value <= low) low = value - 1;
  if (value >= high) high = value + 1;
  value = map(value, low, high, 0, 100);
  Serial.println(value);
  delay(250);
}
