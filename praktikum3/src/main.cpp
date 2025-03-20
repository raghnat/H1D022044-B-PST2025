#include <Arduino.h>

// put function declarations here:
int trigPin = D0;
int echoPin = D1;

int led1 = D2;



long duration;
long distance;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  // test
  // digitalWrite(led1,HIGH);
  // delay(500);
  // digitalWrite(led1,LOW);

  duration= pulseIn(echoPin,HIGH);
  distance= 0.034 * duration / 2;

  Serial.print("Jarak ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10)
  {
    digitalWrite(led1,HIGH);
  }else
  {
    digitalWrite(led1,LOW);
  }
  delay(1000);
}

