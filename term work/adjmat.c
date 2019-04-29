#include<stdio.h>
#include<string.h>
#define N 50
int adj[N][N],visit[N],q[N],fl[N];
int f=0,r=-1;
int n,e;
void dfs(int i)
{
	int j;
	printf("%d\t",i);
	visit[i]=1;
	for(j=0;j<n;j++)
	{
		if(visit[j]==0&&adj[i][j]!=0)
			dfs(j);
	}
}
void bfs(int i)
{
	int j;
	printf("%d\t",i);
	visit[i]=1;
	for(j=0;j<n;j++)
	{
		if(visit[j]==0 && adj[i][j]!=0)
		{
			q[++r]=j;
			visit[j]=1;
		}
	}
	if(f>r)
		return;
	bfs(q[f++]);
	
}
int find(int c,int count,int tmp[])
{
	int i,j,cnt=0,t;
	for(i=0;i<count;i++)
	{
		for(j=0;j<n;j++)
		{
			if(adj[tmp[i]][j]!=0)
				fl[j]=1;
		}
	}
	fl[c]=0;
	for(i=0;i<n;i++)
	{
		if(fl[i]==1)
			cnt++;
	}
	return cnt;
}
void main()
{
	int i,j,s,d,w,t;
	int a,in[N],out[N],old[N],fr[N],fof[N],tmp[N];
	char file[20];
	float pop;
	FILE *fp;
	printf("Enter file name = ");
	scanf("%s",file);
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("Please enter valid name = ");
		return;
	}
	fscanf(fp,"%d%d",&n,&e);
	if(n==1 && e==0)
	{
		fscanf(fp,"%d",&t);
		printf("\nGraph is directed and unweighted\n");
		fscanf(fp,"%d%d",&n,&e);	
		printf("it has %d Nodes and %d Edges\n",n,e);
		for(i=0;i<e;i++)
		{
			fscanf(fp,"%d%d",&s,&d);
			adj[s][d]=1;
		}
		for(i=0;i<n;i++)
			visit[i]=0;
		printf("\nEnter first node for visit = ");
		scanf("%d",&a);
		printf("DFS Traversal =\t");
		dfs(a);	
		printf("\nBFS Traversal =\t");
		for(i=0;i<n;i++)
			visit[i]=0;
		bfs(a);
		for(i=0;i<=n;i++)
		{	
			in[i]=out[i]=0;
			for(j=0;j<=n;j++)
			{
				if(adj[i][j]==1)
					out[i]++;
				if(adj[j][i]==1)
					in[i]++;
			}
		}
		for(i=0;i<n;i++)
		{	
			if(out[i]==0)
			{
				if(in[i]>=t)
					printf("\n%d is popular\nfollows = %d\tFollowers = %d\n",i,out[i],in[i]);
				else
					printf("\nPerson %d is not popular\nfollows = %d\tFollowed by = %d\n",i,out[i],in[i]);
			}
			else
			{
				pop=(float)in[i]/(float)out[i];
				if(pop>=2)
					printf("\n%d is popular, Popularity score = %.2f\nfollows = %d\tFollowed by = %d\n",i,pop,out[i],in[i]);
				else
					printf("\n%d is not popular, Popularity score = %.2f\nfollows = %d\tFollowed by = %d\n",i,pop,out[i],in[i]);
			}
		}
		printf("\n");
	}
	if(n==0 && e==1)
	{
		printf("\nGraph is undirected and weighted\n");
		fscanf(fp,"%d%d",&n,&e);	
		printf("it has %d Nodes and %d Edges\n",n,e);
		for(i=0;i<e;i++)
		{
			fscanf(fp,"%d%d%d",&s,&d,&w);
			adj[s][d]=w;
			adj[d][s]=w;
		}
		for(i=0;i<n;i++)
			visit[i]=0;
		printf("\nEnter first node for visit = ");
		scanf("%d",&a);
		printf("DFS Traversal =\t");
		dfs(a);	
		printf("\nBFS Traversal =\t");
		for(i=0;i<n;i++)
			visit[i]=0;
		bfs(a);
		for(i=0;i<n;i++)
		{	
			out[i]=0;old[i]=0;
			fof[i]=0;
			for(j=0;j<n;j++)
			{
				fl[j]=0;
				fl[j]=0;visit[j]=0;
				if(adj[i][j]!=0)
				{
					tmp[out[i]]=j;
					out[i]++;
				}
				if(adj[j][i]>old[i])
				{
					old[i]=adj[j][i];
					fr[i]=j;
				}
			}
			fof[i]=find(i,out[i],tmp);
		}
		for(i=0;i<n;i++)
			printf("\nPerson %d has %d friends and %d Friends of Friends\noldest friend is %d [%d days]\n",i,out[i],fof[i],fr[i],old[i]);
	}
	printf("\n");
}
