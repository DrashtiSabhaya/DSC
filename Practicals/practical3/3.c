#include<stdio.h>
int fibo(int);
void main()
{
	int n,i;
	printf("Enter n = ");
	scanf("%d",&n);
	printf("value %d at %d position\n",fibo(n),n);	
}
int fibo(int n)
{
	if(n==1 || n==0)
		return n;
	else
		return fibo(n-1)+fibo(n-2);
}
