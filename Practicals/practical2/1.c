/*Implement user defined functions (UDF) to perform following:
String length, string copy, string compare, string concate.*/
#include<stdio.h>
void length(char str[])
{
 	int cnt=0;
 	while(str[cnt]!='\0')
		cnt++;
	printf("Length of string = %d\n",cnt);
}
void copystring(char str[])
{
	char cp[20];
	int i;
	for(i=0;str[i]!='\0';i++)
		cp[i]=str[i];
	cp[i]='\0';
	printf("Copied string = %s\n",cp);
}
void compare(char str[])
{
	char str1[20];
	int i,d=0;
	printf("\nEnter a string to compare  = ");
	scanf("%s",str1);
	for(i=0;str[i]!='\0',str1[i]!='\0';i++)
	{
		d=d+str[i]-str1[i];
	}
	printf("Compare = %d\n",d);	
}
void concate(char str[])
{
	int i,c;
	char str1[20];
	printf("\nEnter a string for concate = ");
	scanf("%s",str1);
	for(c=0;str[c]!='\0';c++);
	for(i=0;str1[i]!='\0';i++,c++)
		str[c]=str1[i];
	str[c]='\0';
	printf("String after concat = %s\n",str);
}
void main()
{
	char str[20];
	printf("Enter a string = ");
	scanf("%s",str);
	length(str);
	copystring(str);
	compare(str);
	concate(str);	
}
