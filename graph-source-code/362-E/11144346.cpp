//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;
int a[10000],next[10000],b[100],cost[10000],f[10000];
int num;
int dist[100];
int pe[100],px[100];
bool flag[100];
int n,k,x,dq,flow;
void addedge(int x,int y,int p,int q)
{
	a[num]=y;next[num]=b[x];b[x]=num;f[num]=p;cost[num]=q;++num;
	a[num]=x;next[num]=b[y];b[y]=num;f[num]=0;cost[num]=-q;++num;
}
bool spfa()
{
	int dqx,dqy;
	for (int i=1;i<=n;++i) dist[i]=1e7;
	dist[1]=0;
	memset(flag,false,sizeof(flag));
	flag[1]=true;
	while (!q.empty()) q.pop();
	q.push(1);
	while (!q.empty())
	{
		dqx=q.front();
		q.pop();
		for (int i=b[dqx];i!=-1;i=next[i])
		{
			dqy=a[i];
			if (f[i]>0&&dist[dqx]+cost[i]<dist[dqy])
			{
				dist[dqy]=dist[dqx]+cost[i];
				pe[dqy]=i;
				px[dqy]=dqx;
				if (!flag[dqy])
				{
					q.push(dqy);
					flag[dqy]=true;
				}
			}
		}
		flag[dqx]=false;
	}
	if (dist[n]<1e7) return true;
	else return false;
}
int main()
{
	num=0;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i) b[i]=-1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			scanf("%d",&x);
			if (x==0) continue;
			addedge(i,j,x,0);
			addedge(i,j,1e7,1);
		}
	while (spfa()&&k>=0)
	{
		x=n;
		dq=1e7;
		while (x!=1)
		{
			dq=min(dq,f[pe[x]]);
			x=px[x];
		}
		x=n;
		while (x!=1)
		{
			f[pe[x]]-=dq;
			f[pe[x]^1]+=dq;
			x=px[x];	
		}
		if (dq*dist[n]<=k)
		{
			flow+=dq;
			k-=dq*dist[n];
		}
		else
		{
			flow+=k/dist[n];
			k=-1;
		}
	}
	printf("%d\n",flow);
	return 0;
}
  				     		  			 	  			 	