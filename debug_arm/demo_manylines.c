#include<stdio.h>
#include<pthread.h>  
#include<unistd.h> 
#include<string.h> 
char text[4096]={0};  
int flag=0;  

void *mythread(void *arg)  
{  
    int v=*(int *)arg;  
  
    while(1)  
    {  
        if(flag==1)  
        {  
            printf("current length of text is : %d\n ",strlen(text));  
            flag=0;  
        }  
        usleep(10000);  
    }  
}  
int main(int argc,char* argv[])  
{  
    int i=5;  
    pthread_t tid;  
    char buf[128];  
  
    pthread_create(&tid,NULL,mythread,&i);  
      
    while(1)  
    {  
        memset(buf,0,sizeof(buf));  
        gets(buf);  
        strcat(text,buf);  
        flag=1;       
    }  
  
    return 0;  
}