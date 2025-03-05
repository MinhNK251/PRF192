#include <stdio.h>
#include <string.h>
int main()
{
	char str[2020];
	printf("Enter string: ");
    gets(str);
    printf("\nString after transformation: %s",strlwr(str));
	return 0;
}
