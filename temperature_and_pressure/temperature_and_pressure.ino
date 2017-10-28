#include <Wire.h>
#include "Adafruit_MCP9808.h"
#include "SFE_BMP180.h"

#define ALTITUDE 165.0

Adafruit_MCP9808 temperature = Adafruit_MCP9808();
SFE_BMP180 pressure;

void setup() {
	Serial.begin(9600);
	if (!temperature.begin(0x19)) {
		Serial.println("Error: Can't find MCP9808.");
		while(1);
	}
	if (!pressure.begin()) {
		Serial.println("Error: Can't find BMP180.");
		while(1);
	}
}

float readTemperatureMCP() {
	return temperature.readTempF();
}

double readTemperatureBMP() {
	char status;
	double result;

	status = pressure.startTemperature();
	if (status != 0) {
		delay(status);
		status = pressure.getTemperature(result);

		if (status != 0) {
			return result;
		}
	}

	Serial.println("Error: Can't read temperature from BMP180.")
	return 0.0;
}

double readPressureBMP(double temperature) {
	char status;
	double result;

	status = pressure.startPressure(3);
	if (status != 0) {
		delay(status);
		status = pressure.getPressure(result, temperature);

		if (status != 0) {
			return result;
		}
	}

	Serial.println("Error: Can't read pressure from BMP180.")
	return 0.0;
}



void loop() {
	temperature.shutdown_wake(0);

	float f1 = readTemperatureMCP();
	double c2 = readTemperatureBMP();
	double f2 = c2 * (9.0 / 5.0) + 32.0;
	double p = readPressureBMP(c2);
	double rp = pressure.sealevel(p, ALTITUDE);

	Serial.println("------------------------------------");

	Serial.print("Temp: ");
	Serial.print(f1, 2);
	Serial.print("/");
	Serial.print(f2, 2);
	Serial.print("F");
	Serial.print("\n");

	Serial.print("Provided Altitude: ");
	Serial.print(ALTITUDE, 0);
	Serial.print(" meters, ");
	Serial.print(ALTITUDE * 3.28084, 0);
	Serial.print(" feet");
	Serial.print("\n");

	Serial.print("Absolute Pressure: ");
	Serial.print(p, 2);
	Serial.print(" mb, ");
	Serial.print(p * 0.0295333, 2);
	Serial.print(" inHg");
	Serial.print("\n");

	Serial.print("Relative Pressure: ");
	Serial.print(rp, 2);
	Serial.print(" mb, ");
	Serial.print(rp * 0.0295333, 2);
	Serial.print(" inHg");
	Serial.print("\n");

	temperature.shutdown_wake(1);
	delay(2000);
}
