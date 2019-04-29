/*Write a program to merge two arrays. [using UDF]*/
#include<stdio.h>
void merge(int [],int[],int,int);
void main()
{
	int a[10],b[10],n,n1,i;
	printf("Enter size of 1st array =");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("Enter size of 2nd array =");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		printf("Enter b[%d]=",i);
		scanf("%d",&b[i]);
	}
	merge(a,b,n,n1);
}
void merge(int a[],int b[],int n,int n1)
{
	int i,tmp;
	tmp=n;
	for(i=0;i<n1;i++)
	{
		a[tmp]=b[i];
		tmp++;
	}
	printf("After merge\n"); 
	for(i=0;i<tmp;i++)
		printf("%d\t",a[i]);
}
