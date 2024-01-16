// Define the pin numbers for each segment
const int segA = 2;
const int segB = 3;
const int segC = 3;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
const int segDP = 9;

void setup() {
  // Set all the pins to OUTPUT mode
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}

void loop() {
  // Turn on each segment for one second, then turn it off
  digitalWrite(segA, HIGH);
  delay(1000);
  digitalWrite(segA, LOW);

  digitalWrite(segB, HIGH);
  delay(1000);
  digitalWrite(segB, LOW);

  digitalWrite(segC, HIGH);
  delay(1000);
  digitalWrite(segC, LOW);

  digitalWrite(segD, HIGH);
  delay(1000);
  digitalWrite(segD, LOW);

  digitalWrite(segE, HIGH);
  delay(1000);
  digitalWrite(segE, LOW);

  digitalWrite(segF, HIGH);
  delay(1000);
  digitalWrite(segF, LOW);

  digitalWrite(segG, HIGH);
  delay(1000);
  digitalWrite(segG, LOW);

  digitalWrite(segDP, HIGH);
  delay(1000);
  digitalWrite(segDP, LOW);
}
