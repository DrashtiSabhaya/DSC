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
	count++;
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
int midnode()
{
	int cnt=0;
	struct node* tmp;
	tmp=head;
	if(head==NULL)
		printf("\nlist is Empty\n");
	else
	{
		while(tmp->next!=NULL)
		{
			if(cnt==(int)(count/2))
				return tmp->data;
			tmp=tmp->next;
			cnt++;
		}
	}
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
	printf("\nMiddle node of list = %d\n",midnode());
	display();	
}
