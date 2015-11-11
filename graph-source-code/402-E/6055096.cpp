//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<set>
using namespace std;
#define INF 1000000000
//typedef __int64 LL;
#define N 2005
int n,tot,hh[N*N],dfn[N],low[N],flag,ad=0,ins[N],cou;
struct node
{
	int u,next;
}edge[N*N];
stack<int > s;
void init()
{
	tot=0;
	memset(hh,-1,sizeof(hh));
	memset(dfn,0,sizeof(dfn));
	memset(ins,0,sizeof(ins));
}
void add(int x,int y)
{
	edge[tot].u=y; edge[tot].next=hh[x];
	hh[x]=tot++;
}
void tar(int u)
{
	if(flag) return ;
	dfn[u]=low[u]=++ad;
	s.push(u);
	ins[u]=1;// printf("%d\n",u);
	for(int i=hh[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].u;// printf("%d \n",v);
		if(!dfn[v])
		{
			tar(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u])
	{ //printf("don");
		int m=s.top();  s.pop();
		cou++;
		if(cou>1) { flag=1; return ;}
		ins[m]=0;
		while(m!=u)
		{
			m=s.top(); s.pop(); ins[m]=0;
		}
	}
}
void sol()
{
	cou=0; flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tar(i);
			if(flag)
			{
				printf("NO\n"); return ;
			}
		}
	}
	printf("YES\n");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
#endif
	scanf("%d",&n);
	int tmp;
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&tmp);
			if(tmp)
			{
				add(i,j);
			}
		}
	}		//	printf("flag : %d \n",edge[0].next);
	int mark=0;
	//for(int i=hh[1];i!=-1 && mark<=8;i=edge[i].next) printf("%d tot: %d ",edge[i].u,i),mark++;
	sol();

    return 0;
}
