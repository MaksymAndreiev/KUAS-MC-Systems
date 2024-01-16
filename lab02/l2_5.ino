void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    int value = analogRead(A0);
    Serial.print("Value: ");
    Serial.println(value);
    delay(3000);
    float angle = value / 1023. * 270.;
    Serial.print("Angle: ");
    Serial.println(angle);
    delay(3000);
}
