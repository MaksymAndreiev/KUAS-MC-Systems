float mymap(float value, float inMin, float inMax, float outMin, float outMax){
  float result = (value - inMin)*(outMax - outMin)/(inMax - inMin) + outMin;
  return result;
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  int value = analogRead(A0);
  value = mymap(value, 0, 1023, 0, 500); // temp in Celsius
  Serial.println(value);
  delay(250);
}
