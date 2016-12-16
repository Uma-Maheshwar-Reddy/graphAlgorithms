#include<iostream>
using namespace std;
int disconn(int**g,int* v,int n)
{
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		return i;
	}
	return -1;
}
bool is_adj(int **g,int i,int j)
{
	return g[i][j];
}
void dft(int v,int *vis,int n,int **g)
{
	vis[v]=1;
	cout<<v+1<<" ";
	for(int i=0;i<n;i++)
	{
		if(is_adj(g,v,i))
		{
			if(!vis[i])
			dft(i,vis,n,g);
		}
	}
	int c=disconn(g,vis,n);
	if(c!=-1)
	{
		dft(c,vis,n,g);
	}
}
void bft(queue &q,int v,int *vis,int n,int **g)
{
	vis[v]=1;
	enque(q,v);
	int p;
	while(q.front!=-1)
	{
		p=deque(q);
		cout<<p+1<<" ";
		for(int i=0;i<n;i++)
		{
			if(is_adj(g,p,i))
			{
				if(!vis[i])
				{
					enque(q,i);
					vis[i]=1;
				}
			}
		}
	}
	int c=disconn(g,vis,n);
	if(c!=-1)
	{
		bft(q,c,vis,n,g);
	}
}
int main()
{
	int n;
	cout<<"enter the number of vertices of the graph ";
	cin>>n;
	int **g;
	g=new int* [n];
	for(int i=0;i<n;i++)
	{
		g[i]=new int[n];
	}
	cout<<"enter the matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
	int v;
	int *vis;
	vis=new int[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	cout<<"enter the vertex where you strt ";
	cin>>v;
	v--;
	cout<<"DEPTH FIRST TRAVERSAL : ";
	dft(v,vis,n,g);
	cout<<endl;
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	cout<<"BREADTH FIRST TRAVERSAL : ";
	bft(q,v,vis,n,g);
	return 0;
}
