/*doubly circular*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*head=NULL,*end=NULL;
void display()
{
	struct node* tmp;
	tmp=head;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		printf("\n----Elements----\n");
		while(tmp->next!=head)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}
		printf("%d\n",tmp->data);
		while(tmp->prev!=end)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->prev;
		}
		printf("%d\n",tmp->data);
	}	
}
void infirst(int n)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	new->prev=NULL;
	if(head==NULL)
	{
		head=new;
		end=new;
		new->next=head;
		new->prev=end;
	}
	else
	{
		head->prev=new;
		new->next=head;
		new->prev=end;
		head=new;
		end->next=head;
	}
	display();
}
void inlast(int n)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	end->next=new;
	new->prev=end;
	new->next=head;
	end=new;
	head->prev=new;
	display();
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
		while(cnt!=i)
		{
			tmp=tmp->next;
			cnt++;
		}
		new->next=tmp->next;
		tmp->next->prev=new;
		new->prev=tmp;
		tmp->next=new;
	}
	display();
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
		end->next=head;
		head->prev=end;
		printf("\nDeleted data = %d\n",tmp->data);
		free(tmp);
	}	
	display();
}
void dellast()
{
	struct node* tmp,*prev;
	tmp=head;
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		tmp=end;
		end=end->prev;
		end->next=head;
		head->prev=end;
		printf("\nDeleted data = %d\n",tmp->data);
		free(tmp);	
	}
	display();
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
				break;
			case 2:
				printf("\nEnter data = ");
				scanf("%d",&n);
				inlast(n);
				break;
			case 3:
				printf("\nEnter data = ");
				scanf("%d",&n);
				insert(n);
				break;
			case 4:
				delfirst();
				break;
			case 5:
				dellast();
				break;
			case 6:
				delete();
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
