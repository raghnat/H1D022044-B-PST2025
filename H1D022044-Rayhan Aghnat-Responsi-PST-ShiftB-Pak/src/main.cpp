#include <Arduino.h>
#include <Servo.h>


// Variabel
int ledHijau = D0;
int ledMerah = D4;
// ultrasonic sensor
int trigPin = D1;
int echoPin = D2;
long duration;
long distance;
long distanceM;

// servo
Servo myservo;


void setup() {
  //ultrasonic
  pinMode(ledHijau,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600); 
  // servo
  myservo.attach(D3);
  Serial.begin(9600);
}

void loop() {
  // mengaktifkan sensor
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  // rumus hitung jarak dalam cm
  duration= pulseIn(echoPin,HIGH);
  distance= 0.034 * duration / 2;
  distanceM = distance/100;
  
  // keterangan jarak
  Serial.print("Jarak ");
  Serial.print(distanceM);
  Serial.println(" m");

  if (distanceM <= 1.5)
  {
    digitalWrite(ledMerah,LOW);
    digitalWrite(ledHijau,HIGH);

    for(int pos=0; pos<=180; pos++){
      myservo.write(pos);
      delay(10);
     }
  }
  else{
    digitalWrite(ledHijau,LOW);
    digitalWrite(ledMerah,HIGH);

    for(int pos=180; pos>=0; pos--){
      myservo.write(pos);
      delay(10);
     }
  }
}

