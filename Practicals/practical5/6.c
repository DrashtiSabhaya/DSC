#include<stdio.h>
#define N 20
int q[N],s[N];
int f=-1,r=-1,p=-1;
void enque(int n)
{
	if(f>N)
		printf("Overflow\n");
	else
		q[++r]=n;
	if(f==-1)
		f++;
}
int deque()
{
	if(r<f)
		printf("Underflow\n");
	else
		return q[f++];
	return 0;
}
void push(int n)
{
	if(p>N)
		printf("Overflow stack\n");
	else
		s[++p]=n;
}
int pop()
{
	if(p<0)
		printf("Underflow stack\n");
	else
		return s[p--];
}
void display()
{
	int i;
	for(i=f;i<=r;i++)
		printf("%d ",q[i]);
}
void rev()
{
	while(r>=f)
		push(deque());
	while(p>-1)
		enque(pop());
	display();
}
void main()
{
	int c,n,i;
	printf("Enter no of element = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Element %d = ",i+1);
		scanf("%d",&c);
		enque(c);
	}
	printf("\nInput = [ ");
	display();
	printf("]\n");
	printf("\nOutput = [ ");
	rev();
	printf("]\n");	
}
