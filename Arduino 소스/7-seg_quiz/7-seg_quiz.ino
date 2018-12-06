
int seg[]={6,7,8,9,10,11,12};
int sel[]={5,4,3,2};

int num=0;
int alert=15;
int cnt=0;

byte digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<=12;i++){
    pinMode(i,OUTPUT);
  }
  
  pinMode(A0,OUTPUT);
  
  digitalWrite(sel[0],HIGH);
  digitalWrite(sel[1],HIGH);
  digitalWrite(sel[2],HIGH);
  digitalWrite(sel[3],HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = millis()/1000;
  int val1 = val%10;
  int val2 = (val/10)%10;
  
  if(val==15){
    tone(A0, 3542,1000);
    delay(1000);
    noTone(A0);
  }
  
  if(cnt>1){
    cnt=0;
  }

  if(cnt==0){
    selSeg(0);
    displayDigit(val1);
  }
  if(cnt==1){
    selSeg(1);
    displayDigit(val2);
  }
  delay(10);
  cnt++;
}

void displayDigit(int num){
  int pin =6;
  for(int i =0 ;i <=12;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}

void selSeg(int num){
  digitalWrite(sel[0],HIGH);
  digitalWrite(sel[1],HIGH);
  digitalWrite(sel[2],HIGH);
  digitalWrite(sel[3],HIGH);
  
  digitalWrite(sel[num],LOW);
}
