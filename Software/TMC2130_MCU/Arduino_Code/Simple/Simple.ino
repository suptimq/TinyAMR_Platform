/**
 * Author Teemu Mäntykallio
 * Initializes the library and turns the motor in alternating directions.
 * Need to install https://github.com/teemuatlut/TMC2130Stepper for this to work, verified functionality on Arduino Uno
*/

#define EN_PIN    4  // Nano v3:	16 Mega:	38	//enable (CFG6)
#define DIR_PIN   5  //			19			55	//direction
#define STEP_PIN  6  //			18			54	//step
#define CS_PIN    10  //			17			64	//chip select

bool dir = true;

#include <TMC2130Stepper.h>
TMC2130Stepper driver = TMC2130Stepper(EN_PIN, DIR_PIN, STEP_PIN, CS_PIN);

void setup() {
	Serial.begin(9600);
	while(!Serial);
	Serial.println("Start...");
	SPI.begin();
	pinMode(MISO, INPUT_PULLUP);
	driver.begin(); 			// Initiate pins and registeries
	driver.rms_current(600); 	// Set stepper current to 600mA. The command is the same as command TMC2130.setCurrent(600, 0.11, 0.5);
	driver.stealthChop(1); 	// Enable extremely quiet stepping
	
	digitalWrite(EN_PIN, LOW);
}

float ms_delay = 0.1;

void loop() {
	digitalWrite(STEP_PIN, HIGH);
	delayMicroseconds(ms_delay);
	digitalWrite(STEP_PIN, LOW);
	delayMicroseconds(ms_delay);
	uint32_t ms = millis();
	static uint32_t last_time = 0;
	if ((ms - last_time) > 10000) {
    Serial.println(driver.microsteps());
		if (dir) {
			Serial.println("Dir -> 0");
			driver.shaft_dir(0);
		} else {
			Serial.println("Dir -> 1");
			driver.shaft_dir(1);
		}
		dir = !dir;
		last_time = ms;
	}
}
