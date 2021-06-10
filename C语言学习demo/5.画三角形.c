//自定义边长，用*画出正方形
#include<stdio.h>

int main()
{
	int side_length1 = 0;
	printf("正方形的边长：");
	scanf("%d",&side_length1);
	int side_length2 = side_length1-1;
	int i = 0;
	//画三角形区域 
	//**************************************************************************************
	for(i=0;i<side_length1*2;i++){
		if(i==side_length1-1) {
			printf("*");
		}else{
			printf(" ");
		}
	}
    printf("\n");
	for(i=0;i<side_length1-2;i++){
	   int j = 0;
	   for(j=0;j<side_length1*2;j++){
		if(j==side_length2-i-1||j==side_length2+1+i){
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
