#include "Button.h"
#include "Arduino.h"


Button::Button(int pin){
	buttonPin = pin;
	pinMode(buttonPin, INPUT);	
	
	debounce = 40;	//time to debounce in ms
	holdTime = 1000;	//time to hold button to read as long press

	lastButtonState = LOW;
	lastDebounceTime = 0;
}
	
	
int Button::Read(){
	// Function will return 0 when no change, 1 
	
	int reading = digitalRead(buttonPin);
	
	
	if (reading != lastButtonState){
	
		lastDebounceTime = millis();
	}
	
	if ((millis() - lastDebounceTime) > debounce) {
	
		if (reading != buttonState) {
			buttonState = reading;
			
			
			if (buttonState == HIGH) {			//Rising edge of button change
				// Serial.print(buttonState);
				// Serial.println("  Rising edge");
				lastButtonState = reading;
				timeHeld = millis();
				return 1;
				
			}
			else if (buttonState == LOW) {		//Falling edge of button change
				// Serial.print(buttonState);
				// Serial.println("Falling edge");
				lastButtonState = reading;
				
				//check how long the button was held
				if ((millis() - timeHeld)  < holdTime ){	
					//short press
					return 2;
				}
					
				else{			
					//long press
					return 3;
				}			
			}
		}
	}
	//no change in button state
	lastButtonState = reading;
	return 0;
}