#include <stdio.h>


char *brief[5] = {
" ____                       _     _               _     ",   
"/ ___| _ __ ___   __ _ _ __| |_  | |    ___   ___| | __ ",
"\\___ \\| '_ ` _ \\ / _` | '__| __| | |   / _ \\ / __| |/ / ",
" ___) | | | | | | (_| | |  | |_  | |__| (_) | (__|   <  ",
"|____/|_| |_| |_|\\__,_|_|   \\__| |_____\\___/ \\___|_|\\_\\ "};


void draw_string(char *buf[], unsigned int line)
{
	int i;
	for (i = 0; i < line; i++) {
		printf("%s\n", buf[i]);
	}
}


int main()
{

	draw_string(brief,5);
	return 0;
}


