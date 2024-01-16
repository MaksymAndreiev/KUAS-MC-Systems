#include <SPI.h>

#define SSN 10


void setup() {
  Serial.begin(9600);
  pinMode(SSN, OUTPUT);
  digitalWrite(SSN, HIGH); // device inactive
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16); // 1MHz
  SPI.setDataMode(SPI_MODE0); // low, rising  _|
  SPI.setBitOrder(MSBFIRST);
}

int readADC(unsigned char channel){
  digitalWrite(SSN, LOW); // low - inverted input
  int adval = 0;
  SPI.transfer(0b00000110 + ((channel >> 2) & 1));
  adval =  ((unsigned char)SPI.transfer(channel << 6) & 0b00001111) << 8;
  adval |= ((unsigned char)SPI.transfer(0));
  digitalWrite(SSN, HIGH);
  return adval;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(readADC(2));
  delay(250);
}
