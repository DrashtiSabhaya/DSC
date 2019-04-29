/*Write a program to implement Queue with all basic
operations using linked list.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*front=NULL,*rear=NULL;
void enque(int n)
{
	struct node *new,*tmp;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	tmp=front;
	if(front==NULL)
		front=rear=new;
	else
		rear->next=new;
	rear=new;
}
void deque()
{
	struct node* tmp;
	if(front==NULL)
		printf("\nList is empty\n");
	else
	{
		tmp=front;
		front=front->next;
		printf("\nDeleted data = %d\n",tmp->data);
		free(tmp);
	}	
}
void display()
{
	struct node* tmp;
	tmp=front;
	if(front==NULL)
		printf("\nlist is Empty\n");
	else
	{
		printf("\n----Elements----\n");
		while(tmp!=NULL)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}
		printf("\n");
	}	
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
				printf("Enter element = ");
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
