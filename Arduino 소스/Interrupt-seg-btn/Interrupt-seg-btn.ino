int btn1_pin = 2;
volatile boolean count1 = true;

int seg[]={6,7,8,9,10,11,12};
int sel[]={A1,3,4,5};

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
  Serial.begin(9600);
  pinMode(btn1_pin, OUTPUT);
 for(int i=2;i<=12;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(sel[1],HIGH);
  digitalWrite(sel[2],HIGH);
  digitalWrite(sel[3],LOW);
  
  
  attachInterrupt(0, btn1ISR, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
 displayDigit(num);
 delay(1000);
 if(count1==true){
    num++;
    if(num>9){
      num=0;
    }
 }else{
  num--;
  if(num<0){
    num=9;
  }
 }
}

void displayDigit(int num){
  int pin =6;
  for(int i =0 ;i <=12;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}

void btn1ISR(){
  delayMicroseconds(10);
  count1 = !count1;
  delayMicroseconds(10);
  Serial.print("count1 : ");
  Serial.println(count1);
}
