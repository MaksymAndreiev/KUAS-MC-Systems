#define SSN 10
#define MOSI 11
#define MISO 12
#define SCK 13


void setup() {
  Serial.begin(9600);
  pinMode(SSN, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(SCK, OUTPUT);
  digitalWrite(SSN, HIGH); // device inactive
  digitalWrite(SCK, LOW);
}

int readADC(unsigned char channel){
  digitalWrite(SSN, LOW); // low - inverted input
  sendBit(1);
  sendBit(1);
  sendBit(channel>>2);
  sendBit(channel>>1);
  sendBit(0);
  sendBit(0);

  int advalue = 0;
  for (int i= 0; i < 12; ++i){
    advalue = (advalue << 1) + recvBit();
  }
  digitalWrite(SSN, HIGH);
  return advalue;
}

void sendBit(int value){
  digitalWrite(MOSI, value & 1);
  digitalWrite(SCK, HIGH);
  digitalWrite(SCK, LOW);
}

int recvBit(void){
  digitalWrite(SCK, HIGH);
  int value = digitalRead(MISO);
  digitalWrite(SCK, LOW);
  return value;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(readADC(1));
  delay(250);
}
