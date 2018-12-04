int g, y, r;
int btn1, btn2,btn3,btn4;

void setup() {
  // put your setup code here, to run once:
  g=9;
  y=10;
  r=11;
  
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  btn1 = digitalRead(5);
  btn2 = digitalRead(6);
  btn3 = digitalRead(7);
  btn4 = digitalRead(8);
  
  if(btn1 == HIGH){
    
    ledClear();
    analogWrite(r,255);
    
    for(int i=0;i<6;i++){
      Serial.println("Btn1 High");
      analogWrite(y,255);
      delay(500);
      analogWrite(y,0);
      delay(500);
    }
  }
  
  if(btn2 == HIGH){
    
    ledClear();
    analogWrite(g,255);
    
    for(int i=0;i<6;i++){
      Serial.println("Btn1 High");
      analogWrite(y,255);
      delay(500);
      analogWrite(y,0);
      delay(500);
    }
  }
  
  if(btn3 == HIGH){
    ledClear();
    
    for(int i=0;i<4;i++){
      for(int j=9;j<12;j++){
        analogWrite(j,255);
        delay(200);
      }
      for(int j=11;j>8;j--){
        analogWrite(j,0);
        delay(200);
      }
      if(i%2!=0){
        for(int i =0; i<4; i++){
          ledAllOn();
          delay(200);
          ledClear();
          delay(200);
        }
      }
    }
  }

  if(btn4 == HIGH){
    ledClear();
    for(int i=9; i<12;i++){
      for(int j=0; j<=255; j++){
        analogWrite(i,j);
        delay(20);
      }
    }
     for(int i=11; i>8;i--){
      for(int j=255; j>=0; j--){
        analogWrite(i,j);
        delay(20);
      }
    }
  }
}

void ledClear(){
    analogWrite(r,0);
    analogWrite(g,0);
    analogWrite(y,0);
}

void ledAllOn(){
    analogWrite(r,255);
    analogWrite(g,255);
    analogWrite(y,255);
}
