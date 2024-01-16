void setup()
{
Serial.begin(9600);
}
void loop()
{
int value = analogRead(A0);
value = map(value, 0, 1023, 0, 500); // temp in Celsius
Serial.println(value);
delay(250);
}
