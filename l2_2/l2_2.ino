void setup() {
  Serial.begin(9600);
}

int count = 1;

void loop() {
  Serial.println(count);
  count += 1;
  delay(250);
}
