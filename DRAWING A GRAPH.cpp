#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
void addend (lptr &h,int a)
{
	if(h==NULL)
	{
		h=new node;
		h->next=NULL;
		h->data=a;
		return;
	}
	lptr t=h;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new node;
	t=t->next;
	t->data=a;
	t->next=NULL;
}
bool is_adj(int **g,int i,int j)
{
	return g[i][j];
}
int degree(int **g,int n,int v)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(g[v][i])
		c++;
	}
	return c;
}
int first(int **g,lptr h,int n)
{
	while(h!=NULL)
	{
		if(degree(g,n,h->data)!=0)
		{
			return h->data;
		}
		h=h->next;
	}
	return -1;
}
void dft(int v,int n,int **g,lptr &h)
{
	if(degree(g,n,v)==0)
	{
		int x=first(g,h,n);
		if(x==-1) return;
		lptr temp=NULL;
		for(int i=0;i<n;i++)
		{
			if(is_adj(g,x,i))
			{
				cout<<x<<" "<<i<<"are adj"<<" add this to temp "<<x<<" "<<i<<endl;
				g[x][i]=0;
				g[i][x]=0;
				addend(temp,x);
				addend(temp,i);
				dft(i,n,g,temp);
				break;
			}
		}
		if(h->data==x)
		{
			lptr poi=h->next;
			delete h;
			lptr z=temp;
			while(z->next!=NULL) 
			z=z->next;
			z->next=poi;
			h=temp;
		}
		else
		{
			lptr t=h;
			while(t->next->data!=x)
			t=t->next;
			lptr poi=t->next->next;
			lptr del=t->next;
			t->next=temp;
			while(temp->next!=NULL) 
			temp=temp->next;
			temp->next=poi;
			delete del;
		}
		x=first(g,h,n);
		if(x==-1) return;
		dft(x,n,g,h);
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(is_adj(g,v,i))
			{
				cout<<v<<" "<<i<<"are adjacent  add "<<i<<endl;
				addend(h,i);
				g[v][i]=0;
				g[i][v]=0;
				dft(i,n,g,h);
				break;
			}
		}
	}
}
void print(lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		if(t->data!=-1)
		cout<<t->data<<" ";
		t=t->next;
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
	cout<<"degree sequence : ";
	for(int i=0;i<n;i++)
	{
		cout<<degree(g,n,i)<<" ";
	}
	cout<<endl;
	int o=0;
	for(int i=0;i<n;i++)
	{
		if(degree(g,n,i)%2==1)
		o++;
	}
	lptr h=NULL;
	if(o==0)
	{
		cout<<"add 0"<<endl;
		addend(h,0);
		dft(0,n,g,h);
		cout<<endl<<"sequence : ";
		print(h);
	}
	else
	if(o==2)
	{
		for(int i=0;i<n;i++)
		{
			if(degree(g,n,i)%2==1)
			{
				cout<<"add "<<i<<endl;
				addend(h,i);
				dft(i,n,g,h);
				break;
			}
		}
		cout<<endl<<"sequence ";
		print(h);
	}
	else
	{
		cout<<"not possible ";
	}
	return 0;
}
