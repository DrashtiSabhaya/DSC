/*Write a program to implement Queue with required
operations using array.*/
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
	FILE *fp;
	fp=fopen("data.txt","r");
	do
	{
		printf("\n------Choices------\n");
		printf("1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
		printf("Enter your choice = ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				fscanf(fp,"%d",&n);
				enque(n);
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
