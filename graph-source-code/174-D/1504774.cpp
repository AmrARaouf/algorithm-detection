//Language: GNU C++


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define rep(i,n) for(int i=0;i<(n);++i)
#define REP(i,n) for(int i=1;i<=(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define print(expr) cout<<(#expr)<<" : "<<(expr)<<endl
#define tr(it,c) for(VI::iterator it=(c).begin(); it!=(c).end(); ++it)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;
typedef pair<int,int> pii;

const int maxn=100050;
int n,m;
int f[maxn];
VI buf1[maxn], buf2[maxn];
bool vis1[maxn]={}, vis2[maxn]={};
bool go[maxn]={};
VI todel;

void bfs(VI *buf, bool *vis, int xx, int t)
{
	rep(i,n) if(f[i]==xx && !vis[i])
	{
		vis[i]=true;
		queue<int> q; q.push(i);
		while(!q.empty())
		{
			int x=q.front(); q.pop();
			tr(it,buf[x]) if(!vis[*it])
			{
				if(f[*it]==t)
				{
					if(xx==2) vis[*it]=true;
				}
				else
				{
					vis[*it]=true;
					q.push(*it);
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",f+i);
	rep(i,m) { int a,b; scanf("%d%d",&a,&b); --a; --b; buf1[a].PB(b); buf2[b].PB(a);}
	bfs(buf1,vis1,1,1); bfs(buf2,vis2,2,1);
	rep(i,n) printf("%d\n",vis1[i] && vis2[i]);
	return 0;
}