#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*root=NULL;
struct que
{
	struct node* data;
	struct que* next;
}*front=NULL;
struct node* create(int n)
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	new->left=NULL;
	new->right=NULL;
	new->data=n;
	return new;
}
void enque(struct node* n)
{
	struct que *new,*tmp;
	new=(struct que*)malloc(sizeof(struct que));
	new->data=n;
	new->next=NULL;
	if(front==NULL)
		front=new;
	else
	{
		tmp=front;
		while(tmp->next!=NULL)
			tmp=tmp->next;
		tmp->next=new;
	}
}
struct node* deque()
{
	struct que *tmp;
	if(front!=NULL)
	{
	tmp=front;
	front=front->next;
	printf("%d\t",tmp->data->data);
	free(tmp);
	}
	return NULL;
}
void level(struct node* root)
{
	if(root!=NULL)
	{
		if(root->left!=NULL)
			enque(root->left);
		if(root->right!=NULL)
			enque(root->right);
		deque();
		if(front!=NULL)
			level(front->data);
		//printf("%d\t",front->next->data->data);
	}
	return;
}
int main()
{
	root=create(12);
	root->left=create(7);
	root->left->left=create(4);
	root->left->right=create(9);
	root->left->right->right=create(11);
	root->right=create(22);
	root->right->left=create(18);
	root->right->right=create(27);
	enque(root);
	level(root);
	//level(front->data);
}
