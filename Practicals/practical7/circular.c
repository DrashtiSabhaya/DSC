/*singly circular*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head=NULL;
void infirst(int n)
{
	struct node *new,*tmp;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		new->next=head;
	}
	else
	{
		tmp=head;
		do
		{
			tmp=tmp->next;
		}while(tmp->next!=head);
		new->next=head;
		head=new;
		tmp->next=head;
	}
}
void inlast(int n)
{
	struct node *new,*tmp;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	tmp=head;
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		do
		{
			tmp=tmp->next;
		}while(tmp->next!=head);
		tmp->next=new;
	}
	new->next=head;
}
void insert(int n)
{
	int i,cnt=1;
	struct node *new,*tmp;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	printf("Enter index where you want to insert = ");
	scanf("%d",&i);
	tmp=head;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		while(cnt!=i)
		{
			tmp=tmp->next;
			cnt++;
		}
		new->next=tmp->next;
		tmp->next=new;
	}
}
void delfirst()
{
	struct node *tmp,*tmp1;
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		tmp1=head;
		tmp=head;
		do
		{
			tmp=tmp->next;
		}while(tmp->next!=head);
		head=head->next;
		tmp->next=head;
		printf("\nDeleted data = %d\n",tmp1->data);
		free(tmp1);
	}	
}
void dellast()
{
	struct node* tmp,*prev;
	tmp=head;
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		do
		{
			prev=tmp;
			tmp=tmp->next;
		}while(tmp->next!=head);
		printf("\nDeleted data = %d\n",tmp->data);
		prev->next=head;
		free(tmp);	
	}
}
void delete()
{
	int i,cnt=1;
	struct node *tmp,*prev;
	printf("Enter index which you want to delete = ");
	scanf("%d",&i);
	tmp=head;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		while(cnt!=i)
		{
			prev=tmp;
			tmp=tmp->next;
			cnt++;
		}
		prev->next=tmp->next;
		printf("\nDeleted data = %d\n",tmp->data);
		free(tmp);	
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
		do
		{
			if(tmp->data==n)
				flag++;
			tmp=tmp->next;
		}while(tmp!=head);
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
		do
		{
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}while(tmp!=head);
	}	
}
void main()
{
	int ch,n;
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
				printf("\nEnter data = ");
				scanf("%d",&n);
				infirst(n);
				display();
				break;
			case 2:
				printf("\nEnter data = ");
				scanf("%d",&n);
				inlast(n);
				display();
				break;
			case 3:
				printf("\nEnter data = ");
				scanf("%d",&n);
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
