void setup() {
	Serial.begin(9600);
	pinMode(2, OUTPUT);
	pinMode(3, INPUT);
}

void loop() {
	digitalWrite(2, LOW);
	delayMicroseconds(2);
	digitalWrite(2, HIGH);
	delayMicroseconds(10);
	digitalWrite(2, LOW);

	// while(!digitalRead(3));
	// unsigned long start = micros();
	// while(digitalRead(3));
	// unsigned long end = micros();
	// unsigned long total = end - start;
	long duration = pulseIn(3, HIGH);
	float distance = (duration / 2) / 29.1;

	if (distance < 0 || distance > 200) {
		Serial.println("Unknown.");
	} else {
		Serial.println(distance);
	}

	delay(500);
}
