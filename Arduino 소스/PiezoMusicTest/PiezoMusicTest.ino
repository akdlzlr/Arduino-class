#define C 262   // 도
#define D 294   // 레
#define E 330   // 미
#define F 349   // 파
#define G 392   // 솔
#define A 440   // 라
#define B 494   // 시
#define H 523   // 높은 도

int melody[]={G,G,A,A,G,G,E,G,G,E,E,D,G,G,A,A,G,G,E,G,E,D,E,C};

int melodySize = sizeof(melody)/sizeof(int);

void setup() {
  // put your setup code here, to run once:
  pinMode(5,INPUT);
  pinMode(6,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5) == HIGH){
    for(int i=0;i<melodySize/2;i++){
      tone(9,melody[i],100);
      delay(100);
    }
  }else if(digitalRead(6) == HIGH){
    for(int i=melodySize/2;i<melodySize;i++){
      tone(9,melody[i],100);
      delay(100);
    }
  }
}
