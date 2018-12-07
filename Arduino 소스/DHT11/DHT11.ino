#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int DHT11PIN = A0;            //Signal 이 연결된 아두이노의 핀번호
 
dht11 DHT11;
  
void setup()
{
  Serial.begin(9600);  //시리얼 통신속도 설정
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  lcd.begin();
  lcd.backlight();  
  lcd.cursor();
  lcd.blink();
  lcd.home();
}
  
void loop()
{
  int chk = DHT11.read(DHT11PIN);
  float T=(float)DHT11.temperature;
  float RH = (float)DHT11.humidity;
  Serial.print("Temp: ");
  Serial.print(T);
  Serial.print(" C ");
   
  Serial.print("/ RelF: ");
  Serial.print(RH);
  Serial.print(" %");

   int discomfort_index = ((9/5)*T)-(0.55*(1-(RH/100))*((9/5)*T-26))+32;
  Serial.print("/ 불쾌지수 : ");
  Serial.print(discomfort_index); 
  Serial.println();  
  lcd.home();
  lcd.print("T = ");
  lcd.print((int)T);
  lcd.print("C,");
  
  lcd.print("RH = ");
  lcd.print((int)RH);
  lcd.print("% ");

  lcd.setCursor(0,1);
  
  lcd.print("DI = ");
  lcd.print(discomfort_index);

  if(discomfort_index>=80){
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }else if(discomfort_index>=75){
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }else if(discomfort_index>=68){
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
  }else{
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
  
  
  delay(1000);
}
