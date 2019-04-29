/*Given two values v1 and v2 (where v1 < v2) within a Binary
Search Tree. Print all the keys of tree in range v1 to v2. i.e.
print all x such that v1<=x<=v2 and x is a element of given
BST. (Create a Binary Search Tree by any method).*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*root=NULL;
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
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}	
}
void search(struct node* root,int v1,int v2)
{
	if(root==NULL)
		return;
	if(v1<root->data)
		search(root->left,v1,v2);
	if(v1<=root->data && v2>=root->data)
		printf("%d\t",root->data);
	if(v2>root->data)
		search(root->right,v1,v2);
}
void main()
{
	int a,v1,v2;
	FILE *fp;
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
	printf("\nEnter v1 and v2 = ");
	scanf("%d%d",&v1,&v2);
	search(root,v1,v2);
}
