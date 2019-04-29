#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
}*f=NULL,*r=NULL;
void enque(int n)
{
	struct queue *new;
	new=(struct queue *)malloc(sizeof(struct queue));
	new->next=NULL;
	new->data=n;
	if(f==NULL)
		f=new;
	else
		r->next=new;
	r=new;
}
void deque()
{
	struct queue *tmp;
	tmp=f;
	if(f==NULL)
		printf("\nUnderflow\n");
	else
	{
		f=f->next;
		printf("\nDequeued data = %d\n",tmp->data);
		free(tmp);
	}
}
void display()
{
	struct queue *tmp;
	tmp=f;
	if(f==NULL)
	{
		printf("\nQueue is empty\n");
		return;
	}
	printf("\n----Elements of queue----\n");
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
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
