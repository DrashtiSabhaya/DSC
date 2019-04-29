/*Reverse a string using recursion. [Using UDF and Pointer]*/
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
	char rev[10];
	int i;
	rev[l]='\0';
	for(i=l-1;*str!='\0';i--)
	{
		rev[i]=*str;
		str++;
	}
	printf("Reverse = %s\n",rev);
}
