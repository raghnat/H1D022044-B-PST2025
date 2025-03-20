#include <Arduino.h>

// Variable
int redLed = D0;
int yellowLed = D3;
int greenLed = D4;

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
pinMode(redLed,OUTPUT);
pinMode(yellowLed,OUTPUT);
pinMode(greenLed,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLed,HIGH);
  delay(100);
  digitalWrite(redLed,LOW);
  digitalWrite(yellowLed,HIGH);
  delay(100);
  digitalWrite(yellowLed,LOW);
  digitalWrite(greenLed,HIGH);
  delay(100);
  digitalWrite(greenLed,LOW);
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}