#include<iostream>
using namespace std;
int indegree(int **g,int v,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(g[i][v])
		c++;
	}
	return c;
}
bool is_adj(int **g,int i,int j)
{
	return g[i][j];
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
	int *in;
	in=new int[n];
	for(int i=0;i<n;i++)
	{
		in[i]=indegree(g,i,n);
	}
	int c=0;
	while(c<n)
	{
		for(int i=0;i<n;i++)
		{
			if(in[i]==0)
			{
				cout<<i+1<<"  ";
				c++;
				in[i]=-1;
				for(int j=0;j<n;j++)
				{
					if(is_adj(g,i,j))
					in[j]--;
				}
			}
		}
	}
	return 0;
}
