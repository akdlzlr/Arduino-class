int a, b, c;

void setup() {
  // put your setup code here, to run once:
  a=9;
  b=10;
  c=11;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=9;i<=11;i++){
    for(int j=0;j<=255;j++){
      analogWrite(i,j);
      delay(10);
    }
    for(int j=255;j>=0;j--){
      analogWrite(i,j);
      delay(10);
    }
  }
}
