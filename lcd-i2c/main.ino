#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
	lcd.init();
	lcd.backlight();
}

void loop() {
	lcd.setCursor(random(16), random(2));
	lcd.print(char(random(int('a'), int('z') +1)));
	delay(30);
}
