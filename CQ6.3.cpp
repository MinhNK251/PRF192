#include <stdio.h>
int main()
{
	int c=500,t=150,s=600,p=50,totalCaloriesAmount=0,n,i;
	char ingre;
	printf("Input the number of ingredients: ");
	scanf("%d",&n);
	for(i=0;i<n*2;i++)
	{
		scanf("%c",&ingre);
		switch(ingre)
		{
		case 'c': totalCaloriesAmount+=c;
		break;
		case 't': totalCaloriesAmount+=t;
		break;
		case 's': totalCaloriesAmount+=s;
		break;
		case 'p': totalCaloriesAmount+=p;
		break;
		default: totalCaloriesAmount+=0;
		break;
		}
	}
	printf("The total calories is: %d",totalCaloriesAmount);
	return 0;
}
