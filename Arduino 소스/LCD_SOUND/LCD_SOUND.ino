#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int sound_pin = A0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();  
  lcd.cursor();
  lcd.blink();
  lcd.home();
  lcd.setCursor(0,1);
  lcd.print("(-O-)");
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  Serial.print("sound value : ");
  Serial.println(sound_value);
  if(sound_value>=1000){
    lcd.scrollDisplayRight();
  }
}
