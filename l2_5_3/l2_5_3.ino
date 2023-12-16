void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int delayTime = 250;

void loop() {
  if (Serial.available() > 0){
    int digit = Serial.read();
    if (digit == '0') delayTime = 0;
    if (digit == '1') delayTime = 100;
  }
  delay(delayTime);
  digitalWrite(13, HIGH);
  delay(delayTime);
  digitalWrite(13, LOW);
}
