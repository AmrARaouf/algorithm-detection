//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#define SET(p)	 		memset(p,-1,sizeof(p))
#define CLR(p) 			memset(p,0,sizeof(p))
#define LL 				long long int
#define ULL		 		unsigned long long int
#define S(n)			scanf("%d",&n)
#define Sl(n)			scanf("%lld",&n)
#define Sf(n)			scanf("%lf",&n)
#define Ss(n)			scanf("%s",n)
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define FOR(i,a,b)		for(int i=a;i<b;i++)
#define REP(i,n)		FOR(i,0,n)
using namespace std;
vector<int> adj[100009];
vector<int> col[100009];
int main()
{
	int t,i,j,k,n,m;
	#ifndef ONLINE_JUDGE
	freopen("example.txt","r",stdin);
	#endif
	S(n);S(k);
	vector<int> v;
	for(i=0;i<n;i++)
	{
		int x;
		S(x);
		v.push_back(x);
		col[x].push_back(i+1);
	}
	for(i=0;i<k;i++)
	{
		int a,b;
		S(a);S(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans=0;
	int ancol=0;
	for(i=0;i<=100000;i++)
	{
		if(col[i].size()==0)
			continue;
		set<int> st;
		//cout<<i<<"_-__  "<<endl;
		st.insert(i);
		for(j=0;j<col[i].size();j++)
		{
			t=col[i][j];
			for(k=0;k<adj[t].size();k++)
			{
				st.insert(v[adj[t][k]-1]);
				//cout<<v[adj[t][k]-1]<<" ";
			}
		}
		//cout<<endl;
		//cout<<i<<" "<<st.size()<<endl;
		if(ans<st.size())
		{
			ans=st.size();
			ancol=i;
			//cout<<ans<<" "<<ancol<<endl;
		}
	}
	cout<<ancol<<endl;
	return 0;
}
