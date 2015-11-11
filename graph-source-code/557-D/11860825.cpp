//Language: GNU C++


#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<vector>
#include<iostream>
#include<cmath>
#include<string>
#define N 500010
#define M 1010
#define P 1000000007
using namespace std;
int dp,pre[N],p[N],tt[N],a[N],b[N],vis[N],i,flag[N];
long long n,m,ans,rd[N],u,v,tmp;
map<int,int>ma;
void link(int x,int y)
{
	dp++;pre[dp]=p[x];p[x]=dp;tt[dp]=y;
}
void dfs(int x)
{
	int i;
	if (flag[x]==0) u++;else v++;
	vis[x]=1;
	i=p[x];
	while (i)
	{
		if (vis[tt[i]]==0)
		{
			flag[tt[i]]=1-flag[x];
			dfs(tt[i]);
		}
		i=pre[i];
	}
}
void dis(int x,int d,int fa)
{
	int i;
	i=p[x];
	if (d==2)
	{
		if (ma[x]==0)
		{
			ma[x]=1;
			ans++;
		}
		return;
	}
	while (i)
	{
		if (tt[i]!=fa)
			dis(tt[i],d+1,x);
		i=pre[i];
	}
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		link(a[i],b[i]);
		link(b[i],a[i]);
		rd[a[i]]++;
		rd[b[i]]++;
	}
	if (m==0)
	{
		cout<<3<<" "<<n*(n-1)*(n-2)/6;
		return 0;
	}
	for (i=1;i<=n;i++)
	if (vis[i]==0)
	{
		u=0;v=0;
		dfs(i);
		tmp=tmp+u*(u-1)/2+v*(v-1)/2;
	}
	for (i=1;i<=m;i++)
	{
		if (flag[a[i]]==flag[b[i]])
		{
			cout<<0<<" "<<1;
			return 0;
		}
	}
	for (i=1;i<=n;i++)
	if (rd[i]>1) ans++;
	if (ans==0)
		cout<<2<<" "<<m*(n-2);
	else
		cout<<1<<" "<<tmp;
} 