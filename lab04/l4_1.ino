void setup() {
  Serial.begin(115200);
}

void loop(){
  int value = analogRead(A0);
  Serial.println(value);
}
