#include <stdio.h>
double makeDouble(int integral, double fraction)
{
    while (fraction >=1) 
	    fraction /= 10;
    if (integral<0) 
	    return integral - fraction;
    return integral + fraction;
}

int main()
{
	double integral,fraction,real;
	printf("Input integral part: ");
	scanf("%lf",&integral);
	do
	{
		printf("Input fraction part: ");
	    scanf("%lf",&fraction);
	}
	while(fraction<0);
	printf("Real number: %lf", real = makeDouble(integral,fraction));
	return 0;
}
