//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define MM 2005
using namespace std;
vector<int>vt[MM];
stack<int>s;
int dfn[MM],low[MM],instack[MM],index;
int Bcnt,Belong[MM];
void tarjan(int u)
{
	dfn[u]=low[u]=++index;
	s.push(u);
	instack[u]=1;
	int v;
	for(int i=0;i<vt[u].size();i++)
	{
		v=vt[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			if(low[u]>low[v])low[u]=low[v];
		}
		else if(instack[v])
		{
			if(low[u]>dfn[v])low[u]=dfn[v];
		}
	}
	if(low[u]==dfn[u])
	{
		Bcnt++;
		do{
			v=s.top();
			s.pop();
			instack[v]=0;
			Belong[v]=Bcnt;
		}while(u!=v);
	}
}
void solve(int n)
{
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
	index=Bcnt=0;;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
}
int main()
{
	int n,m,i,j,k,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		vt[i].clear();
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&k);
			if(k&&i!=j){
				vt[i].push_back(j);
			}
		}
		solve(n);
		if(Bcnt==1)printf("YES\n");
		else printf("NO\n");
	}
}
	  		 			 				      			  	