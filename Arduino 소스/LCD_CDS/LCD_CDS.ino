#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig_pin = 2;
int echo_pin = 3;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();  
  lcd.cursor();
  lcd.blink();
  lcd.home();

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int light = analogRead(A0);
  lcd.print("light : ");
  lcd.print(light);
  
  lcd.setCursor(0,1);
  lcd.print("distance : ");
  
  lcd.print(getDistance(trig_pin, echo_pin));
  delay(1000);
  
  lcd.clear();
}

long getDistance(int aTrig_pin, int aEcho_pin){
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin,HIGH);
  long distance = duration/58.2;
  return distance;
}
