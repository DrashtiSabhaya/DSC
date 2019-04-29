/*simple link list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head=NULL;
int count=0;
void create(int n)
{
	struct node *new,*tmp;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	tmp=head;
	if(head==NULL)
		head=new;
	else
	{
		while(tmp->next!=NULL)
			tmp=tmp->next;
		tmp->next=new;
	}
}
void display()
{
	struct node* tmp;
	tmp=head;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		printf("\n----Elements----\n");
		while(tmp->next!=NULL)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}
		printf("%d\t",tmp->data);
	}	
}
int length(struct node* head)
{
	if(head==NULL)
		return 0;
	else
	return 1+length(head->next);
	/*
	struct node* tmp;
	tmp=head;
	while(tmp)
	{
		count++;
		tmp=tmp->next;
	}
	return count;*/
	
}
void main()
{
	int c,n,i,tmp;
	printf("Enter no of nodes you want to enter = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element = ");
		scanf("%d",&c);
		create(c);
	}
	printf("\nLength of list = %d\n",length(head));
	display();	
}
