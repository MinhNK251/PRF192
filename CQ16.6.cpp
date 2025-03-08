#include <stdio.h>
#include <ctype.h>
void input (int*a, int*pn)
{
	int value;
	char response;
	do
	{
	printf("Input an added value: ");
    scanf("%d", &value);
    printf("\nAdded\n");
    a[*pn] = value ;
    (*pn) ++;
    printf("\nDo you want to continue?(Y/N): ");
    scanf("%c");
    scanf("%c", &response);
    printf("\n");
    response = toupper(response);
	}
	while(response == 'Y');
}
void pair(int*a, int n, int sum)
{
	int flag = 0;
	printf("\nPair found: ");
	for (int i = 0; i < (n - 1); i++)
        for (int j = (i + 1); j < n; j++)
			if (a[i] + a[j] == sum)
                {
                	printf("(%d,%d) ", a[i], a[j]);
                	flag++;
				}
	if (flag==0)
	    printf("None\n");
	else printf("\n");
}
int main()
{
	int n=0, sum=0, a[100];
	input(a,&n);
	printf("Input sum: ");
    scanf("%d", &sum);
    pair(a,n,sum);
	return 0;
}
