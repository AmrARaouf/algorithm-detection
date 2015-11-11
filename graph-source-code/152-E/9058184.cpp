//Language: GNU C++0x


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define dep(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;

const int nn=110;
int N,M,K;
int a[nn][nn],f[nn][nn][130],v[nn][nn][130],can[nn][nn];
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

struct state
{
	int x,y,z;
	state(){}
	state(int a,int b,int c):x(a),y(b),z(c){}
} p1[nn][nn][130],p2[nn][nn][130];
queue<state> Q;

void add(int x,int y,int z,int t,int a1,int b1,int c1,int a2,int b2,int c2)
{
	v[x][y][z]=1;
	p1[x][y][z]=state(a1,b1,c1);
	p2[x][y][z]=state(a2,b2,c2);
	f[x][y][z]=t;
	Q.push(state(x,y,z));
}
void print(state t)
{
	if (!t.z) return;
	can[t.x][t.y]=1;
	print(p1[t.x][t.y][t.z]);
	print(p2[t.x][t.y][t.z]);
}
int main()
{
	memset(f,0x7f,sizeof(f));
	scanf("%d%d%d",&N,&M,&K);
	rep(i,1,N) rep(j,1,M) scanf("%d",&a[i][j]);
	rep(i,1,K)
	{
		int x,y;scanf("%d%d",&x,&y);
		add(x,y,1<<(i-1),a[x][y],0,0,0,0,0,0);
	}
	while (Q.size())
	{
		state t=Q.front();Q.pop();
		int x=t.x,y=t.y,z=t.z;v[x][y][z]=0;
		rep(i,0,(1<<K)-1)
		{
			if (f[x][y][i|z]>f[x][y][z]+f[x][y][i]-a[x][y])
				add(x,y,i|z,f[x][y][z]+f[x][y][i]-a[x][y],x,y,i,x,y,z);
		}
		rep(k,0,3)
		{
			int x1=x+dx[k],y1=y+dy[k];
			if (x1<1||y1<1||x1>N||y1>M) continue;
			if (f[x1][y1][z]>f[x][y][z]+a[x1][y1])
				add(x1,y1,z,f[x][y][z]+a[x1][y1],0,0,0,x,y,z);
		}
	}
	int ans=1<<30,bx,by;
	rep(i,1,N) rep(j,1,M)
	{
		if (ans>f[i][j][(1<<K)-1]) ans=f[i][j][(1<<K)-1],bx=i,by=j;
	}
	printf("%d\n",ans);
	print(state(bx,by,(1<<K)-1));
	rep(i,1,N)
	{
		rep(j,1,M) putchar(can[i][j]?'X':'.');
		puts("");
	}
	return 0;
}

