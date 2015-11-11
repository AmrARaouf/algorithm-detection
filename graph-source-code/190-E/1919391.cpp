//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>

using namespace std;

#define MAXN 500010

vector<int>g[MAXN];
vector<int>Ans[MAXN];

int n,m;

int sck[MAXN];
int q[MAXN];

int cnt;

bool find(int x,int idx)
{
	if(g[idx].size()==0)	return false;
	int l=0,r=g[idx].size()-1;
	while(l<=r)
	{
		int md=l+r>>1;
		if(g[idx][md]==x)	return true;
		if(g[idx][md]>x)	r=md-1;
		else	l=md+1;
	}
	return false;
}

void bfs(int s)
{
	int h,t,i;
	h=0,t=1;
	q[h]=s;
	cnt--;
	while(h<t)
	{
		int u=q[h++];
		Ans[m].push_back(u);
		for(i=0;cnt && i<cnt;)
		{
			if(!find(sck[i],u))
			{
				q[t++]=sck[i];
				swap(sck[i],sck[cnt-1]);
				cnt--;
				if(cnt==0)	break;
			}
			else i++;
		}
	}
	m++;
}
void solved()
{
	int i,j;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		sck[cnt++]=i;
	}
	m=0;
	while(cnt>0)
	{
		bfs(sck[cnt-1]);
	}
	printf("%d\n",m);
	for(i=0;i<m;i++)
	{
		printf("%d ",Ans[i].size());
		for(j=0;j<Ans[i].size();j++)
			printf("%d%c",Ans[i][j],j==Ans[i].size()-1?'\n':' ');
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,j;
		for(i=0;i<=n;i++)
		{
			g[i].clear();
			Ans[i].clear();
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(i=0;i<=n;i++)
			sort(g[i].begin(),g[i].end());
		solved();
	}
	return 0;
}

/*lktkltptlrsbdbljldahahlrqdotpmgsofbrqqrifpbijmsaik*/