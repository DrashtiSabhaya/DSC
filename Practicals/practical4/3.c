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
int check(char e)
{
	if( e == '(')
		return 0;
	if( e == '+'|| e == '-')
		return 1;
	if( e == '/' || e == '*')
		return 2;
	if( e == '^' || e == '$'|| e == '|')
		return 3;
}
void main()
{
	char exp[30];
	char *e,x;
	printf("Enter infix expresion = ");
	scanf("%s",exp);
	e=exp;
	printf("\nPostfix expression\n");
	while(*e!='\0')
	{
		if(isalnum(*e))
			printf("%c",*e);
		else if(*e == '(')
			push(*e);
		else if(*e == ')')
		{
			x=pop();
			while(x!='(')
			{
				printf("%c",x);
				x=pop();
			}
		}
		else
		{
			while(check(s[p-1]) >= check(*e))
				printf("%c",pop());
			push(*e);
		}
		e++;
	}
	while(p>0)
		printf("%c",pop());
}
