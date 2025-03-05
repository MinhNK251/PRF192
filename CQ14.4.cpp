#include<stdio.h>
int count(char s[])
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}
int compare(char s1[], char s2[])
{
    int length = count(s1);
    if (length < count(s2))
        length = count(s2);
    for (int i = 0; i < length; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
int main()
{
	char s1[2021], s2[2021];
	printf("Enter s1: ");
	gets(s1);
	printf("Enter s2: ");
	gets(s2);
	if(compare(s1,s2)==1)
    	printf("The longer string is s1");
	else if(compare(s1,s2)==-1)
    	printf("The longer string is s2");
	else printf("Equal length");
	return 0;
}
