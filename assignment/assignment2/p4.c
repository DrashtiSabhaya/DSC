/*Implement a program to generate a linked list. For any
unsorted linked list, write a method that will delete any
duplicates from the linked list without using a temporary
buffer.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head=NULL,*end=NULL;
void insert(int n)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	if(head==NULL)
		head=new;
	else
		end->next=new;
	end=new;
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
		printf("%d\n",tmp->data);
	}	
}
void removedup()
{
	struct node *p1,*p2,*dup;
	p1=head;
	while(p1!=NULL && p1->next!=NULL)
	{
		p2=p1;
		while(p2->next!=NULL)
		{
			if(p1->data==p2->next->data)
			{
				dup=p2->next;
				p2->next=p2->next->next;
				free(dup);
			}
			else
				p2=p2->next;
		}
		p1=p1->next;
	}
}
void main()
{
	FILE *fp;int a;
	fp=fopen("data.txt","r");
	while(fscanf(fp,"%d",&a)==1)
		insert(a);
	display();
	removedup();
	display();
}
