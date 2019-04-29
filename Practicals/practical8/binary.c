#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*root;
struct node* create(int n)
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	new->left=NULL;
	new->right=NULL;
	new->data=n;
	return new;
}
void display(struct node* root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("%d\t",root->data);
		display(root->right);
	}	
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
	display(root);
}
