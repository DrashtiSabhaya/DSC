/*Write a C program to Swap 2 numbers using functions by passby value and pass by reference.*/
#include<stdio.h>
void swap1(int *,int *);
void swap2(int ,int );
void main()
{
	int a=10,b=20;
	printf("Before swap\n");
	printf("a=%d\tb=%d\n",a,b);
	swap1(&a,&b);
	printf("After swap(using pass by reference)\n");
	printf("a=%d\tb=%d\n",a,b);
	printf("\nBefore swap\n");
	printf("a=%d\tb=%d\n",a,b);
	swap2(a,b);
}
void swap1(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void swap2(int a,int b)
{
	int tmp;
	printf("After swap(using pass by value)\n");
	tmp=a;
	a=b;
	b=tmp;
	printf("a=%d\tb=%d\n",a,b);
}
