
int sound_pin = A0;
int y = 8;
int g = 9;
int r = 10;
int num=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(r,OUTPUT);
  Serial.begin(9600);
  digitalWrite(y,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  Serial.print("sound value : ");
  Serial.println(sound_value);
  if(sound_value>=1000){
    num++;
  }
  if(num>5){
    digitalWrite(g,HIGH);
  }
  if(num>10){
    digitalWrite(r,HIGH);
  }
  delay(100);
}
