#include <stdio.h>
int main()
{
	int pi,sum=0,a;
	printf("Input a positive integer: ");
	scanf("%d",&pi);
	a=pi;
	while (pi>0)
	{
		sum=sum+pi%10;
		pi/=10;
	}
	printf("Sum of the digits of %d is %d",a,sum);
	return 0;
}
