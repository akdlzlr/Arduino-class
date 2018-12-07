#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(13);
  pinMode(A5,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(A5)==HIGH){
  int val = analogRead(A0);
  int rad = map(val, 0, 1023, 0 ,180);
  myservo.write(rad);
  delay(15);
  }
}
