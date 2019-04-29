#include<stdio.h>
#define N 20
int s[N],p=0;
void display()
{
	int i;
	for(i=p-1;i>=0;i--)
		printf("%d\t",s[i]);
}
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
void insert(int n)
{
	int tmp;
	if(isEmpty())
		push(n);
	else
	{
		tmp=pop();
		insert(n);
		push(tmp);	
	}
}
void rev()
{
	int tmp;
	if(!isEmpty())
	{
		tmp=pop();
		rev();
		insert(tmp);
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
	printf("\n--Stack--\n");
	display();
	rev();
	printf("\n--Reverse stack--\n");
	display();
	printf("\n");
}
