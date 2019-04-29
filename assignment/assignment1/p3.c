/*Write a program to check the balance of parenthesis if an
expression. Implement required data structure for the same.*/
#include<stdio.h>
#include<ctype.h>
char s[20];
int p=0;
void push(char n)
{
	s[p++]=n;
}
char pop()
{
	return s[--p];
}
void main()
{
	int i=0,f=1;
	char exp[30];
	FILE *fp;
	fp=fopen("expr.txt","r");
	fscanf(fp,"%s",exp);
	while(exp[i]!='\0')
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			push(exp[i]);
		if(exp[i]==')')
		{
			if(pop()!='(')
				f=0;
		}
		if(exp[i]=='}')
		{
			if(pop()!='{')
				f=0;
		}
		if(exp[i]==']')
		{
			if(pop()!='[')
				f=0;
		}
		i++;
	}
	if(f==0)
		printf("Please enter match parenthes\n");
	else
		printf("Parenthes matched\n");
}
