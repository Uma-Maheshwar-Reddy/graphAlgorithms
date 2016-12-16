#include<iostream>
using namespace std;
struct heap
{
	int len;
	int v1;
	int v2;
};
void swap(heap &a,heap &b)
{
	heap temp;
	temp.len=a.len;
	temp.v1=a.v1;
	temp.v2=a.v2;
	a.len=b.len;
	a.v1=b.v1;
	a.v2=b.v2;
	b.len=temp.len;
	b.v1=temp.v1;
	b.v2=temp.v2;
}
void percolate_up(heap *h,int &s,heap &k)
{
	s++;
	h[s].len=k.len;
	h[s].v1=k.v1;
	h[s].v2=k.v2;
	int j=s;
	while(j!=0&&h[j].len<h[j/2].len)
	{
		swap(h[j],h[j/2]);
		j=j/2;
	}
}
heap percolate_down(heap *h,int &s)
{
	if(s==0)
	{
		cout<<"error ";
	}
	else
	{
		heap r;
		r.len=h[1].len;
		r.v1=h[1].v1;
		r.v2=h[1].v2;
		h[1].len=h[s].len;
		h[1].v1=h[s].v1;
		h[1].v2=h[s].v2;
		s--;
		int j=1;
		while(2*j<=s&&(h[j].len>h[2*j].len||h[j].len>h[2*j+1].len))
		{
			if(h[2*j].len<h[2*j+1].len)
			{
				swap(h[j],h[2*j]);
				j=2*j;
			}
			
			else
			{
				swap(h[j],h[2*j+1]);
				j=2*j+1;
			}
		
		}
		return r;
	}
}
void print(heap* h,int s)
{
	cout<<endl<<"HEAP"<<endl;
	for(int i=1;i<=s;i++)
	{
		cout<<h[i].len<<" "<<h[i].v1<<" "<<h[i].v2<<endl;
	}
	cout<<"end "<<endl;
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
	heap* h;
	h=new heap[30];
	heap in;
	int s=0;
	h[s].len=-1;
	h[s].v1=-1;
	h[s].v2=-1;
	cout<<"enter the matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
	int v;
	cout<<"enter the start vertex ";
	cin>>v;
	bool vis[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	int count=1;
	while(count<n)
	{
		vis[v]=1;
		for(int i=0;i<n;i++)
		{
			if(g[v][i]!=0&&vis[i]==0)
			{
				in.len=g[v][i];
				in.v1=v;
				in.v2=i;
				cout<<"input "<<in.len<<" "<<in.v1<<" "<<in.v2<<endl;
				percolate_up(h,s,in);
			}
		}
 		in=percolate_down(h,s);
 		cout<<"delete is "<<in.len<<" "<<in.v1<<" "<<in.v2<<endl<<endl;
 		if(vis[in.v1]==0||vis[in.v2]==0)
 		{
 			cout<<in.len<<" v1:"<<in.v1<<" v2:"<<in.v2<<endl<<endl;
	 		count++;
	 		vis[in.v1]=1;
	 		vis[in.v2]=1;
		}
		v=in.v2;
	}
	return 0;
}
