//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
#define X first
#define Y second
#define mp make_pair
typedef pair<int,int> pii;
int n,m,x,y,din[100005],dout[100005],de[100005];
bool vis[100005];
pii e[600000];
int dq;
vector<int> v[100005];
int dfs(int x)
{
	vis[x]=true;
	for (int i=0;i<v[x].size();++i)
	{
		int id=v[x][i];
		if (x==e[id].X) y=e[id].Y;else y=e[id].X;
		if (vis[y]) continue;
		int dq=dfs(y);
		if (dq%2==1)
		{
			swap(e[id].X,e[id].Y);
			din[x]^=1;
			dout[x]^=1;
		}
	}
	return din[x]%2;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		din[y]++;dout[x]++;
		de[x]++;de[y]++;
		e[i]=mp(x,y);
		v[x].push_back(i);
		v[y].push_back(i);
	}
	dq=0;
	for (int i=1;i<=n;++i)
		if (de[i]%2==1)
		{
			if (dq!=0)
			{
				de[i]++;de[dq]++;
				dout[i]++;din[dq]++;
				e[++m]=mp(i,dq);
				v[i].push_back(m);
				v[dq].push_back(m);
				dq=0;
			}
			else dq=i;
		}
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;++i)
	{
		if (!vis[i])
		{
			dfs(i);
			if (din[i]%2==1) e[++m]=mp(i,i);
		}
	}
	printf("%d\n",m);
	for (int i=1;i<=m;++i)
		printf("%d %d\n",e[i].X,e[i].Y);
	return 0;
}