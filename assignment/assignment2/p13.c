/*Write a program to implement Doubly Linked List.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*head=NULL,*end=NULL;
void display();
void infirst(int n)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	new->prev=NULL;
	if(head!=NULL)
	{
		new->next=head;
		head->prev=new;
		head=new;
	}
	else
		head=end=new;
}
void inlast(int n)
{
	struct node *new,*tmp;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	new->prev=NULL;
	tmp=head;
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		end->next=new;
		new->prev=end;
	}
	end=new;
}
void insert(int n)
{
	int i,cnt=1;
	struct node *new,*tmp;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	new->prev=NULL;
	printf("Enter index where you want to insert = ");
	scanf("%d",&i);
	tmp=head;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		while(cnt!=i-1)
		{
			tmp=tmp->next;
			cnt++;
		}
		new->next=tmp->next;
		tmp->next->prev=new;
		tmp->next=new;
		new->prev=tmp;
	}
}
void delfirst()
{
	struct node* tmp;
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		tmp=head;
		head=head->next;
		head->next->prev=head;
		head->prev=tmp->prev;
		tmp->prev=head;
		printf("\nDeleted data = %d\n",tmp->data);
		free(tmp);
	}	
}
void dellast()
{
	struct node* tmp,*prev;
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		tmp=end;
		end=end->prev;
		end->next=NULL;
		printf("\nDeleted data = %d\n",tmp->data);
		free(tmp);	
	}
}
void delete()
{
	int i,cnt=1;
	struct node *tmp,*p;
	printf("Enter index which you want to delete = ");
	scanf("%d",&i);
	tmp=head;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		while(cnt!=i)
		{
			p=tmp;
			tmp=tmp->next;
			cnt++;
		}
		if(tmp==head)
			delfirst();
		else if(tmp==end)
			dellast();
		else
		{
			p->next=tmp->next;
			p->next->prev=p;
			printf("\nDeleted data = %d\n",tmp->data);
			free(tmp);	
			display();
		}
	}
}
void search(int n)
{
	int flag=0;
	struct node* tmp;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		tmp=head;
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
		while(tmp!=NULL)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->prev;
		}
	}	
}
void main()
{
	int ch,n;
	FILE *fp;
	fp=fopen("data.txt","r");
	do
	{
		printf("\n\n-----Choice------\n");
		printf("1.Insert at first\n2.Insert at last\n3.Insert at desire place\n4.Delete from first\n");
		printf("5.Delete from last\n6.Delete from given location\n7.Search\n8.Display\n9.Exit\n");
		printf("Enter your choice = ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(fscanf(fp,"%d",&n))
					infirst(n);
				display();
				break;
			case 2:
				if(fscanf(fp,"%d",&n))
					inlast(n);
				display();
				break;
			case 3:
				if(fscanf(fp,"%d",&n))
				insert(n);
				display();
				break;
			case 4:
				delfirst();
				display();
				break;
			case 5:
				dellast();
				display();
				break;
			case 6:
				delete();
				display();
				break;
			case 7:
				printf("\nEnter a element you want to search = ");
				scanf("%d",&n);
				search(n);
				break;
			case 8:
				display();
				break;
			case 9:
				break;
		}
	}while(ch!=9);
}
