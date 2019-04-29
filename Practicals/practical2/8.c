/*Write a program to Rearrange array such that even index elements are smaller
and odd index elements are greater.*/
#include<stdio.h>
void main()
{
	int a[20],i,n,tmp;
	printf("Enter size of array = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(i%2==0 && a[i]>a[i+1])
		{
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
		}
		if(i%2!=0 && a[i+1]>a[i])
		{
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
