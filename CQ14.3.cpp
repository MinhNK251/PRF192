#include<stdio.h>
#include<string.h>
int main()
{
	char str[1000];
	printf("Enter str: ");
	scanf("%[^\n]",str);
	char word;
	int i=0,count=0,temp=0;
	while(temp==0)
	{
		if(str[i]==' '||str[i]=='\t'||str[i]=='\0')
		   if(word!=' ' && word!='\t' && word!='\0')
		      count++;
	    word=str[i];
	    if(str[i]=='\0')
	      temp++;
	    i++;
	}
	printf("Total number of words in str: %d",count);
	return 0;
}
