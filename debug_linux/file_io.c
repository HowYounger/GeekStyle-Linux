#include "file_io.h"

char buf[32]={0};  // the max is 32 bit,for read_info function

void init_root()
{
	//int dd = -1,mode = 0777; 
    //char dname[42]={"user"};
	char name[32]="root",pwd[32]="root";
	int res = 0;
	if(check_info(name) == 0)
	{
		system("mkdir user");
		store_info(name,pwd,sizeof(pwd));
	}
}

void store_info(char *name,char *pwd,int len)
{
	int fd = -1,mode = 0666; // 8进制
	int res = 0;
	//char buf[128]={0};
	char fname[42]={"./user/"},suf[]=".txt",suf1[]=".csv";
	char root[32]="root";
	if(0 == strcmp(root,name))
		strcpy(suf,suf1);
	
	strcat(fname,name); //补全文件名
	strcat(fname,suf);  //补全文件后缀
	fd = open(fname,O_WRONLY | O_CREAT | O_TRUNC,mode); // 写、创建、覆盖
	if(fd<0)
	{			// printf %s the way array address
		printf("open file\"%s\" failed,errno=%d.\n",fname,errno); 

	}
	res = write(fd,pwd,len);
	//res = write(fd,buf,sizeof(buf));
	printf("write %d bytes to \"%s\".\n",res,fname);
	fsync(fd);	
	close(fd);
}

int check_info(char *name)
{
  	int fd = -1,mode = 0666; // 8进制模式
	char fname[42]={"./user/"},suf[]=".txt",suf1[]=".csv";
	char root[32]="root";
	if(0 == strcmp(root,name))
		strcpy(suf,suf1);
	
	strcat(fname,name); //补全文件名
	strcat(fname,suf);  //补全文件后缀
	fd = open(fname,O_RDONLY);
	if(fd<0)
	{
		//printf("open file\"%s\" failed,errno = %d.\n",fname,errno);
		printf("the info of user is no exit!\n");
		close(fd);
		return 0;
	}
	else
	{
		close(fd);
		return 1;
	}	
}

char * read_info(char *name)
{
   	int fd = -1,mode = 0666; // 8进制模式
	char fname[42]={"./user/"},suf[]=".txt",suf1[]=".csv";
	char root[32]="root";
	if(0 == strcmp(root,name))
		strcpy(suf,suf1);

	strcat(fname,name); //补全文件名
	strcat(fname,suf);  //补全文件后缀
	int res = 0;

	fd = open(fname,O_RDONLY);
	if(fd<0)
	{
		printf("open file\"%s\" failed,errno = %d.\n",name,errno);
		printf("the buf:%s",buf);
		close(fd);
		return buf;
	}
	else
	{
		res = read(fd,buf,sizeof(buf));
		buf[res]='\0';
		printf("read %d bytes from \"%s\" data = \"%s\".\n",res,name,buf);
		close(fd);
		return buf;
	}
}

