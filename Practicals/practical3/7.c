#include<stdio.h>
int sum(int);
void main()
{
	int n,i;
	printf("Enter n = ");
	scanf("%d",&n);
	printf("sum of %d number is %d \n",n,sum(n));	
}
int sum(int n)
{
	if(n==0)
		return 0;
	else
		return n+sum(n-1);
}
