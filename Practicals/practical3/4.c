#include<stdio.h>
int gcdcount(int,int);
void main()
{
	int a,b;
	printf("Enter higher number = ");
	scanf("%d",&a);
	printf("Enter samller number = ");
	scanf("%d",&b);
	printf("GCD = %d\n",gcdcount(a,b));
}
int gcdcount(int a,int b)
{
	if(a!=0 && b!=0)
		return gcdcount(b,a%b);
}
