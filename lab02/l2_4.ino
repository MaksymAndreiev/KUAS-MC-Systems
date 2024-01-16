void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    int value = analogRead(A0);
    // Serial.println(value);
    delay(250);
    digitalWrite(13, HIGH);
    delay(value);
    digitalWrite(13, LOW);
}
