#include <stdio.h>
int main()
{
	int a,b;
	printf("Input A: ");
	scanf("%d",&a);
	while(a<-2021||a>2021)
	{  
	  printf("Input A again: ");
	  scanf("%d",&a);
	}
	printf("Input B: ");
	scanf("%d",&b);
	while(b<-2021||b>2021)
	{  
	  printf("Input B again: ");
	  scanf("%d",&b);
	}
	printf("ADD(A,B) = %d",a+b);
	printf("\nSUB(A,B) = %d",a-b);
	printf("\nMUL(A,B) = %d",a*b);
	printf("\nDIV(A,B) = %d",a/b);
	printf("\nMOD(A,B) = %d",a%b);
}
