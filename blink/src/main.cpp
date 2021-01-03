#include <Arduino.h>
const int ledPinBlink = 7;

void setup() {
  // put your setup code here, to run once:
  // start virtual serial communication
  Serial.begin(9600);
  // set outpin pin
  pinMode(ledPinBlink,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPinBlink, HIGH);
  delay(500);
  digitalWrite(ledPinBlink, LOW);
  delay(500);

}