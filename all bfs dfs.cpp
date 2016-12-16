#include<iostream>
using namespace std;
bool not_pres(int v,int *vis,int c)
{
	for(int i=0;i<c;i++)
	{
		if(vis[i]==v)
		return 0;
	}
	return 1;
}
void DFS(int v,int **g,int n,int *vis,int c)
{
	vis[c]=v;
	c++;	
	if(c==n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<vis[i]+1<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(g[v][i]&&not_pres(i,vis,c))
			DFS(i,g,n,vis,c);
		}
	}
	/*for(int i=0;i<n;i++)
	{
		if(not_pres(i,vis,c))
		{
			DFS(i,g,n,vis,c);	
		}
	}*/
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
		vis[i]=-1;
	}
	cout<<"enter the start vertex ";
	cin>>v;
	v--;
	cout<<"All DFS starting at vertex "<<v+1<<":"<<endl;
	DFS(v,g,n,vis,0);
	return 0;
}
