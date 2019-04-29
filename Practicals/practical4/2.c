#include<stdio.h>
#include<ctype.h>
char s[30];
int p=0;
void push(int);
int pop();
void push(int n)
{
	s[p++]=n;
}
int pop()
{
	return s[--p];
}
void main()
{
	char e[30],*exp;
	int ans=0,n;
	printf("Enter a postfix expression = ");
	scanf("%s",e);
	exp=e;
	while(*exp!='\0')
	{
		if(isdigit(*exp))
			push(*exp-'0');
		else
		{
			switch(*exp)
			{
				case '+':
					ans=pop()+pop();
					break;
				case '-':
					ans=pop()-pop();
					break;
				case '*':
					ans=pop()*pop();
					break;
				case '/':
					ans=pop()/pop();
					break;
			}
			push(ans);
		}
		exp++;
	}
	
	printf("Answer = %d\n",pop());
}
