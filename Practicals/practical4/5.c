#include<stdio.h>
#define N 20
int s[N],tmp[N];
int t1=0,t2=0;
void push(int n)
{
	if(t1>N)
		printf("Overflow stack\n");
	else
		s[t1++]=n;
}
void push_tmp(int n)
{
	if(t2>N)
		printf("Overflow stack\n");
	else
		tmp[t2++]=n;
}
int pop()
{
	if(t1<0)
		printf("Underflow stack\n");
	else
		return s[--t1];
}
int pop_tmp()
{
	if(t2<0)
		printf("Underflow stack\n");
	else
		return tmp[--t2];
}
void display()
{
	int i;
	printf("[ ");
	for(i=0;i<t1;i++)
		printf("%d  ",s[i]);
	printf("]");
}
void display_tmp()
{
	int i;
	printf("[ ");
	for(i=0;i<t2;i++)
		printf("%d ",tmp[i]);
	printf("]");
}
void main()
{
	int no,i,e,t;
	printf("Enter number of elements for push = ");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		scanf("%d",&e);
		push(e);
	}
	while(t1>0)
	{
		t=pop();
		printf("\n\nElement taken out = %d\n",t); 
		if(tmp[t2-1]<t)
			push_tmp(t);
		else
		{
			while(tmp[t2-1]>t)
				push(pop_tmp());
			push_tmp(t);
		}
		printf("Input = ");
		display();
		printf("\nTemp = ");
		display_tmp();
	}
	printf("\n\nFinal Sorted list : ");
	display_tmp();
}
