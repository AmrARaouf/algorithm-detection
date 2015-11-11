//Language: GNU C++


#include <cstdio>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000000
#define orta ((a+b)/2)
#define Size(a) ((int)a.size())
typedef long long int lint;
typedef pair<int,int> ii;
int n,m,mark[N],dp[N];
vector <ii> yol[N];
vector <int>  prt;
priority_queue <ii> q;
int fon(int k)
{
	if(k==n) return 0;
	if(dp[k]!=-1) return dp[k];
	int mx=-inf;
	for (int i = 0; i < (int)yol[k].size(); i++)
		if(mark[k]+1==mark[yol[k][i].fi])
		{
			mx=max(mx,yol[k][i].sc+fon(yol[k][i].fi));	
		}
	return dp[k]=mx;
}
void yaz(int k)
{
	prt.pb(k);
	if(k==n) return ;
	for (int i = 0; i < (int)yol[k].size(); i++)
		if(mark[k]+1==mark[yol[k][i].fi] && dp[k]==yol[k][i].sc+fon(yol[k][i].fi))
		{
			yaz(yol[k][i].fi);
			return ;
		}	
}
map <ii,int> mp;
int main()
{
	int say=0;
	memset(mark,-1,sizeof(mark));
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++)
	{
		int o1,o2,o3;
		scanf("%d %d %d",&o1,&o2,&o3);
		yol[o1].pb(MP(o2,o3));
		yol[o2].pb(MP(o1,o3));
		if(o3) say++;
		if(o3)
		{
			mp[MP(o1,o2)]=1;
			mp[MP(o2,o1)]=1;		
		}
	}
	q.push(MP(0,1));
	while(!q.empty())
	{
		ii tmp=q.top();
		q.pop();
		if(mark[tmp.sc]!=-1) continue;
		mark[tmp.sc]=-tmp.fi;
		for (int i = 0; i < (int)yol[tmp.sc].size(); i++)
		if(mark[yol[tmp.sc][i].fi]==-1)
		{
			ii yeni=MP(tmp.fi-1,yol[tmp.sc][i].fi);
			q.push(yeni);
		}
	}
	cout <<say-2*fon(1)+mark[n]<<endl;
	yaz(1);
	int yy[N][3],cevs=0;
	for (int i = 0; i <(int) prt.size()-1; i++)
	{
		if(mp[MP(prt[i],prt[i+1])])
		{
			mp[MP(prt[i],prt[i+1])]=0;
			mp[MP(prt[i+1],prt[i])]=0;
		}
		else
		{
			yy[cevs][0]=prt[i];
			yy[cevs][1]=prt[i+1];
			yy[cevs][2]=1;
			cevs++;
		}
	}
  std::map<ii,int>::iterator it = mp.begin();
	for (it=mp.begin(); it!=mp.end(); ++it)
		if(it->sc && (it->first).fi > (it->first).sc)
		{

			yy[cevs][0]=it->first.fi;
			yy[cevs][1]=it->first.sc;
			yy[cevs][2]=0;
			cevs++;
		}
	for (int i = 0; i < cevs; i++)
	{
		printf("%d %d %d\n",yy[i][0],yy[i][1],yy[i][2]);
	}
	
}









