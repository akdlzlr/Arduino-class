int notes[] = {262, 294, 330};

int pins[] = {5, 6, 7};

//            배열이름(12) / 자료형(4)
int pinSize = sizeof(pins)/sizeof(int);

void setup() {
  // put your setup code here, to run once:
  for(int i = 5; i<8;i++){
    pinMode(pins[i],INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<pinSize;i++){
    if(digitalRead(pins[i])==HIGH){
      tone(9, notes[i],100);
      delay(100);
      noTone(9);
    }
  }
}
