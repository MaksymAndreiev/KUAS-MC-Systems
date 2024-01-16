void setup() {
  DDRD = 0b11111111;
  DDRB = 0b00111111; 
  DDRC = 0b00111111; 
}

void setLEDs(long leds) {
  PORTD = leds; 
  PORTB = (leds >> 8) & 0b00111111;
  PORTC = (leds >> 14) & 0b00111111; 
}

void loop() {
  for(long i = 0; i < (1L << 20); i++) {
    setLEDs(i);
    delay(1); 
  }
}