#include <stdio.h>
int sumDigits (int n)
{
	int sum=0;
    do
    {
    	int remainder = n%10;
		n /= 10;
		sum += remainder;
    }
    while (n>0);
    return sum;
}
int main()
{
	int n,s;
	do
	{
		printf("Input a positive integer: ");
	    scanf("%d",&n);
	    if(n>=0)
	    {
	    	s = sumDigits(n);
	    	printf("Sum of decimal digits: %d\n\n",s);
		}
	}
	while(n>=0);
	return 0;
}
