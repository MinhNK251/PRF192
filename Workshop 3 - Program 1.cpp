#include <stdio.h>
#include <math.h>
int prime(int n) 
{
    int m = sqrt(n),i;
    if (n<2)
	    return 0;
    for ( i=2; i<=m; i++)
        if (n%i==0)
		    return 0 ;
    return 1;
}
int main()
{
	int n;
	do
	{
		printf("Input a positive integer: ");
	    scanf("%d",&n);
	}
	while(n<2);
	printf("Prime number between 2 and %d are: ",n);
	for ( int i=2; i<n; i++)
	{
		if(prime(i)==1)
		   printf("%d ",i);
	}
	return 0;
}
