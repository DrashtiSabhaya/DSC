/*Write a program to take input of string from user, allow user to change
character at willing location/ index. [use UDF and pointer]*/
#include<stdio.h>
void change(char [],int);
void main()
{
	char str[20];
	int i;
	printf("Enter a string = ");
	scanf("%s",str);
	fflush(stdin);
	printf("Enter index for change char =");
	scanf("%d",&i);
	change(str,i);
}
void change(char str[],int i)
{
	char ch;
	fflush(stdin);
	printf("Enter new char = ");
	scanf("%c",&ch);
	str[i]='d';
	printf("After change = %s\n",str);
}
