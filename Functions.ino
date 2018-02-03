/* void Begin(){
	
	strip.begin();
	for(int i=0;i<ledStripCount;i++){
	  strip.setPixelColor(i, strip.Color(0,0,0));  
	}
	strip.show(); 
	Serial.println("Begin!");
	
} */

void ToggleLamp(){

	LampState = !LampState;

	
	
	for(int i=0;i<ledStripCount;i++){

		//RGB value for nightlamp, adjust for a comfortable brightness and color temperature
		strip.setPixelColor(i, strip.Color(LampState *255,LampState * 200,LampState * 100));
	  
	  
	}
	strip.show(); // 
	Serial.print("Lampstate is ");
	Serial.print(LampState);

}

//Toggle alarm mode and give flash to user
void ToggleAlarm(){

	AlarmPending = !AlarmPending;

	previousColor = strip.getPixelColor(0);
	Serial.println(previousColor);
	if (AlarmPending == 0){			//Flash twice when alarm is switched off
		FlashNumber = 3;
	}
	else if (AlarmPending == 1){	//Flash three times whel alarm is turned on
		FlashNumber = 4;
	}
	if (previousColor == 0) {		//
	
		FlashNumber++;
		
		}
	Serial.print("AlarmState is ");
	Serial.print(AlarmPending);

}



void Flash(int previous){
//Flash the first LED as an indicator when changing states

   

	if (FlashNumber > 0){
	
		if((FlashState == HIGH) && (millis() - previousMillis >= Flashperiod)){

			FlashState = LOW;  // Turn it off
			previousMillis = millis();  // Remember the time
			
			strip.setPixelColor(0, strip.Color(0,0,0));
			strip.show();
			FlashNumber--;
				
			
		}
		else if ((FlashState == LOW) && (millis() - previousMillis >= Flashperiod)){
			FlashState = HIGH;  // turn it on
			previousMillis = millis();   // Remember the time
			
			// Set LED back to previous state on last flash
			if (FlashNumber != 1){
				strip.setPixelColor(0, strip.Color(150,150,80));
				strip.show();
			}
			
			else {
				strip.setPixelColor(0, previousColor);
				strip.show();
				FlashNumber--;
			}
		}

	}

}




void Update(){
	
	
}