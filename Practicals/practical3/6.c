#include<stdio.h>
long power(int,int);
void main()
{
	int n,p;
	printf("Enter base number = ");
	scanf("%d",&n);
	printf("Enter power = ");
	scanf("%d",&p);
	printf("%d^%d = %ld\n",n,p,power(n,p));
}
long power(int n,int p)
{
	if(p>1)
		return n*power(n,p-1);
		
}
