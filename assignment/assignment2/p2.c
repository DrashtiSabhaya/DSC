/*Implement linked list to create and manage a set of
elements. Set of elements contains integer values i.e. S =
{4,5,6}. Also implement a method which shows all possible
subsets of the created set by user i.e. {{4}, {5}, {6}, {4,5}, {4,6},
{5,6}, {4,5,6}, {Ø}}.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head=NULL;
int count=0;
void insert(int n)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	if(head!=NULL)
		new->next=head;
	head=new;
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
		printf("%d\n",tmp->data);
	}	
}
void powerset(int a)
{
	struct node* tmp=head,*cur=head;
	int cnt;
	if(a>count)
		return;
	while(tmp)
	{
		cnt=0;
		tmp=cur;
		printf("{ ");
		while(cnt<a && tmp!=NULL)
		{
			printf("%d ",tmp->data);
			tmp=tmp->next;
			cnt++;
		}
		printf("} ");
		cur=cur->next;
	}
	powerset(a+1);
}
void main()
{
	FILE *fp;int a;
	fp=fopen("powerset.txt","r");
	while(fscanf(fp,"%d",&a)==1)
		insert(a);
	display();
	powerset(1);
}
