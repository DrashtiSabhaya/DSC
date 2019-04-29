/*Pass two-dimensional array as an argument to User Defined
Function and perform summation of array elements.*/
#include<stdio.h>
int sum(int [][3],int,int);
void main()
{
	int a[3][3],r,c,i,j;
	printf("Enter rows & cols = ");
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter a[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Sum = %d\n",sum(a,r,c));
}
int sum(int a[][3],int r,int c)
{
	int i,j,sum=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			sum=sum+a[i][j];
	}
	printf("----Array----\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	return sum;
}
