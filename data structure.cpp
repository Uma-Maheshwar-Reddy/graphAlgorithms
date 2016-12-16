#include<iostream>
#include<cstring>
using namespace std;
union u
{
	struct leafnode* poi;
	struct trienode* ptr[4];
};
struct leafnode
{
	char *ch;
};
typedef
struct trienode
{
	int tag;
	union u dir;
}*trie;
int index(char c)
{
	if(c=='A'||'a') return 0;
	if(c=='B'||'b') return 1;
	if(c=='C'||'c') return 2;
	return 3;
}
void insert(trie &h,char* k,int u,int len)
{
	int id;
	id=index(k[u]);
	trie t;
	t=h->dir.ptr[id];
	if(t==NULL)
	{
		t=new trienode;
		t->tag=0;
		t->dir.poi=new leafnode;
		t->dir.poi->ch=new char[len+1];
		strcpy(t->dir.poi->ch,k);
		h->dir.ptr[id]=t;
	}
	else
	if(t->tag==0)
	{
		char k1[10];
		strcpy(k1,t->dir.poi->ch);
		t->tag=1;
		for(int i=0;i<4;i++)
		t->dir.ptr[i]=NULL;
		insert(t,k1,u+1,strlen(k1));
		insert(t,k,u+1,len);
	}
	else
	{
		insert(h->dir.ptr[id],k,u+1,len);
	}
}
void print(trie h)
{
	if(h==NULL)
	return;
	else
	{
		if(h->tag==1)
		{
			for(int i=0;i<4;i++)
			{
				print(h->dir.ptr[i]);
			}
		}
		else
		if(h->tag==0)
		{
			cout<<h->dir.poi->ch<<" ";
		}
	}
}
int main()
{
	trie h;
	h=new trienode;
	h->tag=1;
	for(int i=0;i<4;i++)
	h->dir.ptr[i]=NULL;
	char key[10];
	int z;
	cout<<"1:enter key 2: exit  ";
	cin>>z;
	int len;
	while(z==1)
	{
		cout<<"enter the key word"<<endl;
		cin>>key;
		len=strlen(key);
		insert(h,key,0,len);
		print(h);
		cout<<endl;
		cout<<"1:enter key 2: exit  ";
		cin>>z;
	}
	
	return 0;
}
