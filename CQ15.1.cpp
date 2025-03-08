#include <stdio.h>
#include <stdlib.h>
void ascSort(int *a, int n)
{
	int i,j,temp,minIndex;
	for(i=0; i<n-1; i++)
	{
		minIndex=i;
		for(j=i+1; j<n; j++)
		   if(a[minIndex]>a[j])
		      minIndex=j;
		if(minIndex>i)
		{	
		    temp=a[minIndex];
		    a[minIndex]=a[i];
	        a[i]=temp;
		}
	}
}
int main()
{
	int n, result=0;
	do
	{
		printf("Enter the number of elements: ");
		scanf("%d",&n);
	}
	while(n<1);
	int* a= (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",a+i);
	}
	ascSort(a,n);
	for(int i=0;i<n;i++)
	{
		if(result*result==a[i])
		   result++;
	}
	free(a);
	printf("Result = %d",result*result);
	return 0;
}
