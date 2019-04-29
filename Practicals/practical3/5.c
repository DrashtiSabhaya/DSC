#include<stdio.h>
void hanoi(int,char,char,char);
void main()
{
	int n;
	printf("Enter number of disks = ");
	scanf("%d",&n);
	hanoi(n,'A','C','B');
}
void hanoi(int n,char src,char des,char tmp)
{
	if(n==1)
	{
		printf("\nMove disk 1 from %c to %c",src,des);
		return ;
	}
	hanoi(n-1,src,tmp,des);
	printf("\nMove disk %d from %c to %c",n,src,des);
	hanoi(n-1,tmp,des,src);
}
