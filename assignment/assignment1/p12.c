/*Write a program to check whether the string is palindrome
or not. Use Stack Data Structure for the same.*/
#include<stdio.h>
#include<string.h>
#define N 50
char s[N];
int t=0;
void push(char ch)
{
	if(t>N)
		printf("Overflow\n");
	else
		s[t++]=ch;
}
char pop()
{
	if(t!=0)
		return s[--t];
	else
		printf("\nUnderflow\n");
	return 0;

}
void display()
{
	int i;	
	for(i=t;i>=0;i--)
		printf("%c",s[i]);
	
}
void palindrom(char str[])
{
	int i=0,cnt=0;
	while(str[i]!='\0')
	{
		if(pop()==str[i])
			cnt++;
		i++;
	}
	if(cnt!=strlen(str))
		printf("String is not palindrom\n");
	else
		printf("String is palindrom\n");
}
void main()
{
	char str[N];
	int i;
	FILE *fp;
	fp=fopen("string.txt","r");
	fscanf(fp,"%s",str);
	for(i=0;i<strlen(str);i++)
		push(str[i]);
	palindrom(str);
	printf("%s\n",str);
	printf("\n");
}
