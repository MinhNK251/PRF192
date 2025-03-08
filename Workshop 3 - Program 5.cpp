#include <stdio.h>
double fibo ( int n) 
{
    int t1=1, t2=1, f=1, i ;
    for ( i= 3; i<=n; i++)
	{
		f= t1 + t2;
		t1= t2;
		t2=f;
    }
   return f;
} 
int main()
{
	int n;
	printf("Input n: ");
	scanf("%d",&n);
	printf("The value at the %dth position in Fibonacci sequence: %d",n,n=fibo(n));
	return 0;
}
