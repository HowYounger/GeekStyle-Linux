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

char *brief[BRIEF_LINES] = {
	" =================================",
	"| 实验：buzzer测试                |",
	"| 现象：按键控制buzzer的状态      |",  
	" ================================="};
char *buzzer_on = "1";
char *buzzer_off = "0";

void delay_10ms(int xms)
{
	int i=0;
	while(xms--)
	{
		for(i=0;i<10;i++)
			usleep(1000);
	}
}

void draw_string(char *buf[], unsigned int line)
{
	int i;
	for (i = 0; i < line; i++) {
		printf("%s\n", buf[i]);
	}
}

void warn_buzzer(int n)
{
	int fd = -1;
	int ret;
	if ((fd = open(BUZZINPUTTAG,O_RDWR|O_NONBLOCK))<0){
		perror("open error\n");
		exit(0);
	}
	
	//draw_string(brief, BRIEF_LINES);
	struct input_event event;
	event.type = EV_SND;
	event.code = SND_TONE;
	while (n--) {
		printf("the time is %d",n);
		printf("\r");
		fflush(stdout);
		event.value = 1000; //turn on
		ret = write(fd,&event,sizeof(struct input_event));
		delay_10ms(50);	//0.5s
		event.value = 0;  //turn off
		ret = write(fd,&event,sizeof(struct input_event));
		delay_10ms(50);	//0.5s
		
	}
	event.value = 0;  //turn off
	ret = write(fd,&event,sizeof(struct input_event));
	close(fd);
}

int main(int argc, const char *argv[])
{
	warn_buzzer(7);
	return 0;
}
