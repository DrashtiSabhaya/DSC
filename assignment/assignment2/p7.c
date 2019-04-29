/*Write a program to create a binary tree. Implement
required method to generate a binary tree from user inputs
and check whether the Binary Tree is a perfect binary tree.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*root=NULL;
int count=0;
struct node* create(int n)
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	new->left=NULL;
	new->right=NULL;
	new->data=n;
	count++;
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
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}	
}
int complete(struct node* root,int i)
{
	if(root==NULL)
		return 1;
	if(i>=count)
		return 0;
	return (complete(root->left,2*i+1)&&complete(root->right,2*i+2));	
}
void main()
{
	FILE *fp;
	int i=0,a;
	fp=fopen("tree.txt","r");
	while(fscanf(fp,"%d",&a)==1)
	{
		if(root==NULL)
			root=create(a);
		else
			insert(root,a);
	}
	printf("\nIneorder = \t");
	inorder(root);
	a=complete(root,i);
	if(a)
		printf("\nThe binary tree is complete\n");
	else
		printf("\nThe binary tree is not complete binary tree\n");
}
