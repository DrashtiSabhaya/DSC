/*Write a program to create a binary tree. Implement
required method to generate a binary tree from user inputs
and to display binary tree using level order and pre order
traversals.*/
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
}*front=NULL,*end=NULL;
struct node* create(int n)
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	new->left=NULL;
	new->right=NULL;
	new->data=n;
	return new;
}
struct node* insert(struct node* root,int n)
{
	if(root==NULL)
	{
		root=create(n);
		return root;
	}
	if(n<root->data)
		root->left=insert(root->left,n);
	if(n>=root->data)		
		root->right=insert(root->right,n);
	return root;
}
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}	
}
void enque(struct node* n)
{
	struct que *new,*tmp;
	new=(struct que*)malloc(sizeof(struct que));
	new->data=n;
	new->next=NULL;
	if(front==NULL)
		front=end=new;
	else
		end->next=new;
	end=new;
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
	}
	return;
}
void main()
{
	int a;
	FILE *fp;
	fp=fopen("tree.txt","r");
	while(fscanf(fp,"%d",&a)==1)
	{
		if(root==NULL)
			root=create(a);
		else
			insert(root,a);
	}
	printf("\nPreorder = \t");
	preorder(root);
	printf("\nLevelorder = \t");
	enque(root);
	level(root);	
}
