int trig_pin = 2;
int echo_pin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin,HIGH);
  long distance = duration/58.2;

  Serial.println(distance);
  if(distance<10){
    tone(9,1000,100);
    delay(100);
    noTone(9);
  }else if(distance <20){
    tone(9,1000,100);
    delay(200);
    noTone(9);
  }
}
