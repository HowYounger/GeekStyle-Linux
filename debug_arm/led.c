#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define LED_NUMS 4
#define BRIEF_LINES 4
char *led_path[LED_NUMS] = {"/sys/class/leds/led2/brightness",
							"/sys/class/leds/led3/brightness",
							"/sys/class/leds/led4/brightness",
							"/sys/class/leds/led5/brightness"};

char *ledon = "1";
char *ledoff = "0";

void delay_10ms(int xms)
{
	int i=0;
	while(xms--)
	{
		for(i=0;i<10;i++)
			usleep(1000);
	}
}

void water_leds(int n)
{
	int fd[LED_NUMS] = {0};
	int i;	
	for (i = 0; i < LED_NUMS; i++) {
		if ((fd[i] = open(led_path[i], O_RDWR)) == -1) {
			perror("open led error\n");
			exit(EXIT_FAILURE);	
		}
	}

	//for (i = 0; i < LED_NUMS; i++)		//turn off all
	//{	
	//		write(fd[i], ledoff, 1);
	//}
		
	write(fd[0], ledon, 1);
	delay_10ms(25);
	write(fd[0], ledoff, 1);
	
	write(fd[1], ledon, 1);
	delay_10ms(25);
	write(fd[1], ledoff, 1);

	write(fd[2], ledon, 1);
	delay_10ms(25);
	write(fd[2], ledoff, 1);

	write(fd[3], ledon, 1);
	delay_10ms(25);
	write(fd[3], ledoff, 1);
	for (i = 0; i < LED_NUMS; i++) {	//turn off all
		write(fd[i], ledoff, 1);
	}
}


