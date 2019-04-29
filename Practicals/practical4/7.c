#include<stdio.h>
#include<string.h>
#define N 50
char s[N];
int t=0,p=0;
char tmp[N];
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
void pushTmp(char ch)
{
	if(p>N)
		printf("Overflow\n");
	else
		tmp[p++]=ch;
}
char popTmp()
{
	if(p!=-1)
		return tmp[--p];
	else
		printf("\nUnderflow\n");
	return 0;
}
void display()
{
	int i;	
	for(i=0;i<p;i++)
		printf("%c",tmp[i]);
	
}
void sortStr()
{
	char ch;
	while(t>0)
	{
		ch=pop();
		if(tmp[p-1]<ch)
			pushTmp(ch);
		else
		{
			while(tmp[p-1]>ch)
				push(popTmp());
			pushTmp(ch);
		}
	}
}
void main()
{
	char str[N];
	int i;
	printf("Enter a string = ");
	scanf("%[^\n]",str);
	for(i=0;i<strlen(str);i++)
		push(str[i]);
	sortStr();
	printf("Sorted string = ");
	display();
	printf("\n");
}
