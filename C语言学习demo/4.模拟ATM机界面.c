#include<stdio.h>
#include<stdlib.h>


int main()
{
	struct bank_account
   {
	int account;
	int password;
	int balance;
   } Myaccount;
//   struct bank_account Myaccount;
   
   Myaccount.balance = 1000;
   
   int num = 0;
   printf("欢迎光临个人银行！\n请输入您要操作的项目：\n1.登录\n2.注册\n");
   scanf("%d",&num);
   
   FILE *pfile = NULL;
   char *filename = "D:\\myfile.txt";//存储账号文件路径 
   FILE *ppass = NULL;
   char *filepass = "D:\\myword.txt";//存储密码文件路径
    
   //注册功能的实现，将用户的账户密码存入文本里
   if(num==2)
  {
   printf("注册：\n请输入您的账号：\n");
   scanf("%d",&Myaccount.account);
   printf("请输入您的密码：\n");
   scanf("%d",&Myaccount.password);
   
    if(!(pfile = fopen(filename,"w")))
    {
   	printf("出现错误。程序终止");
   	exit(1);
    }
    fprintf(pfile,"%d",Myaccount.account);
    fclose(pfile);
    
    if(!(ppass = fopen(filepass,"w")))
    {
   	printf("出现错误。程序终止");
   	exit(1);
    }
    fprintf(ppass,"%d",Myaccount.password);
    fclose(ppass);
    
   printf("注册完毕\n");
  }
  //登录功能的实现，将用户输入的账号密码和文本里的进行对比 
   for(;;)
   {
   	int my_account = 0;
   	int account1 = 0;
   	int password1 = 0;
	int my_password = 0;
    printf("请输入你的账号：\n");
    scanf("%d",&my_account);
    printf("\n请输入你的密码：\n");
    scanf("%d",&my_password);
    
    
    pfile = fopen(filename,"r");
    fscanf(pfile,"%d",&account1);
    fclose(pfile);
    
    ppass = fopen(filepass,"r");
    fscanf(ppass,"%d",&password1);
    fclose(ppass);
    
   if(my_account==account1&&my_password==password1)
     break;
    if(my_account!=account1)
     {
     	 printf("不存在该账户\n");
     	 continue;
	 }
    
    if(my_password!=password1)
    printf("密码输入错误!\n");
   }
   printf("您的账户余额为：%d\n",Myaccount.balance);
  //操作功能的实现 
   for(;;)
   {
   	int number = 0;
   	int money = 0;
   	int newpassword = 0;
   	int deposit = 0;
   	printf("\n请选择您要的服务项目:\n1.查询余额\n"
	   "2.取款\n3.修改密码\n4.存款\n5.取卡\n");
	scanf("%d",&number);
	
	 if(number==5)
	  {
	    printf("欢迎下次光临！");
	    break;
	  }
	  
	 if(number==1)
	  {
	    printf("您的账户余额为：%d\n",Myaccount.balance);
	    continue;
      }
    
     if(number==2)
     {
    	printf("\n请输入您要取款的金额：");
    	scanf("%d",&money);
		printf("\n请收好您的%d元现金\n",money);
		Myaccount.balance -= money;
		continue;
	 }
	 
	 if(number==3)
	 {
	 	printf("请输入你的新密码(6位)：\n");
	 	scanf("%d",&newpassword);
	 	ppass = fopen(filepass,"w");
        fprintf(ppass,"%d",newpassword);
        fclose(ppass);
	 	continue;
	 }
	 
	 if(number==4)
	 {
	 	printf("请输入存款金额：");
	 	scanf("%d",&deposit);
	 	Myaccount.balance += deposit;
	 	continue;
	 }
   } 
	return 0;

}
