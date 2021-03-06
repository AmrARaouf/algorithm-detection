//Language: GNU C++


#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <sstream>

const int N=501;
const int inf=0x3f3f3f3f;

using namespace std;

#define sz(x) ((x).size())
#define pb push_back

vector<int> vt[N];

struct data
{
	int a,b,s;
	data() {}
	data(int a,int b,int s) :a(a),b(b),s(s) {}
};

int n,m;

int dis[N][N][2];

int bfs(int a,int b)
{
	memset(dis,0x3f,sizeof(dis));
	queue<data> que;
	que.push(data(a,b,0));
	dis[a][b][0]=0;
	while(sz(que))
	{
		data u=que.front();
		que.pop();
		if(u.s==0 && u.a==u.b)
		{
			dis[u.a][u.b][u.s]=inf;
			continue;
		}
		if(u.s)
		{
			for(int i=0;i<sz(vt[u.b]);i++)
			{
				int x=u.a,y=vt[u.b][i];
				if(dis[x][y][0]!=inf) continue;
				dis[x][y][0]=dis[u.a][u.b][1]+1;
				que.push(data(x,y,0));
			}
		}
		else
		{
			for(int i=0;i<sz(vt[u.a]);i++)
			{
				int x=vt[u.a][i],y=u.b;
				if(dis[x][y][1]!=inf) continue;
				dis[x][y][1]=dis[u.a][u.b][0];
				que.push(data(x,y,1));
			}
		}
	}
}

vector<int> r1,r2;

void display(int a,int b)
{
	//printf("%d -> %d = %d\n",a,b,dfs(a,b,0));
	r1.pb(a),r2.pb(b);
	if(a==n && b==1) return ;
	int ret=dis[a][b][0];
	for(int i=0;i<sz(vt[a]);i++)
		for(int j=0;j<sz(vt[b]);j++)
		{
			int x=vt[a][i],y=vt[b][j];
			if(x==y) continue;
			if(ret==dis[x][y][0]+1)
			{
				display(x,y);
				return ;
			}
		}
	return ;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		vt[a].pb(b);
		vt[b].pb(a);
	}
	bfs(n,1);
	if(dis[1][n][0]==inf) return puts("-1"),0;
	display(1,n);
	printf("%d\n",dis[1][n][0]);
	for(int i=0;i<sz(r1);i++)
		printf("%d ",r1[i]);puts("");
	for(int i=0;i<sz(r2);i++)
		printf("%d ",r2[i]);puts("");
	return 0;
}
