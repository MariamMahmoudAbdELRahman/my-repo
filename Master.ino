#include <Wire.h>

const int button1Pin = 2;
const int button2Pin = 3;

void setup() {
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  
  Wire.begin();
}

void loop() {
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  
  Wire.beginTransmission(9); // I2C address of the receiver
  Wire.write(button1State);
  Wire.write(button2State);
  Wire.endTransmission();
  
  delay(100);
}