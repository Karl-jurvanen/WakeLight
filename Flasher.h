#ifndef Flasher_h
#define Flasher_h
#include "Arduino.h"

class Flasher
{
	
	int ledPin;      // the number of the LED pin
	long OnTime;     // milliseconds of on-time
	long OffTime;    // milliseconds of off-time
	
	int ledState;             		// ledState used to set the LED
	unsigned long previousMillis;  	// will store last time LED was updated

 
  public:
  Flasher(int pin, long on, long off);
  void Update();
  
};


#endif