#include <stdio.h>
int main()
{
    int h;
    printf("Input h: ");
    scanf("%d",&h);
    for(int i=1;i<=h;i++)
    {
        for(int space=1;space<=h-i;space++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("%d ",j);
        printf("\n");
    }
    return 0;
}

