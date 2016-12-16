#include<iostream>
using namespace std;
int find_min(int d[],int vis[],int n)
{
	int min=100;
	for(int i=0;i<n;i++)
	{
		if(d[i]<min&&d[i]!=0&&vis[i]==0)
		min=d[i];
	}
	for(int i=0;i<n;i++)
	{
		if(d[i]==min&&vis[i]==0)
		return i;
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
	int source,goal;
	cout<<"enter s g \n";
	cin>>source>>goal;
	int* d;int* pre;int* vis;
	d=new int[n];
	pre=new int[n];
	vis=new int[n];
	while(source>0&&goal>0)
	{
		int cur;
		cur=source-1;
		for(int i=0;i<n;i++)
		{
			d[i]=0;
			pre[i]=-1;
			vis[i]=0;
			if(i==source-1)
			vis[i]=1;
		}
		int ind;
		while(cur!=goal-1)
		{
			for(int i=0;i<n;i++)
			{
				if(g[cur][i]!=0)
				{
					if(d[i]==0||(d[cur]+g[cur][i])<d[i])
					{
						d[i]=g[cur][i]+d[cur];
						pre[i]=cur;
					}
				}
			}
			ind=find_min(d,vis,n);
			cur=ind;
			vis[cur]=1;
		}
		cout<<endl<<cur+1<<" ";
		while(cur!=source-1)
		{
			cout<<pre[cur]+1<<" ";
			cur=pre[cur];
		}
		cout<<"enter the source and goal\n";
		cin>>source>>goal;
	}
	return 0;
}
