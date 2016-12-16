#include<iostream>
using namespace std;
bool is_adj(int **g,int i,int j)
{
	return g[i][j];
}
int child(int v,int *par,int n)
{
	for(int i=0;i<n;i++)
	{
		if(par[i]==v)
		return i;
	}
	return -1;
}
void dfs(int &p,int v,bool* vis,int **g,int n,int *par,int &c,int *num)
{
	vis[v]=1;
	num[v]=c;
	c++;
	par[v]=p;
	for(int i=0;i<n;i++)
	{
		if(is_adj(g,v,i)&&!vis[i])
		{
			dfs(v,i,vis,g,n,par,c,num);
		}
	}
}
int assign_low(int **g,int n,int *par,int *num,int v)
{
	int a,b=100,c=100;
	a=num[v];
	for(int i=0;i<n;i++)
	{
		if(par[i]==v)
		{
			b=assign_low(g,n,par,num,i);
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(is_adj(g,v,i)&&par[v]!=i&&num[v]>num[i]&&num[i]<c)
		{
			c=num[i];
		}
	}
	int d;
	d=min(a,b);
	return min(d,c);
}
bool chil(int v,int *par,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(par[i]==v)
		c++;
	}
	if(c==1)
	return 0;
	else
	return 1;
}
bool no_child(int v,int* par,int n)
{
	for(int i=0;i<n;i++)
	{
		if(par[i]==v)
		return 0;
	}
	return 1;
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
	bool *vis;
	vis=new bool[n];
	int *chi;
	int *par;
	int *num;
	int *low;
	chi=new int[n];
	par=new int[n];
	low=new int[n];
	num=new int[n];
	int p=-1,v=0,c=0;
	dfs(p,v,vis,g,n,par,c,num);
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		low[i]=assign_low(g,n,par,num,i);
	}
	cout<<endl;
	int art[10];
	int ind=0;
	cout<<"THE ARTICULATION POINTS ARE : ";
	for(int v=0;v<n;v++)
	{
		for(int w=0;w<n;w++)
		{
			if(is_adj(g,v,w)&&low[w]>=num[v]&&par[w]==v)
			{
				if(par[v]!=-1)
				{
					art[ind]=v;
					ind++;
				}
				else
				if(chil(v,par,n))
				{
					art[ind]=v;
					ind++;
				}
			}
		}
	}
	for(int i=0;i<ind;i++)
	{
		cout<<art[i]<<" ";
	}
	cout<<endl<<"BICONNECTED COMPONENTS : "<<endl;
	for(int i=0;i<ind;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j]==art[i])
			{
				if(no_child(j,par,n))
				{
					cout<<art[i]<<" "<<j;
				}
			}
		}
	}
	for(int v=0;v<n;v++)
	for(int i=0;i<n;i++)
	{
		if(is_adj(g,v,i)&&par[v]!=i&&num[v]>num[i])
		{
			cout<<endl;
			p=v;
			while(1)
			{
				cout<<p<<" ";
				if(p==i)
				break;
				p=par[p];
			}
		}
	}
	return 0;
}
