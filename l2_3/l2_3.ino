void setup() {
  Serial.begin(9600);
}

int count = 1;

void loop() {
  Serial.println(count, BIN);
  count += 1;
  delay(250);
}
