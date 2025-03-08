#include <stdio.h>
void printMinMaxDigits(int n)
{
	int min, max, digit = n% 10;
    n = n/10;
    max = min = digit;
    while (n>0) 
    {
    	digit = n%10;
		n /= 10;
        if (min > digit) 
		    min = digit;
        if (max < digit) 
		    max = digit;
   }
   printf("Minimum digit: %d\n",min);
   printf("Maximum digit: %d\n",max);
}
int main()
{
	int n;
	do
	{
		printf("Input a positive integer: ");
	    scanf("%d",&n);
	    printMinMaxDigits(n);
	}
	while(n<0);
	return 0;
}


