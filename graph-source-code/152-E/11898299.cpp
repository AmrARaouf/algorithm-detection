//Language: GNU C++11


#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define F cin
#define G cout

const int N = 210; 
const int lim = 20;

int n,m;

int dist[N][N],cost[N][N];
int k,x[N],y[N];
int dp[N][110][110]; // dp[mark][vertex]

struct from {
	int mask1,mask2;
	int xv,yv;
};

struct from2 {
	int xv,yv;
};

#define _dist(x,y,z,k)  dist[(x-1)*m+y][(z-1)*m+k]
#define _on(x,y,z,k)  on[(x-1)*m+y][(z-1)*m+k]

from trk[N][110][110];
from2 on[N][N];

char a[N][N];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void color(int x,int y,int x2,int y2)
{
	//cerr<<x2<<' '<<y2<<'\n';
	a[x2][y2] = 'X';
	if ( x == 0 || y == 0 || x2 == 0 || y2 == 0 ) return; 
	if ( x != x2 || y != y2 )
		color(x,y,_on(x,y,x2,y2).xv,_on(x,y,x2,y2).yv);
}

void track(int mk,int x,int y)
{	
	//cerr<<mk<<' '<<x<<' '<<y<<' '<<trk[mk][x][y].mask1<<' '<<trk[mk][x][y].xv<<' '<<trk[mk][x][y].yv<<'\n';
	if ( mk == 0 ) return; 
	color(x,y,trk[mk][x][y].xv,trk[mk][x][y].yv);
	track(trk[mk][x][y].mask1,trk[mk][x][y].xv,trk[mk][x][y].yv);
	track(trk[mk][x][y].mask2,trk[mk][x][y].xv,trk[mk][x][y].yv);
}

void bellman(int x,int y)
{
	queue< pair<int,int> > q;
	_dist(x,y,x,y) = cost[x][y];
	q.push( make_pair(x,y) );
	//int its = 0;
	while ( !q.empty() )
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		//if ( ++its < 10 ) cerr<<xx<<' '<<yy<<'\n';
		
		for (int d=0;d<4;++d)
		{
			int xn = xx+dx[d];
			int yn = yy+dy[d];
			
			if ( xn < 1 || yn < 1 || xn > n || yn > m ) continue;
			
			if ( !_dist(x,y,xn,yn) || _dist(x,y,xn,yn) > _dist(x,y,xx,yy) + cost[xn][yn] )
			{
				_dist(x,y,xn,yn) = _dist(x,y,xx,yy) + cost[xn][yn];
				_on(x,y,xn,yn).xv = xx;
				_on(x,y,xn,yn).yv = yy;
				q.push( make_pair(xn,yn) );
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		ifstream F("p.in");
	#endif

	F>>n>>m>>k;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			F>>cost[i][j];
	for (int i=1;i<=k;++i)
		F>>x[i]>>y[i];
		
	//cerr<<"here\n";

	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			a[i][j] = '.';
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			bellman(i,j);
	//cerr<<_dist[1][2][3][3]<<'\n';
	
	for (int i=1;i<=k;++i)
	{
		dp[1<<(i-1)][x[i]][y[i]] = cost[x[i]][y[i]];
		trk[1<<(i-1)][x[i]][y[i]].mask1 = trk[1<<(i-1)][x[i]][y[i]].mask2 = 0;
		trk[1<<(i-1)][x[i]][y[i]].xv = trk[1<<(i-1)][x[i]][y[i]].yv = 0;
		a[x[i]][y[i]] = 'X';
	}
	for (int mask=1;mask<(1<<k);++mask)
		for (int xx=1;xx<=n;++xx)
			for (int yy=1;yy<=m;++yy)
			{
				for (int xv=1;xv<=n;++xv)
					for (int yv=1;yv<=m;++yv)
						if ( dp[mask][xv][yv] )
						{
							int ct = dp[mask][xv][yv] + _dist(xv,yv,xx,yy) - cost[xv][yv];
							if ( !dp[mask][xx][yy] || dp[mask][xx][yy] > ct )
							{
								dp[mask][xx][yy] = ct;
								trk[mask][xx][yy].xv = xv;
								trk[mask][xx][yy].yv = yv;
								trk[mask][xx][yy].mask1 = mask;
								trk[mask][xx][yy].mask2 = 0;
							}
						}
				for (int mask2=1;mask2<mask;++mask2)
					if ( (mask2 & mask) == mask2 )
						for (int xv=1;xv<=n;++xv)
							for (int yv=1;yv<=m;++yv)
								if ( dp[mask2][xv][yv] && dp[mask^mask2][xv][yv] )
								{
									//cerr<<xv<<' '<<yv<<'\n';
									int ct = dp[mask2][xv][yv] + dp[mask^mask2][xv][yv] - 2*cost[xv][yv] + _dist(xv,yv,xx,yy);
									if ( !dp[mask][xx][yy] || dp[mask][xx][yy] > ct )
									{
										dp[mask][xx][yy] = ct;
										trk[mask][xx][yy].xv = xv;
										trk[mask][xx][yy].yv = yv;
										trk[mask][xx][yy].mask1 = mask2;
										trk[mask][xx][yy].mask2 = mask^mask2;
									}
								}
			}
	//G<<dp[3][3][3]<<'\n';
	G<<dp[(1<<k)-1][x[1]][y[1]]<<'\n';
	
	//cerr<<"here\n";
	track((1<<k)-1,x[1],y[1]);
	for (int i=1;i<=n;++i)
		G<<(a[i]+1)<<'\n';
}
