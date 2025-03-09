#include <stdio.h>
int main()
{
	int i,s,count=1;
	float avg=0;
	printf("Enter the number of input: ");
	scanf("%d",&i);
	while (count<=i)
	{
		count=count+1;
		printf("The score is: ");
		scanf("%d",&s);
		avg=avg+s;
	}
	avg=avg/i;
	if (avg>=5)
	{
		printf("Your average is: %f\n",avg);
		printf("You passed!");
	}
	else
	{
		printf("Your average is: %f\n",avg);
		printf("You failed!");
	}
	return 0;
}
