#include <stdio.h>
#include <math.h>
int main()
{
	int n,area;
	printf("Input a positive integer: ");
	scanf("%d",&n);
	area=pow((n+1),2)+n*n;
	printf("Area: %d",area);
	return 0;
}
