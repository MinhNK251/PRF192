#include <stdio.h>
int main()
{
	long long income,pa=9000000,pd=3600000,n,tf,ti,it;
	printf("Input your income: ");
	scanf("%lld",&income);
	printf("Input the number of dependents: ");
	scanf("%lld",&n);
	tf=12*(pa+n*pd);
	ti=income-tf;
	if (ti<=0)
	  it=0;
	if (ti<=5000000&&ti>0)
	  it= ti*5/100;
	if (ti<=10000000&&ti>5000000)
	  it= ti*10/100;
	if (ti<=18000000&&ti>10000000)
	  it= ti*15/100;
	if (ti>18000000) 
	  it= ti*20/100;
	printf("Your income tax is: %lld",it);
	return 0;
}
