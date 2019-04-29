/*Write a program to implement stack with required
operations using array.*/
#include<stdio.h>
#define N 20
int s[N],p=0;
void push(int n)
{
	if(p>N)
		printf("Overflow stack\n");
	else
		s[p++]=n;
}
void pop()
{
	if(p<=0)
		printf("Underflow stack\n");
	else
		printf("Poped element = %d\n",s[--p]);
}
int peep(int i)
{
	if(p-i<0)
		printf("Underflow stack\n");
	else
		return s[p-i];
}
void display()
{
	int i;
	for(i=p-1;i>=0;i--)
		printf("%d\n",s[i]);
}
void main()
{
	int c,n,i;
	FILE *fp;
	fp=fopen("data.txt","r");
	do
	{
		printf("\n-----Choices-----\n");
		printf("1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\n");
		printf("Enter your choice = ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				fscanf(fp,"%d",&n);
				push(n);
				display();
				break;
			case 2:
				pop();
				display();
				break;
			case 3:
				printf("Enter index number = ");
				scanf("%d",&i);
				printf("Element on %d index = %d\n",i,peep(i));
				break;
			case 4:
				printf("\n----Elements of stack----\n");
				display();
				break;
			case 5:
				break;
		}
	}while(c!=5);
}
