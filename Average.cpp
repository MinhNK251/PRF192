#include <stdio.h>
double average (double a, double b, double c)
{
	double result;
	result = (a+b+c)/3;
	return result;
}
int main()
{
	double a,b,c;
	printf("Input a: ");
	scanf("%lf",&a);
	printf("Input b: ");
	scanf("%lf",&b);
	printf("Input c: ");
	scanf("%lf",&c);
	printf("Result: %lf",average (a,b,c));
	return 0;
}
