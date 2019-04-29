/*Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements.*/
#include<stdio.h>
void rotate(int [],int,int);
void main()
{
	int a[20],n,d,i;
	printf("Enter size of array = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	printf("Enter d for rotate element = ");
	scanf("%d",&d);
	rotate(a,d,n);
}
void rotate(int a[],int d,int n)
{
	int i,tmp[10],j;
	for(i=d;i<n;i++)
		tmp[i-d]=a[i];
	for(j=0;j<d;j++,i++)
		tmp[i-d]=a[j];
	for(i=0;i<n;i++)
		printf("%d\t",tmp[i]);
}
