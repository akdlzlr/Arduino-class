void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A1);
  int ledLight = map(light, 10, 900, 0,255);
  int ledLight2 = map(light, 10, 900, 0, 4000);
  analogWrite(10, ledLight);
  tone(9, ledLight2,100);
  delay(100);
  noTone(9);
  Serial.println(light);
  if(light>=500){
    digitalWrite(11,HIGH);
  }else{
    digitalWrite(11,LOW);
  }
}
