#include <stdio.h>
#include <math.h>
int isPrime (int n)
{
	for (int i=2;i<n;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int sumPrime (int isPrime)
{
	for (int i=2;i<n;i++)
	{
		if(n%i==0)
		return 0;
	}
}
int main()
{
	int integer;
	printf("Input an integer: ");
	scanf("%d",&integer);
	if (integer==1)
	printf("Result: 0");
	if (isPrime(integer)==1)
	printf("%d",)
	else printf("Result: %d",sumPrime(isPrime(integer)));
	return 0;
}
