//�Զ���߳�����*����������
#include<stdio.h>

int main()
{
	int side_length1 = 0;
	int side_length2 = 0;
	printf("�����εı߳���");
	scanf("%d",&side_length1);
	int i = 0;
	//������������ 
	//**************************************************************************************
	for(i=0;i<side_length1;i++){
		 printf("* ");
	}
    printf("\n");
    
	for(i=0;i<side_length1-2;i++){
	   int j = 0;
	   for(j=0;j<side_length1*2;j++){
		if(j==0||j==side_length1*2-2){
			 printf("*");
		}else{
			printf(" ");
		}
	  }
	  printf("\n");
   }
   for(i=0;i<side_length1;i++){
   	printf("* ");
   }
   printf("\n\n");
  //***************************************************************************************** 
	return 0;
}
