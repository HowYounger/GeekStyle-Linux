#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h> //字符操作函数库
#include <stdlib.h>

void init_root();
void store_info(char *name,char *pwd,int len);
char * read_info(char *name);
int check_info(char *name);
