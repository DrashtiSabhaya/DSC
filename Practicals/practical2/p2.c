/*Input a text from a user, enter search string and find the occurrence of the
search string and replace it with entered new string using UDF.*/
#include<stdio.h>
#include<string.h>
void replace(char[],char[],int []);
void main()
{
	char str[50],w[20];
	int i,j,cnt=0,cnt1=0,tmp[5];
	printf("Enter a string = ");
	scanf("%[^\n]",str);
	printf("Enter a word you want to serach = ");
	scanf("%s",w);
	i=0;
//	printf("%ld\n",strlen(str));
	while(str[i]!='\0')
	{
		j=0;
		cnt=0;
		while(str[i]==w[j] && w[j]!='\0')
		{
			cnt++;i++;j++;
		}
		if(cnt==strlen(w))
		{
			tmp[cnt1]=i-strlen(w);
			cnt1++;
			cnt=0;
		}
		else
			i++;
	}
	printf("%s is occur %d time(s)\n",w,cnt1);
	replace(str,w,tmp);
}
void replace(char str[],char w[],int t[])
{
	char new[20],temp[20];
	int i,j,k;
	printf("Enter new word for replace = ");
	scanf("%s",new);
	if(strlen(w)<strlen(new))
	{
		i=strlen(new)-strlen(w);
		for(k=strlen(str)+i;k>=t[0]+strlen(w);k--)
		{
			str[k]=str[k-i];
		}
	}
	if(strlen(w)>strlen(new))
	{
		i=strlen(w)-strlen(new);
		for(k=t[0]+strlen(w);str[k]!='\0';k++)
		{
			str[k-i]=str[k];
		}
		str[k-i]='\0';
	}

	for(i=t[0],j=0;j<strlen(new);i++)
	{
		str[i]=new[j++];
	}
	printf("%s\n",str);
}
