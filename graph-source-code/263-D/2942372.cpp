//Language: GNU C++


/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
#define fi first
#define se second
#define mp make_pair

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int n,m,k,x,y,tmp,now,ind,vis[100010],nxt[100010];

struct graph
{
	int a[100010],b[200010],c[200010],p;
	void addedge(int x,int y)
	{
		c[++p]=a[x]; a[x]=p; b[p]=y;
		c[++p]=a[y]; a[y]=p; b[p]=x;
	}
	void dfs()
	{
		vis[now=1]=ind=1;
		for(int i;;)
		{
			for(i=a[now];i;i=c[i]) if (!vis[b[i]])
			{
				nxt[now]=b[i];
				now=b[i];
				vis[now]=++ind;
				break;
			}
			if (!i)
			{
				tmp=-1;
				for(int j=a[now];j;j=c[j]) if (tmp==-1||vis[b[j]]<vis[tmp]) tmp=b[j];
				break;
			}
		}
	}
} A;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		A.addedge(x,y);
	}
	A.dfs();
	printf("%d\n",vis[now]-vis[tmp]+1);
	for(int i=tmp;i!=now;i=nxt[i]) printf("%d ",i);
	printf("%d\n",now);
	
	return 0;
}