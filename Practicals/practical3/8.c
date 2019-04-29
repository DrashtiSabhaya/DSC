#include<stdio.h>
int count(int,int *);
void main()
{
	int n;int sum=0;
	printf("Enter a number = ");
	scanf("%d",&n);
	printf("Number of digits in %d = %d\n",n,count(n,&sum));
	printf("Sum = %d\n",sum);
}
int count(int n,int* s)
{
	static int c=0,sum=0;
	if(n>0)
	{
		c++;
		*s=*s+n%10;
		count(n/10,s);
	}
	return c;
}
