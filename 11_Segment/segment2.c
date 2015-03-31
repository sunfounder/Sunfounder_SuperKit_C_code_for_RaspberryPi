#include <wiringPi.h>
#include <stdio.h>

unsigned char seg[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80};

int main(void)
{
	int i;
	int bit;

	if(wiringPiSetup() == -1){
		printf("wiringPi setup error!\n");
		return -1;
	}

	sr595Setup(100, 10, 0, 2, 1);

	while(1){
		for(i = 0; i < sizeof(seg); i++){
			for(bit = 0; bit < 8; bit++){
				digitalWrite(100+bit, seg[i] & (1<<bit));
				delay(1);
			}	
			delay(500);
		}
	}

	return 0;
}
