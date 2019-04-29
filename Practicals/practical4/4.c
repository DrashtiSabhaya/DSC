#include<stdio.h>
#include<ctype.h>
#include<string.h>
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
	if( e == ')')
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
	char exp[30],rev[30],new[30];
	char x;
	int i,len,j;
	printf("Enter infix expresion = ");
	scanf("%s",exp);
	len=strlen(exp);
	rev[len]='\0';
	for(i=0;exp[i]!='\0';i++)
		rev[--len]=exp[i];
	printf("%s",rev);
	printf("\nPrefix expression\n");
	i=0,j=0;
	while(rev[i]!='\0')
	{
		if(isalnum(rev[i]))
			new[j++]=rev[i];
		else if(rev[i] == ')')
			push(rev[i]);
		else if(rev[i] == '(')
		{
			x=pop();
			while(x!=')')
			{
				new[j++]=x;
				x=pop();
			}
		}
		else
		{
			while(check(s[p-1]) > check(rev[i]))
				new[j++]=pop();
			push(rev[i]);
		}
		i++;
	}
	while(p>0)
		new[j++]=pop();
	new[j]='\0';
	while(j>=0)
		printf("%c",new[j--]);
}
