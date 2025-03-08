#include <stdio.h>
#include <stdlib.h>
int search (int x, int *a, int n)
{ int i, result=0;
  for (i=0; i<n; i++) 
    if (a[i]==x) 
      result++;
  return result;}
int removeOne (int pos, int*a, int*pn)
{ if (pos<0||pos>=*pn)
    return 0;
  for(int i=pos; i<*pn-1; i++) 
    a[i]=a[i+1];
  (*pn)--;
  return 1;}
int main()
{
	int n, item, result=0;
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
	printf("Array: ");
	for (int i=0;i<n;i++) 
		printf("%d ",a[i]);
	printf("\nEnter item: ");
	scanf("%d",&item);
	result=search(item, a, n);
    printf("Result: %d",result);
	return 0;
}
