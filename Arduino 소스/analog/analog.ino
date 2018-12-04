int a=0;
boolean b = true;
void setup() {
  // put your setup code here, to run once:
 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(b == true){
    analogWrite(9,a);
    delay(20);
    a-=1;
    if(a<=0){
      b=false;
    }
  }else{
   analogWrite(9,a);
   delay(20);
   a+=1;
   if(a>=255){
    b=true;
   }
  }
}
