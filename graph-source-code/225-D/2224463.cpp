//Language: GNU C++


﻿#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned
char a[20][20];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int go[(1<<16)+10][4];
short was[16][16][(1<<16)+10];
int p[226*((1<<16)+3)][3];
inline int makemask(vector<pnt > now)
{
		int nmask=0;
		for (int i=(now.size()-2); i>=0; --i)
		{
			FOR(c,0,4)
				if ((now[i+1].first-now[i].first==dx[c]) && (now[i+1].second-now[i].second==dy[c]))
				{
					nmask*=4;
					nmask+=c;
				}
		}
		return nmask;
}
int main()
{
#ifdef Fcdkbear
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double beg=clock();
#endif

	int maxnum=-1;
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,0,n)
		scanf("%s",&a[i]);
	FOR(i,0,n)
		FOR(j,0,m)
			if ((a[i][j]>='0') && (a[i][j]<='9'))
				maxnum=MAX(maxnum,a[i][j]-'0');
	FOR(mask,0,(1<<(maxnum+maxnum-2)))
	{
		vector<pnt > old,now;
		old.push_back(mp(0,0));
		FOR(i,0,maxnum-1)
		{
			int v=2*i;
			int now=((mask>>v)&1)+((mask>>(v+1))&1)*2;
			int x=old.back().first;
			int y=old.back().second;
			old.push_back(mp(x+dx[now],y+dy[now]));
		}
		FOR(k,0,4)
		{
			now.clear();
			now.push_back(mp(dx[k],dy[k]));
			FOR(i,0,old.size()-1)
				now.push_back(old[i]);
			bool f=true;
			FOR(i,1,now.size())
				if (now[i]==now[0])
					f=false;
			if (!f)
				go[mask][k]=-1;
			else
				go[mask][k]=makemask(now);
		}
	}
	vector<pnt> now;
	now.resize(maxnum);
	FOR(i,0,n)
		FOR(j,0,m)
			if ((a[i][j]>='0') && (a[i][j]<='9'))
				now[a[i][j]-'0'-1]=mp(i,j);
	
	
	int bmask=makemask(now);
	int x=now[0].first;
	int y=now[0].second;
	MEMS(was,-1);
	was[x][y][bmask]=0;
	p[0][0]=x;
	p[0][1]=y;
	p[0][2]=bmask;
	int l=0,r=0;
	while (l<=r)
	{
		int x=p[l][0];
		int y=p[l][1];
		int mask=p[l][2];
		if (a[x][y]=='@')
		{
			cout<<was[x][y][mask]<<endl;
			return 0;
		}
		FOR(k,0,4)
		{
			int nx=x+dx[k];
			int ny=y+dy[k];
			int nmask=go[mask][k];
			if (nmask==-1)
				continue;
			if ((nx>=0) && (nx<n) && (ny>=0) && (ny<m) && (a[nx][ny]!='#') && (was[nx][ny][nmask]==-1))
			{
				was[nx][ny][nmask]=was[x][y][mask]+1;
				r++;
				p[r][0]=nx;
				p[r][1]=ny;
				p[r][2]=nmask;
			}
		}
		l++;
	}
	cout<<-1<<endl;
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
	return 0;
}