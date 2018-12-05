/* 초음파 거리센서로 거리를 출력하는 회로와 코드를 작성해보자.
   측정된 거리에 따른 LED 제어
   단, LED는 버튼이 눌린 상태에서 점등 */

int r,g;

void setup() {
  // put your setup code here, to run once:
  r=11;
  g=10;
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(5,INPUT);
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  
  long duration = pulseIn(3,HIGH);
  long distance = duration/58.2;
  
  Serial.println(distance);
  Serial.println(digitalRead(5));
  if(digitalRead(5)==HIGH){
    if(5 <= distance && distance<10){
      digitalWrite(g,HIGH);
      digitalWrite(r,LOW);
    }else{
      digitalWrite(g,LOW);
      digitalWrite(r,HIGH);
    }
  }else{
    digitalWrite(g,LOW);
    digitalWrite(r,LOW);
  }
}
