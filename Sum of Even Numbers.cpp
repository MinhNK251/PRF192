#include <stdio.h>
#define MAX 100
int input(int a[], int n)
{
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter element %d: ",++i);
		i--;
		scanf("%d",&a[i]);
	}
	return n;
}
void output(int a[], int n)
{
	printf("Array: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int sumEven (int a[],int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		s+=a[i];
	}
	return s;
}
int insert (int a[], int n)
{
	int x,y,z=0;
	while(z<1)
	{
	printf("Do you want to enter another number? (1 is YES, else is NO): ");
	scanf("%d",&y);
	if(y==1)
	{
	n++;
	printf("Enter new number: ");
	scanf("%d",&x);
	for(int i=n;i>0;i--)
	{
		a[i]=a[i-1];
	}
	a[0]=x;
	}
	else z=1;
	}
	return n;
}
int main()
{
	int a[MAX],n;
	n=input (a,n);
	n=insert (a,n);
	output (a,n);
	printf("\nSum of even numbers: %d",sumEven(a,n));
	return 0;
}
