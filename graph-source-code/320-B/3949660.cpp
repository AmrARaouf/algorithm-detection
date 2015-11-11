//Language: GNU C++


/*	Karan Dhamele	    */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;

/* General Declarations */

#define INF		1000000007
#define LL		long long int
#define SI(n)		cin >> n;
#define SC(c)		scanf("%c",&c);
#define SS(s)		scanf("%s",s);
#define FOR(x,a,b)	for(LL x=a;x<b;x++)
#define REP(i,n)	for(LL i=0;i<n;i++)
#define MP		make_pair
#define PB		push_back


/* Container's */

#define	VI		vector<LL>
#define PLL             pair<LL,LL>  /* A Single Pair  */
#define VP		vector<PLL> /* Vector of Pairs */
#define VS		vector<string>
#define VVI		vector<VI>
#define VVS		vector<VS>
VP inter;
VI graph[101];
LL visited[101];
LL parent[101];
LL ans=0;
LL dest;
void dfs(LL x)
{
	visited[x]=1;
	if(x==dest)
	{
		ans=1;
		//cout << "came here\n";
		return	;
	}
	LL s=graph[x].size();
	REP(i,s)
	{
		if(visited[graph[x][i]] != 1)
		{
			parent[graph[x][i]]=x;
			dfs(graph[x][i]);
			parent[graph[x][i]]=-1;
			if(ans==1)
				return;
		}
	}
	return ;
}
int main()
{
	LL n;
	SI(n);
	LL cn=0;
	while(n--)
	{
		LL a,b,c;
		
		SI(a);
		if(a==1)
		{
			SI(b);
			SI(c);
			LL s=inter.size();
			REP(i,s)
			{
				if((inter[i].first < b && b < inter[i].second )||( inter[i].first < c && c < inter[i].second))
				{
							graph[cn].PB(i);
							}

							if((inter[i].second < c && b < inter[i].second) || (inter[i].first < c && b < inter[i].first))
							{	graph[i].PB(cn);
				}
			}
			inter.PB(MP(b,c));	
			cn++;
		}
		else if(a==2)
		{
			SI(b);
			SI(c);
			dest = c-1;
			REP(i,inter.size())
			{
				parent[i]=-1;
				visited[i]=0;
				//REP(j,graph[i].size())
				//	cout << graph[i][j] << " ";
				//cout << "\n";
			}
			dfs(b-1);
			if(ans==1)
				cout << "YES\n";
			else
				cout << "NO\n";
			ans=0;
		}
	}
	return 0;
}
