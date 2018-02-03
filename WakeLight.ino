/* 	
	Wakeuplight using Adafruit Neopixel library for driving a LED strip and 
	RTClib library for time keeping 
	Main function is lighting the LEDs at preset time of day. 
	Also functions as a night lamp with simple dimming function at night.

 TODO: 
  - Add controls for changing time without reprogramming the microcontroller. 
  - Add display (Either 7-segment displays or LCD) to display time and alarm.

 */

#include "Adafruit_NeoPixel.h"
#include <Wire.h>
#include "RTClib.h"
#include "Button.h"


//Functions, defined in separate file
void ToggleLamp();												
void ToggleAlarm();		//Toggle alarm mode on or off
void SetAlarmTime(int hours, int minutes);	
void Update();
void Flash(int previous);


int ledStripPin = 6;		
int ledStripCount = 52;		//Number of WS2812 RGB LEDs in strip used
int buttonPin = 2;	
int ledPin = 13;			//Indicator LED pin, for debugging



//State variables
boolean LampState;		
boolean AlarmPending;	
boolean AlarmActive;


boolean FlashState = 1;
const long Flashperiod = 200;
long 	previousMillis = 0;
int  FlashNumber = 0;
uint32_t previousColor;

Button button1(buttonPin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(ledStripCount, ledStripPin, NEO_GRB + NEO_KHZ800);


void setup(){
	Serial.begin(9600);
	
	
	strip.begin(); 	
}


void loop(){
	
	Flash(0);
	int reading = button1.Read();

		if (reading == 1){
				 Serial.println("  Rising edge");
			}
			
			else if (reading == 2 ){
				//Serial.print(reading);
				 Serial.println("  Short press!");
				 ToggleLamp();
				 
				 
			}
			
			else if (reading == 3 ){
				//Serial.print(reading);
				Serial.println("  Long press!");
				ToggleAlarm();
			}
}


