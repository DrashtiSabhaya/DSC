#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*top=NULL;
void push(int n)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	if(top!=NULL)
		new->next=top;
	top=new;	
}
void pop()
{
	struct node* tmp;
	if(top==NULL)
		printf("\nList is empty\n");
	else
	{
		tmp=top;
		top=top->next;
		printf("\nDeleted data = %d\n",tmp->data);
		free(tmp);
	}	
}
void search(int n)
{
	int flag=0;
	struct node* tmp;
	if(top==NULL)
		printf("\nlist is Empty\n");
	else
	{
		tmp=top;
		while(tmp!=NULL)
		{
			if(tmp->data==n)
				flag++;
			tmp=tmp->next;
		}
		if(flag!=0)
			printf("\n%d is found\n",n);
		else
			printf("\n%d is not found\n",n);
	}	

}
void display()
{
	struct node* tmp;
	tmp=top;
	if(top==NULL)
		printf("\nlist is Empty\n");
	else
	{
		printf("\n----Elements of stack----\n");
		while(tmp->next!=NULL)
		{
			printf("%d\n",tmp->data);
			tmp=tmp->next;
		}
		printf("%d\n",tmp->data);
	}	
}
void main()
{
	int c,n,i;
	do
	{
		printf("\n-----Choices-----\n");
		printf("1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\n");
		printf("Enter your choice = ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter a element for push = ");
				scanf("%d",&n);
				push(n);
				display();
				break;
			case 2:
				pop();
				display();
				break;
			case 3:
				printf("Enter number for search = ");
				scanf("%d",&i);
				search(i);
				break;
			case 4:
				display();
				break;
			case 5:
				break;
		}
	}while(c!=5);
}
