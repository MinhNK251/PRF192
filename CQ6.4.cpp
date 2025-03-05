#include <stdio.h>
int main()
{
	int n,w,i,j,num=0;
	printf("Input N: ");
	scanf("%d",&n);
	printf("Input W: ");
	scanf("%d",&w);
	for(i=0; i<n; i++)
	{
		printf("%d",num);
		num++;
		if(num==10)
		num=0;
        
		for(j=0; j<w-1; j++)
		{
			printf("%d",num);
			num++;
			if(num==10)
			num=0;
		}
		printf("\n");
	}
	return 0;
}
