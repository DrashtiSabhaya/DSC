/*Create function called print(char), which prints the character
values. Create a function pointer which points to a print ()
function and call function.*/
#include<stdio.h>
void printchar(char c)
{
	printf("character = %c\n",c);
}
void main()
{
	void (*ch)(char)=printchar;
	(*printchar)('D');
}
