/*Create function called swap ( ), which swaps the number
values. Create a function pointer which points to a swap ( )
function and call function using pointer. Write a program
which also checks whether the two number entered by user is
palindrome or not after swaping.*/
#include<stdio.h>
#include<string.h>
void swap(int a,int b)
{
	FILE *fp;
	fp=fopen("swap.txt","w");
	int tmp;
	tmp=a;
	a=b;
	b=tmp;	
	fprintf(fp,"%d %d\n",a,b);
	printf("After swap = %d %d\n",a,b);
	fclose(fp);
}
void palindrom(int i)
{
	int j,r=0;
	j=i;
	while(j>0)
	{
		r=r*10;
		r=r+j%10;
		j=j/10;
	}
	if(i==r)
		printf("\n%d is palindrom\n",i);
	else
		printf("\n%d is not palindrom\n",i);
}
void main()
{
	FILE *fp;
	fp=fopen("swap.txt","r+");
	int a,b;
	void (*funp)(int,int)=&swap;
	fscanf(fp,"%d%d",&a,&b);
	printf("Before swap = %d %d\n",a,b);
	(*funp)(a,b);
	palindrom(a);
	palindrom(b);
	fclose(fp);
}
