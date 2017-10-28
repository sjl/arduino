#include <LiquidCrystal.h>
// #include "DHT.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// DHT dht(7, DHT22);

byte degrees[8] = {
	0b01000,
	0b10100,
	0b01000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
byte drop[8] = {
	0b00000,
	0b00100,
	0b01110,
	0b01110,
	0b11111,
	0b11111,
	0b01110,
	0b00000
};
#define DEGREES 0
#define DROP 1

void setup() {
	lcd.begin(16, 2);
	lcd.createChar(DEGREES, degrees);
	lcd.createChar(DROP, drop);
	// lcd.setCursor(0, 1);
	// lcd.print("in Rochester, NY");
	dht.begin();
}

void writeIcon(int icon, int x, int y) {
	lcd.setCursor(x, y);
	lcd.write((uint8_t) icon);
}

void loop() {
	// float humidity = dht.readHumidity();
	// float temperature = dht.readTemperature() * (9.0 / 5.0) + 32;

	// lcd.setCursor(0, 0);
	// if (isnan(humidity) || isnan(humidity)) {
	// 	lcd.print("Error.");
	// } else {
	// 	lcd.print(temperature, 1);
	// 	writeIcon(DEGREES, 4, 0);
	// 	lcd.print("F");
	// 	lcd.setCursor(10, 0);
	// 	lcd.print(humidity, 1);
	// 	lcd.print("%");
	// 	writeIcon(DROP, 15, 0);
	// }

	lcd.setCursor(random(16), random(2));
	lcd.print(char(random(int('a'), int('z') +1)));
	delay(20);
}
