#include<stdio.h>
#define N 5
int q[N];
int f=-1,r=-1;
void enque(int n)
{
	if(r>=N-1 && f!=0)
		r=-1;
	if(r<N-1)
		q[++r]=n;
	if(f==-1)
		f++;
}
void deque()
{
	if(r==f)
		printf("Underflow\n");
	else
		printf("DeQueued element = %d\n",q[f++]);
}
void display()
{
	int i;
	printf("\n---Elements---\n");
	if(r<f)
	{
		for(i=f;i<N;i++)
			printf("%d\t",q[i]);
		for(i=0;i<=r;i++)
			printf("%d\t",q[i]);
	}
	else
	{
		for(i=f;i<=r;i++)
			printf("%d\t",q[i]);
	}
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
				if(f==r && f>0 || r>=N )
					printf("\n--> Overflow\n");
				else
				{
					printf("Enter element = ");
					scanf("%d",&n);
					enque(n);
				}
				display();
				break;
			case 2:
				deque();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
		}
	}while(ch!=4);	
}
