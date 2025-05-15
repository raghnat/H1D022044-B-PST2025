#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D5;
int SCL_pin = D7;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sulawesi");
  lcd.setCursor(0,1);
  lcd.print("Utara");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(500);
}

