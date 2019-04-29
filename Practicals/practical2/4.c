/*To check whether the string enterred by user is palindrome or not. Use UDF
having argument of type pointer.*/
#include<stdio.h>
#include<string.h>
void reverse(char [],int);
void main()
{
	char str[10];
	int t;
	printf("Enter string = ");
	scanf("%s",str);
	t=strlen(str);
	reverse(str,t);
}
void reverse(char *str,int l)
{
	char rev[10],str1[10];
	int i,d=0;
	strcpy(str1,str);
	rev[l]='\0';
	for(i=l-1;*str!='\0';i--)
	{
		rev[i]=*str;
		str++;
	}
	printf("Reverse = %s\n",rev);
	i=0;
	while(rev[i]!='\0')
	{
		if(str1[i]==rev[i])
			d++;
		i++;
	}
	if(d==l)
		printf("Palindrom String\n");
	else
		printf("Not Palindrom\n");
}
