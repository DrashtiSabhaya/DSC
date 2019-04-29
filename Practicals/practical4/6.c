#include<stdio.h>
#define N 20
int s[N],p=0;
void push(int n)
{
	if(p>N)
		printf("Overflow stack\n");
	else
		s[p++]=n;
}
int pop()
{
	if(p<=0)
		printf("Underflow stack\n");
	else
		return s[--p];
}
int isEmpty()
{
	if(p==0)
		return 1;
	return 0;
}
void display()
{
	int i;
	for(i=p-1;i>=0;i--)
		printf("%d\n",s[i]);
}
void sortedInsert(int x)
{
	int temp;
	if(isEmpty() || x>s[p-1])
	{
		push(x);
		return;
	}
	temp=pop();
	sortedInsert(x);
	push(temp);
}
void sort()
{
	int temp;
	if(isEmpty())
		return;
	else
	{
		temp=pop();
		sort();
		sortedInsert(temp);
	}
}
void main()
{
	int c,n,i;
	printf("Enter no of elements for push = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("element %d = ",i+1);
		scanf("%d",&c);
		push(c);
	}
	printf("\n---before sort---\n");
	display();
	sort();
	printf("--Sorted stack--\n");
	display();
	printf("\n");
}
