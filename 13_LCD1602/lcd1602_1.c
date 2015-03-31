/**********************************

$sudo ./l602
------------------
|  Raspberry Pi! |
|51.9C 215/477MB |
------------------

$sudo ./1602 QtSharp
------------------
|QtSharp         |
|51.9C 215/477MB |
------------------

$sudo ./1602 \ \ Hello\ World
------------------
|  hello world   |
|51.9C 215/477MB |
------------------

************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <wiringPi.h>
#include <lcd.h>

int main(int args, char *argv[])
{
	FILE *fp;
	int fd;
	char temp_char[15];
	char Total[20];
	char Free[20];
	float Temp;
	
	if(wiringPiSetup() == -1){
		exit(1);
	}
	
	fd = lcdInit(2, 16, 4,  15,16 , 0,1,2,3,4,5,6,7); //see /usr/local/include/lcd.h
	if (fd == -1){
		printf ("lcdInit 1 failed\n") ;
		return 1;
	}
	sleep(1);

	lcdPosition(fd, 0, 0); lcdPuts (fd, "  Raspberry Pi!");
	sleep(1);

	if(argv[1]){
		lcdPosition(fd, 0, 0);
		lcdPuts(fd, "                ");
		lcdPosition(fd, 0, 0); lcdPuts(fd, argv[1]);
	} 

	while(1){
		fp=fopen("/sys/class/thermal/thermal_zone0/temp","r"); //read Rpi's tempture
		fgets(temp_char,9,fp);
		Temp = atof(temp_char)/1000;
		lcdPosition(fd, 0, 1); lcdPrintf(fd, "%3.1fC", Temp);
		fclose(fp);

		fp=fopen("/proc/meminfo","r"); //read RAM infomation
		fgets(Total,19,fp);
		fgets(Total,4,fp);
		fgets(Free,9,fp);
		fgets(Free,19,fp);
		fgets(Free,4,fp);
//		printf("%3d/%3dMB\n",atoi(Free),atoi(Total));
		lcdPosition(fd, 7, 1);
		lcdPrintf(fd, "%3d/%3dMB", atoi(Free), atoi(Total)) ;
		fclose(fp);

		sleep(1);
	}

	return 0;

}
