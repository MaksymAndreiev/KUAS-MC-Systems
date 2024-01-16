void setup() {
  for (int i = 0; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void setLED(int segment, int colour) {
  if (0 == colour) 
    digitalWrite(segment, LOW);    // disable
  else 
    digitalWrite(segment, HIGH);                // enable
  if (0 == (colour & 1)) 
    digitalWrite(12, HIGH);  // red off
  else 
    digitalWrite(12, LOW);                      // red on
  if (0 == (colour & 2)) 
    digitalWrite(10, HIGH);  // green off
  else 
    digitalWrite(10, LOW);                      // green on
  if (0 == (colour & 4)) digitalWrite(11, HIGH);  // blue off
  else digitalWrite(11, LOW);                      // blue on
}

void loop(void) {
  for (int segment = 0; segment < 10; segment += 1) {
    int colour = 2;                // green
    if (segment >= 6) colour = 3;  // yellow
    if (segment >= 9) colour = 1;  // red
    setLED(segment, colour);       // ON
    delay(1);                      // wait a little
    setLED(segment, 0);            // OFF
  }
}
