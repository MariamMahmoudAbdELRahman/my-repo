#include <Wire.h>

const int ledPin = 9;  // Pin for the indicator LED

void setup() {
  Wire.begin(9);  // Set I2C address to 9
  Wire.onReceive(receiveEvent);
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Do other tasks
}

void receiveEvent(int numBytes) {
  if (numBytes >= 2) {
    int buttonState1 = Wire.read();
    int buttonState2 = Wire.read();
    
    int intensity = 0;
    String message = "No message";
    
    if (buttonState1 == HIGH && buttonState2 == LOW) {
      intensity = 50;
      message = "Vector focused";
    } else if (buttonState1 == LOW && buttonState2 == HIGH) {
      intensity = 75;
      message = "Vector distracted";
    } else if (buttonState1 == HIGH && buttonState2 == HIGH) {
      intensity = 100;
      message = "Glitch";
    }
    
    analogWrite(ledPin, map(intensity, 0, 100, 0, 255));
    Serial.println(message);
  }
}
