#include<stdio.h>
int fact(int);
void main()
{
	int n;
	printf("Enter a number for factorial = ");
	scanf("%d",&n);
	printf("factorial of %d is %d\n",n,fact(n));
}
int fact(int n)
{
	if(n==1)
		return 1;
	else
		return n*fact(n-1);
}
