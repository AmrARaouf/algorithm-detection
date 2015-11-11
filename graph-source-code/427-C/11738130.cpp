//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef long long int lld;

#define sz                           size()
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007
#define __sync__		     std::ios::sync_with_stdio(false);

#define maxn 100010

vi adj[maxn];
stack<int> ss;
int com;
vector< vi > C;
bool mark[maxn];
int Time[maxn];
int lowlink[maxn];
int t = 0;
int a[maxn];
int n;
void tarjan(int u)
{
	Time[u] = ++t;
	lowlink[u] = t;
	ss.push(u);
	mark[u] = 1;
	for(int i=0;i<(int)adj[u].sz;i++)
	{
		int v = adj[u][i];
		if(Time[v] == 0)
		{
			tarjan(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if(mark[v])
			lowlink[u] = min(lowlink[u], Time[v]);
	}
	if(lowlink[u] == Time[u])
	{
		vi tmp;
		int v = ss.top();
		ss.pop();
		tmp.pb(a[v]);
		mark[v] = 0;
		while(u!=v && !ss.empty())
		{
			v = ss.top();
			ss.pop();
			tmp.pb(a[v]);
			mark[v] = 0;
		}
		C.pb(tmp);
		com++;
	}
}


int main()
{
	fill(mark,0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int xx,yy;
		cin>>xx>>yy;
		xx--;yy--;
		adj[xx].pb(yy);
	}
	for(int i=0;i<n;i++) if(Time[i]==0) tarjan(i);
	lld ans, ways;
	ans = 0;
	ways = 1;

	for(int i=0;i<(int)C.sz;i++)
	{
		int val = (*min_element(C[i].begin(),C[i].end()));
		ways = (ways*1LL*count(C[i].begin(),C[i].end(),val))%mod;
		ans += val;
	}
	cout<<ans<<" "<<ways<<"\n";
	return 0;

}      
