#include <stdio.h>
double factorial ( int n) 
{
    double p=1;
    int i;
    for (i=2; i<=n; i++) 
	    p *= i;
    return p;
} 

int main()
{
	int n;
	do
	{
		printf("Input n: ");
	    scanf("%d",&n);
	}
	while(n<1);
	printf("n! = %d\n",n=factorial(n));
	return 0;
}
