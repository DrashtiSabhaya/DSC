#include<stdio.h>
int fibo(int);
void main()
{
	int n,i;
	printf("Enter n = ");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		printf("%d\t",fibo(i));
}
int fibo(int n)
{
	if(n==1 || n==0)
		return n;
	else
		return fibo(n-1)+fibo(n-2);
}
