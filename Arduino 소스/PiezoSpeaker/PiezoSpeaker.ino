enum piano{
  DO = 262,
  RE = 294,
  MI = 330,
  FA = 349,
  SOL = 392,
  RA = 440,
  SI = 494,
  DO2 = 523
};

int melody[] = {
  DO, RE, MI, DO, MI, DO, MI,
  RE, MI, FA, FA, MI, RE, FA,
  MI, FA, SOL, MI, SOL, MI, SOL,
  FA, SOL, RA, RA, SOL, FA, RA,
  SOL, DO, RE, MI, FA, SOL, RA,
  RA, RE, MI, FA, SOL, RA, SI,
  SI, MI, FA, SOL, RA, SI, DO2,
  DO2, SI, RA, FA, SI, SOL, DO2
};

void setup() {
  // put your setup code here, to run once:
  for( int i =0; i<sizeof(melody)/sizeof(int);i++){
    tone(9,melody[i],100);
    delay(150);
    noTone(9);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*   
  아날로그로 소리 내기
  analogWrite(pzo,64);
  delay(250);
  analogWrite(pzo,128);
  delay(250);
  analogWrite(pzo,255);
  delay(250);
  */
}
