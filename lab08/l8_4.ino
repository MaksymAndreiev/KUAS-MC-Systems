void displayDigit(int digit){
  if (0 == digit) setLEDs(0b0111111);
  if (1 == digit) setLEDs(0b0000110);
  if (2 == digit) setLEDs(0b1011011);
  if (3 == digit) setLEDs(0b1001111);
  if (4 == digit) setLEDs(0b1100110);
  if (5 == digit) setLEDs(0b1101101);
  if (6 == digit) setLEDs(0b1111101);
  if (7 == digit) setLEDs(0b0000111);
  if (8 == digit) setLEDs(0b1111111);
  if (9 == digit) setLEDs(0b1101111);
}

void setLEDs(long pattern) {
  for (int i = 4; i <= 11; i++) {
    bool bit = (pattern >> (i - 4)) & 1;
    digitalWrite(i, bit);
  }
}

void setup() {
  for (int i = 4; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

int counter = 15000;
int oldState2 = HIGH;
int oldState3 = HIGH;

void loop() {
  int newState2 = digitalRead(2);
  int newState3 = digitalRead(3);

  if (oldState2 == HIGH && newState2 == LOW) {
    counter = counter + 1;
    displayDigit(counter % 10);
  }

  if (oldState3 == HIGH && newState3 == LOW) {
    counter = counter + 1;
    displayDigit(counter % 10);
  }

  oldState2 = newState2;
  oldState3 = newState3;
}
