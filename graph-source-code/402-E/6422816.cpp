//Language: GNU C++


#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

#define MAXN 2000

int G[MAXN][MAXN];

int n;
int vis[MAXN];
int sgn[MAXN];
stack<int> vs;
void dfs(int u)
{
	vis[u] = 1;
	REP(v,n) if(G[u][v] && !vis[v])
	{
		dfs(v);
	}
	vs.push(u);
}

void rdfs(int u, int k)
{
	vis[u] = 0;
	sgn[u] = k;
	REP(v,n) if(G[v][u] && vis[v])
	{
		rdfs(v, k);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		REP(i,n)
		REP(j,n)
			cin>>G[i][j];
		memset(vis,0,sizeof(vis));
		REP(i,n)
		{
			if(!vis[i])
				dfs(i);
		}
		int k = 0;
		while(!vs.empty())
		{
			int u = vs.top();
			vs.pop();
			if(vis[u]) rdfs(u, k++);
		}
		if(k==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

	   		  		 				  			   			