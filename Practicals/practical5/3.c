#include<stdio.h>
#define N 20
int s1[N],s2[N],t1=-1,t2=-1;
void enque(int n)
{
	if(t1>N)
		printf("\nOverflow\n");
	else
		s1[++t1]=n;
}
void deque()
{
	if(t1==-1)
	{
		printf("\nUnderflow\n");
		return;
	}
	int i;
	for(i=t1;i>-1;i--)
		s2[++t2]=s1[t1--];
	printf("Dequed element = %d\n",s2[t2--]);
	for(i=t2;i>-1;i--)
		s1[++t1]=s2[t2--];
}
void display()
{
	int i;
	if(t1==-1)
	{
		printf("\nEmpty queue\n");
		return;
	}
	printf("\n---Elements---\n");
	for(i=0;i<=t1;i++)
		printf("%d\t",s1[i]);
	printf("\n");
}
void main()
{
	int ch,n;
	do
	{
		printf("\n------Choices------\n");
		printf("1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
		printf("Enter your choice = ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element = ");
				scanf("%d",&n);
				enque(n);
				break;
			case 2:
				deque();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
		}
	}while(ch!=4);
}
