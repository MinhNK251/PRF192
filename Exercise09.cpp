#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int menu();
void triArea();
void strPad();
void sumArith();
void genArray();
int main ()
{
	int userChoice;
    do
    {
    	userChoice = menu();
		switch (userChoice)
		{
			case 1:
				triArea();
				printf("\n");
	            break;
			case 2:
				strPad();
				printf("\n");
	            break;
			case 3:
				sumArith();
				printf("\n");
	            break;
			case 4:
				genArray();
				printf("\n");
	            break;
			default: 
			    printf("\nGoodbye.\n");
		}
	}
    while (userChoice>0 && userChoice<5);
	return 0;
}
int menu ()
{ 
  printf("1 - Calculate area of a triangle");
  printf("\n2 - Check whether a string is padlindrom");
  printf("\n3 - Calculate the sum of arithmetic sequence");
  printf("\n4 - Generate an array of integer");
  printf("\nOthers - Quit");
  printf("\nSelect: ");
  int choice;
  scanf("%d", &choice);
  return choice;
}
void triArea()
{
	double a,b,c,p,area;
	do
	{
		printf("\nEnter 3 sides of triangle: ");
	    scanf("%lf%lf%lf",&a,&b,&c);
	}
	while(a+b<=c || a+c<=b || b+c<=a);
	p = a+b+c;
	p /= 2;
	area = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("\nArea of the triangle: %lf\n",area);	
}
void strPad()
{
	char s[1000];  
    int i,n,c=0;
    fflush(stdin);
    printf("\nEnter string: ");
    gets(s);
    n = strlen(s);
    for(i=0; i<n/2; i++)  
    {
    	if(s[i]==s[n-i-1])
    	    c++;
 	}
 	if(c==i)
 	    printf("\nString is palindrome\n");
    else
        printf("\nString is not palindrome\n");
}
void sumArith()
{
	int n;
	double sum = 0;
    printf("\nEnter n: ");
    scanf("%d", &n);
    printf("\nS = ");
    for(int i=1;i<=n;i++)
    {
		double temp = 0;
		if (i%2==1)
    	{
    		temp += i;
			sum += 1/temp;
    		printf("1/%d",i);
    		if (i != n)
    		    printf(" - ");
		}
		else
		{
			temp += i;
			sum -= 1/temp;
    		printf("1/%d",i);
    		if (i != n)
    		    printf(" + ");
		}
	}
	printf(" = %lf\n",sum);	
}
void genArray()
{
	srand(time(0));
	int k,m,n,temp;
	do
	{
		printf("\nEnter the number of element (k): ");
	    scanf("%d",&k);
	}
	while(k<1);
	int* a= (int*)malloc(k*sizeof(int));
	printf("\nEnter m and n: ");
	scanf("%d%d",&m,&n);
	if(m>n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	for(int i=0;i<k;i++)
	{
		do
			a[i] = rand();
		while(a[i]<m || a[i]>n);
	}
	printf("Random array of integers: ");
	for(int i=0;i<k;i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	printf("\n");
}
