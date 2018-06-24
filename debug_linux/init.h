#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //字符操作函数库

typedef struct UserInfo
{
	char name[32];
	char password[32];
}info;

void clean_sts();
void SignIn(int,info *);
void Admin();
void SignUp();
void show_tips(int);
void show_warn(int n);
void check_qiut(char status[],int i);
