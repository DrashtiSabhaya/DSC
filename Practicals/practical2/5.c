/*Collect String from user and remove all characters from that string except
alphabet, display the count and list of removed characters. [Using UDF and
Pointer]*/
#include<stdio.h>
void main()
{
	char str[30],s[20],a[20];
	int i,cnt=0,j=0;
	printf("Enter a string = ");
	scanf("%[^\n]",str);
	for(i=0;str[i]!='\0';i++)
	{
		if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
			s[cnt++]=str[i];	
		else
			a[j++]=str[i];
		s[cnt]='\0';
		a[j]='\0';
	}
	printf("Alphabet = %s\n",s);
	printf("Number of removed character = %d\n",j);
	printf("Removed characters = %s\n",a);
}
