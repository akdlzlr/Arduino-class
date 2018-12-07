int btn1_pin = 2;
int btn2_pin = 3;

volatile int count1 = 0;
volatile int count2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn1_pin, OUTPUT);

  attachInterrupt(0, btn1ISR, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop 실행 중");
  delay(100);
}

void btn1ISR(){
  count1 +=1;
  Serial.print("count1 : ");
  Serial.println(count1);
}
