#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/input.h>

#define BUZZER_NUMS 1 

#define BRIEF_LINES 4

#define BUZZINPUTTAG "/dev/input/event2"

char *buzzer_on = "1";
char *buzzer_off = "0";

extern void delay_10ms(int xms);
void warn_buzzer()
{
	int fd = -1;
	int ret;
	if ((fd = open(BUZZINPUTTAG,O_RDWR|O_NONBLOCK))<0){
		perror("open error\n");
		exit(0);
	}
	
	struct input_event event;
	event.type = EV_SND;
	event.code = SND_TONE;
		
	event.value = 1000; //turn on
	ret = write(fd,&event,sizeof(struct input_event));
	delay_10ms(50);	//0.5s
	event.value = 0;  //turn off
	ret = write(fd,&event,sizeof(struct input_event));
	delay_10ms(50);	//0.5s
		
	event.value = 0;  //turn off
	ret = write(fd,&event,sizeof(struct input_event));
	close(fd);
}

