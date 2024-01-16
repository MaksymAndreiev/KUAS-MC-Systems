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
  for(int i=2; i<=8; i++) {
    // Get the (i-2)-th bit of the pattern (0th bit is the rightmost one)
    bool bit = (pattern >> (i-2)) & 1;
    // Set the i-th pin according to the (i-2)-th bit of the pattern
    digitalWrite(i, bit);
  }
}

void setup() {
  for (int i=2; i<10; i++){
    pinMode(i, OUTPUT);
  }
}

int counter = 0;

void loop() {
  displayDigit(counter++);
  delay(1000);
  if (counter == 9) counter = 0;
  // setLEDs(0b0101101);
}
