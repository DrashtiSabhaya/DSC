/*Input a number using character array, convert into integer and check whether it
is odd or even using bitwise operator [Using UDF]*/
#include<stdio.h> 
void main()
{
	char n[10];
	int no=0,i;
	printf("Enter a number = ");
	scanf("%s",n);
	for(i=0;n[i]!='\0';i++)
		no=no*10+n[i]-48;
	if(no&1)
		printf("%d is odd\n",no);
	else
		printf("%d is even\n",no);
}
