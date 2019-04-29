#include<stdio.h>
void display(int *,int);
void main()
{
	int a[10],n,i;
	printf("Enter size of array = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	display(a,n);
}
void display(int *p,int n)
{
	if(n>0)
	{
		printf("%d\t",*p);
		p++;
		display(p,n-1);
	}
}
