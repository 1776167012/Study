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
   printf("��ӭ���ٸ������У�\n��������Ҫ��������Ŀ��\n1.��¼\n2.ע��\n");
   scanf("%d",&num);
   
   FILE *pfile = NULL;
   char *filename = "D:\\myfile.txt";//�洢�˺��ļ�·�� 
   FILE *ppass = NULL;
   char *filepass = "D:\\myword.txt";//�洢�����ļ�·��
    
   //ע�Ṧ�ܵ�ʵ�֣����û����˻���������ı���
   if(num==2)
  {
   printf("ע�᣺\n�����������˺ţ�\n");
   scanf("%d",&Myaccount.account);
   printf("�������������룺\n");
   scanf("%d",&Myaccount.password);
   
    if(!(pfile = fopen(filename,"w")))
    {
   	printf("���ִ��󡣳�����ֹ");
   	exit(1);
    }
    fprintf(pfile,"%d",Myaccount.account);
    fclose(pfile);
    
    if(!(ppass = fopen(filepass,"w")))
    {
   	printf("���ִ��󡣳�����ֹ");
   	exit(1);
    }
    fprintf(ppass,"%d",Myaccount.password);
    fclose(ppass);
    
   printf("ע�����\n");
  }
  //��¼���ܵ�ʵ�֣����û�������˺�������ı���Ľ��жԱ� 
   for(;;)
   {
   	int my_account = 0;
   	int account1 = 0;
   	int password1 = 0;
	int my_password = 0;
    printf("����������˺ţ�\n");
    scanf("%d",&my_account);
    printf("\n������������룺\n");
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
     	 printf("�����ڸ��˻�\n");
     	 continue;
	 }
    
    if(my_password!=password1)
    printf("�����������!\n");
   }
   printf("�����˻����Ϊ��%d\n",Myaccount.balance);
  //�������ܵ�ʵ�� 
   for(;;)
   {
   	int number = 0;
   	int money = 0;
   	int newpassword = 0;
   	int deposit = 0;
   	printf("\n��ѡ����Ҫ�ķ�����Ŀ:\n1.��ѯ���\n"
	   "2.ȡ��\n3.�޸�����\n4.���\n5.ȡ��\n");
	scanf("%d",&number);
	
	 if(number==5)
	  {
	    printf("��ӭ�´ι��٣�");
	    break;
	  }
	  
	 if(number==1)
	  {
	    printf("�����˻����Ϊ��%d\n",Myaccount.balance);
	    continue;
      }
    
     if(number==2)
     {
    	printf("\n��������Ҫȡ��Ľ�");
    	scanf("%d",&money);
		printf("\n���պ�����%dԪ�ֽ�\n",money);
		Myaccount.balance -= money;
		continue;
	 }
	 
	 if(number==3)
	 {
	 	printf("���������������(6λ)��\n");
	 	scanf("%d",&newpassword);
	 	ppass = fopen(filepass,"w");
        fprintf(ppass,"%d",newpassword);
        fclose(ppass);
	 	continue;
	 }
	 
	 if(number==4)
	 {
	 	printf("���������");
	 	scanf("%d",&deposit);
	 	Myaccount.balance += deposit;
	 	continue;
	 }
   } 
	return 0;

}
