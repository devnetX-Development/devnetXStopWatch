#include <Arduino.h>
#include <devnetXStopWatch.h>

devnetXStopWatch SW;

void setup()
{
	// Init Serial
	Serial.begin(115200);
	Serial.println("Welcome!");

	// Define the callback
	SW.OnStop([]() {
		Serial.print("The operation took ");
		Serial.print(SW.GetDuration());
		Serial.println(" µSec.");
	});

	// Wait for terminal (optional)
	delay(1000);

	// Start the time measurement
	SW.Start();

	// Do some stuff
	for (uint32_t n = 0; n < 1000; n++)	{
		#if defined(ARDUINO_ARCH_AVR)
			NOP();
		#elif defined(ARDUINO_ARCH_SAMD)
			NOP();
		#elif defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
			yield();
		#endif
	}

	// Stop the time measurement and trigger the callback
	SW.Stop();
}

void loop()
{
	// NOP
}