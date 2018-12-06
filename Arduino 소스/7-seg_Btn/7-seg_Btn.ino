
int seg[]={6,7,8,9,10,11,12};
int sel[]={2,3,4,5};

int num=0;

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
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);

  digitalWrite(sel[0],HIGH);
  digitalWrite(sel[1],HIGH);
  digitalWrite(sel[2],HIGH);
  digitalWrite(sel[3],LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = digitalRead(A4);
  int b = digitalRead(A5);

  if(a==HIGH){
    num++;
    if(num>9){
      num=0;
    }
  }
  if(b==HIGH){
    num--;
    if(num<0){
      num=9;
    }
  }
  
  displayDigit(num);
  delay(100);
}

void displayDigit(int num){
  int pin =6;
  for(int i =0 ;i <=12;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}
