#include "init.h"

info admin = {"root","root"}; //管理员用户
info guest = {0,0}; //普通用户
char sts[3] = {'-','-','-'},key = 0; //返回标志

int main()
{
	int opt = 0,i=0,fsh=1;
	char sts0 = 0;
	//char *psts = sts;
	init_root();
	
	while(!sts0)
	{
		system("clear"); //清屏
		printf("*******************************\n");
		printf("请选择: 1【登录】 2【管理】 3【退出】");
		scanf("%d",&opt);
		system("clear");
		printf("*******************************\n");
		switch(opt) //操作选项
		{
			case 0: {
				break;
			}
			case 1: {	//【登录】
				check_qiut(&sts[0],0);
				SignIn(0,&guest);
			break;
			}	
			case 2: {	//【管理】 管理员验证->管理信息
				check_qiut(&sts[1],1);
				Admin();
				break;
			}
			case 3: { //【退出】 
				sts0 = 1;
				break;
			}
			default:{
				show_warn(3);
				break;
			}
		}
		clean_sts();
		printf("\r");
		fflush(stdout);

	}
	printf("已经完全退出\n");
	return 0;
}

void show_warn(int n)
{
	while(n--)
	{
		printf("操作有误，请%d秒后重试",n);
		sleep(1); //延时一秒
		printf("\r");
		fflush(stdout);
	}
	system("clear"); 
}

void clean_sts()
{
	int i=0;
	for(i=0;i<2;i++)
	{
		sts[i] = '-'; //清除返回标志
	}
}

/*登录函数*/
void SignIn(int sw,struct UserInfo *user)
{
	char adm[32] = "root";
	while(sts[sw]!='n')
	{
		system("clear");
		printf("*******************************\n");
		printf("***********请登录验证***********\n");
		printf("用户名：");
		if(0 == strcmp(adm,user->name))
			printf("%s\n",user->name);	// admin name can't change
		else
			scanf("%s",(*user).name);	//guest change name
		/*验证信息*/
		if(1 == check_info((*user).name))
		{			

			printf("密码:");
			scanf("%s",user->password);
			if(strcmp(read_info(user->name),user->password) == 0)
			{
				printf("用户密码匹配~\n");
				sts[sw] = 'n';
				if(sw == 1)
					key = 1;
			}
			else
			{
				printf("用户密码输入错误！\n");
				show_warn(3);
			}
		}
		else
		{
			printf("用户不存在，请重新输入！\n");
			show_warn(3);
		}
	}

	show_tips(3);
}

/*管理函数*/
void Admin()
{
	int opt1 = 0;
	SignIn(1,&admin);
	while(key == 1)
	{
		system("clear"); //清屏
		printf("*******************************\n");
		printf("请选择: 1【添加用户】 2【删除用户】 3【返回】");
		scanf("%d",&opt1);
		system("clear");
		printf("*******************************\n");		
		switch(opt1)
		{
			case 0:{
				break;
			}
			case 1:{	//【添加用户】
				SignUp();
				break;
			}
			case 2:{	//【删除用户】

				break;
			}
			case 3:{	//【返回】
				sts[1] = '-';
				key = 0;
				break;
			}
			default:{
				show_warn(3);
				break;
			}
		}
	}
	

}

/*注册函数-添加用户*/
void SignUp()
{
	char pwd1[32],pwd2[32];
	system("clear");
	while(sts[2]!='y')
	{
		printf("*******************************\n");
		printf("*********请输入注册信息*********\n");
		printf("用户名：");
		scanf("%s",guest.name);
		printf("密码：");
		scanf("%s",pwd1);
		printf("密码确认：");
		scanf("%s",pwd2);
		if(strcmp(pwd1,pwd2) == 0)
		{	
			strcpy(guest.password,pwd2);  //字符串复制，简便方式
			/**创建用户信息文件**/
			store_info(guest.name,guest.password,sizeof(guest.name)); // p[] or p or &p
			printf("用户添加成功！\n");
			sts[2] = 'y';
		}
		else
		{
			printf("两次输入密码不一致！\n");
			show_warn(3);
		}
	}
	sts[2] = '-'; //清除返回标志
	show_tips(4);
}

void check_qiut(char *status,int i)
{
	system("clear");
	printf("*******************************\n");
	printf("是否确认要进行身份验证: y n?");
	scanf("%s",status);	
}

void show_tips(int n)  //提示
{
	while(n--)
	{
		printf("距离返回上级菜单，还有%d秒",n);
		printf("\r");
		fflush(stdout);
		sleep(1); //延时一秒
	}
	system("clear"); 
}
