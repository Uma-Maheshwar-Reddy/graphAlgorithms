#include<iostream>
using namespace std;
struct queue
{
	int front;
	int rear;
	int elem[100];
	int size;
};
void enque(struct queue &q,int &a)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"the queue is full"<<endl;
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=a;
	}
}
int deque(struct queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		int t=q.elem[q.front];
		if(q.front==q.rear)
		{
			q.rear=-1;
			q.front=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
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
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=10;
	int x;
	for(int i=0;i<n;i++)
	{
		if(in[i]==0)
		{
			enque(q,i);
		}
	}
	while(q.front!=-1)
	{
		x=deque(q);
		cout<<x+1<<" ";
		in[x]--;
		for(int j=0;j<n;j++)
		{
			if(is_adj(g,x,j))
			{
				in[j]--;
				if(in[j]==0)
				{
					enque(q,j);
				}
			}
		}
	}
	return 0;
}
