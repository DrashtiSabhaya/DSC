/*Create an array of 15 element. create pointer which points to an
array. And print the array values using pointer arithmetic. Also
use sizeof() function.*/
#include<stdio.h>
void main()
{
	int n,i,a[15],*p,s;
	for(i=0;i<15;i++)
	{
		printf("Enter a[%d]=",i);
		scanf("%d",&a[i]);
	}
	p=a;
	s=sizeof(a)/sizeof(a[0]);
	for(i=0;i<s;i++)
	{
		printf("%d\t",*p);
		p++;
	}
}
