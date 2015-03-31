#include <wiringPi.h>
#include <stdio.h>

//make led_n on
void led_on(int n)
{
	digitalWrite(n, LOW);
}

//make led_n off
void led_off(int n)
{
	digitalWrite(n, HIGH);
}

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	for(i=0;i<8;i++){
		printf("linker LedPin : GPIO %d(wiringPi pin)\n",i); //when initialize wiring successfully,print message to screen
	}

	for(i=0;i<8;i++){       //make 8 pins' mode is output
		pinMode(i, OUTPUT);
	}

	while(1){
		for(i=0;i<8;i++){   //make led on from left to right
			led_on(i);
			delay(100);
			led_off(i);
		}
	//	delay(500);
		for(i=8;i>=0;i--){  //make led off from right to left
			led_on(i);
			delay(100);
			led_off(i);
		}
	}

	return 0;
}

