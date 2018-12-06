#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD 주소 설정?
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  lcd.cursor();
  lcd.blink();
  lcd.home();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("H");
  delay(500);
  lcd.print("e");
  delay(500);
  lcd.print("l");
  delay(500);
  lcd.print("l");
  delay(500);
  lcd.print("o");
  delay(500);
  lcd.print(" ");
  delay(500);
  lcd.print("W");
  delay(500);
  lcd.print("o");
  delay(500);
  lcd.print("r");
  delay(500);
  lcd.print("l");
  delay(500);
  lcd.print("d");
  delay(1000);
  for(int i=0;i<40;i++){
    lcd.scrollDisplayLeft();
    delay(400);
  }
  delay(1000);
  lcd.clear();
}
