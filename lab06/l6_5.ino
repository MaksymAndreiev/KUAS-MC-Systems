void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void setLEDs(int pattern) {
  Serial.println(pattern, BIN);
  if (0b0001 & pattern) digitalWrite(2, HIGH);
  else digitalWrite(2, LOW);
  if (0b0010 & pattern) digitalWrite(3, HIGH);
  else digitalWrite(3, LOW);
  if (0b0100 & pattern) digitalWrite(4, HIGH);
  else digitalWrite(4, LOW);
  if (0b1000 & pattern) digitalWrite(5, HIGH);
  else digitalWrite(5, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  setLEDs(0b0000);
  delay(100);
  setLEDs(0b0010);
  delay(100);
  // setLEDs(0b0011);
  // delay(100);
  setLEDs(0b0100);
  delay(100);
  // setLEDs(0b0101);
  // delay(100);
  setLEDs(0b1000);
  // delay(100);
  // setLEDs(0b1001);
  // delay(100);
  // setLEDs(0b1010);
  // delay(100);
  // setLEDs(0b1011);
  // delay(100);
  // setLEDs(0b1100);
  // delay(100);
  // setLEDs(0b1101);
  // delay(100);
  setLEDs(0b1111);
  delay(1000);
}
