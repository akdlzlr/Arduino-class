#include <Wire.h>
#include <LiquidCrystal_I2C.h>

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
  lcd.print("(^o^) (-_-)");
  lcd.setCursor(0,1);
  lcd.print("(-O-) (@_@)");
  delay(1000);
  lcd.clear();
  lcd.print("(ToT) (O_O)");
  lcd.setCursor(0,1);
  lcd.print("(>O<) ($_$)");
  delay(1000);
  lcd.clear();
    
}
