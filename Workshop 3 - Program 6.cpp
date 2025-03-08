#include <stdio.h>
int isFibonacci (int n)
{
	int t1=0, t2=1, f=0;
    while (f<n)
   {  
       f= t1 + t2;
       t1=t2;
       t2=f;
   }  
    return n==f;

}
int main()
{
	int n;
	printf("Input a positive integer: ");
	scanf("%d",&n);
	if (isFibonacci(n)==1)
	printf("It is a Fibonacci element.");
	else 
	printf("It is not a Fibonacci element.");
	return 0;
}
