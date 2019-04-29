/*Pass one-dimensional array as an argument to User Defined
Function and write a program to perform sorting operation on it.*/
#include<stdio.h>
void sort(int [],int);
void main()
{
	int a[10],n,i;
	printf("Enter size of array = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	sort(a,n);
}
void sort(int a[],int n)
{
	int i,j,tmp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	printf("----sorted array----\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
