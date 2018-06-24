#include <stdio.h>  
#include <termios.h>  
#include <unistd.h>  
#include <errno.h>  
#include<assert.h>  
#include<string.h>  

int getch()  
{  
    int c=0;  
    struct termios org_opts, new_opts;  
    int res=0;  
    //-----  store old settings -----------  
    res=tcgetattr(STDIN_FILENO, &org_opts);  
    assert(res==0);  
    //---- set new terminal parms --------  
    memcpy(&new_opts, &org_opts, sizeof(new_opts));  
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);  
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);  
    c=getchar();  
    //------  restore old settings ---------  
    res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);  
    assert(res==0);  
    return c;  
}  

//函数getpasswd用于获得用户输入的密码，并将其存储在指定的字符数组中  
void getpasswd(char* passwd, int size)  
{  
   char c;
   int i = 0;  
   
   while(1)
   {
	c = getch(); // kill \n
   	if(c == '\n')
	   i=0;
   	else
	{
	   passwd[i++] = c;
	   printf("*");
	   break;
	}
   }
   for(;;i++)
   {
   	passwd[i] = getch();
	if(passwd[i] == '\n')
	{
		passwd[i] = '\0';
		printf("\n");
		break;
	}
	if(passwd[i] == size -1)
	{
		printf("\b \b");
		i = i-2;
	}
	else
	{
		printf("*");
	}
	if(i<0)
		passwd[0]='\0';
   }   
}

