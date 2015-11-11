//Language: GNU C++


//----------------------JUGNU:LET YOUR LIGHT SHINE---------------------------//
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define sz size
#define mk make_pair
#define ln length
#define vt(a) vector <ll> a
#define st(a) set <ll> a
#define sti(a) set <ll>::iterator a
#define fr(i,a,b) for(i=a;i<b;i++)
#define fre(i,a,b) for(i=a;i<=b;i++)
#define frr(i,a,b) for(i=a;i>=b;i--)
#define cn(a) cin >> a
#define cm(a, b) cin >> a >> b
#define ct(a) cout << a << endl
#define ctm(a, b) cout << a << " " << b << endl
#define isset(x,i) ((x>>i)&1)
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
vector<int> graph[1005];
int dp[1005][1005];
int num[6][1005];
int visited[1005], level[1005];
void dfs(int node)
{
	int i;
	fr(i, 0, graph[node].sz())
	{
		if(visited[graph[node][i]]==0)
		{
			visited[graph[node][i]] = 1;
			dfs(graph[node][i]);
		}
		level[node] = max(level[node], level[graph[node][i]] + 1);
	}
}
int main()
{
	fastScan
	int i, j, t, n, m, k, l, r, temp, result, mini, maxi, flag;
	cm(n, k);
	fr(i, 0, k)
		fr(j, 0, n)
			cn(num[i][j]);
	fr(i, 0, k)
		fr(j, 0, n)
			fr(l, 0, j)
					dp[num[i][j]][num[i][l]]++;
	fre(i, 1, n)
		fre(j, 1, n)
			if(dp[i][j]==k)
				graph[i].pb(j);
	result = 1;
	fre(i, 1, n)
	{
		if(visited[i]==0)
		{
			visited[i] = 1;
			dfs(i);
		}
	}
	fre(i, 1, n)
		result = max(result, level[i]+1);
	ct(result);
return 0;
}
