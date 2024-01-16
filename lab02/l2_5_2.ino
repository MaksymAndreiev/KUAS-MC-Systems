void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    int value = analogRead(A0);
    Serial.print("Value: ");
    Serial.println(value);
    delay(700);
    float voltrage = value / 1023. * 5.;
    Serial.print("Voltrage: ");
    Serial.println(voltrage);
    delay(700);
}

