#include <wiringPi.h>
#include <stdio.h>

#define LedPin    0
#define ButtonPin 1

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);

	pullUpDnControl(ButtonPin, PUD_UP);  //pull up to 3.3V,make GPIO1 a stable level
	while(1){
		digitalWrite(LedPin, HIGH);
		if(digitalRead(ButtonPin) == 0){ //indicate that button has pressed down
			digitalWrite(LedPin, LOW);   //led on
		}
	}

	return 0;
}

