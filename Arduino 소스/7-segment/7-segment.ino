
int seg[]={6,7,8,9,10,11,12};
int sel[]={2,3,4,5};

byte digits[10][7] =
{
 {1,1,1,1,1,1,0},
 {0,1,1,0,0,0,0},
 {1,1,0,1,1,0,1},
 {1,1,1,1,0,0,1},
 {0,1,1,0,0,1,1},
 {1,0,1,1,0,1,1},
 {1,0,1,1,1,1,1},
 {1,1,1,0,0,0,0},
 {1,1,1,1,1,1,1},
 {1,1,1,0,0,1,1} 
};

int cnt=0;
int num=0;
int num2=0;

void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<=12;i++){
    pinMode(i,OUTPUT);
  }

  digitalWrite(sel[2],HIGH);
  digitalWrite(sel[3],HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(cnt==100){
    num++;
    if(num==10){
      num2++;
      num=0;
    }
    cnt=0;
  }
  
  if(cnt%2 ==0){
    digitalWrite(sel[0],LOW);
    digitalWrite(sel[1],HIGH);
    displayDigit(num2);
    delay(10);
    cnt++;
  }
  if(cnt%2==1){
    digitalWrite(sel[0],HIGH);
    digitalWrite(sel[1],LOW);
    displayDigit(num);
    delay(10);
    cnt++;
  }  
}

void displayDigit(int num){
  int pin =6;
  for(int i =0 ;i <=12;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}
