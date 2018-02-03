#ifndef Button_h
#define Button_h

class Button{
	
	int buttonPin;				//digital pin used for the button
	long debounce;	//time to debounce in ms
	unsigned long holdTime;	//time to hold button to read as long press
	
	int 	buttonState;		//
	int		lastButtonState;
	unsigned long	lastDebounceTime;
	unsigned long 	timeHeld;			// keep track how long the button was pressed
	
	public:
	
	Button(int pin);			
	
	int Read();				//Read button state and return integer based on button press

};

#endif