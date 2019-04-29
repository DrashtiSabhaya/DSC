#include<stdio.h>
#define N 20
int q[N];
int f=-1,r=-1;
void enque(int n)
{
	if(f>N)
		printf("Overflow\n");
	else
		q[++r]=n;
	if(f==-1)
		f++;
}
void deque()
{
	if(r<f)
		printf("Underflow\n");
	else
		printf("DeQueued element = %d\n",q[f++]);
}
void display()
{
	int i;
	printf("\n---Elements---\n");
	for(i=f;i<=r;i++)
		printf("%d\t",q[i]);
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
