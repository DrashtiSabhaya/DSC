/*Define a structure Student with personal and academic details.
Write functions to add element and read element from the
structure also write a function displayResult() to display result
of student. Note: use array of five students.*/
#include<stdio.h>
struct student
{
	int rno;float per;
	char nm[10],city[10];
	int m1,m2,m3,total;
}s[5];
void add(struct student s[]);
void display(struct student s[]);
void main()
{
	add(s);
	display(s);
}
void add(struct student s[])
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("\nEnter rollno=");
		scanf("%d",&s[i].rno);
		printf("Enter Name=");
		scanf("%s",s[i].nm);
		printf("Enter City=");
		scanf("%s",s[i].city);
		printf("Enter marks of 3 subjects=");
		scanf("%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3);
		s[i].total=s[i].m1+s[i].m2+s[i].m3;
		s[i].per=(float)s[i].total/3.0;
	}
}
void display(struct student s[])
{
	int i;	
	printf("\n\t----Student details----\n");
	printf("Rollno\tName\tcity\tTotal\tPercentage\n");
	for(i=0;i<5;i++)
		printf("%d\t%s\t%s\t%d\t%.2f\n",s[i].rno,s[i].nm,s[i].city,s[i].total,s[i].per);
}
