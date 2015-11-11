//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int n,m;
vector<int> g[100100];
int deg[100100];
int group[100100];
int color[100100];
bool used[100100];
int num[100100][3];
int k=0;
bool ok=true;
void dfs(int v,int col)
{
	group[v]=k;
	color[v]=col;
	used[v]=true;
	for(int i=0;i<g[v].size();i++)
	{
		if(!used[g[v][i]])dfs(g[v][i],-col);
		if(color[g[v][i]]==color[v])ok = false;
	}
	return;
}
ll ans = 0ll;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		deg[a]++;
		deg[b]++;
		g[a].pb(b);
		g[b].pb(a);
	}
	if(m==0)
	{
		ll x = (ll)n;
		ans = x*(x-1)*(x-2)/6;
		cout << 3 << ' ' << ans << endl;
		return 0;
	}
	bool flag = true;
	for(int i=0;i<n;i++)
	{
		if(deg[i]>1)
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		cout << 2 << ' ' << ((ll)n-2ll)*(ll)m << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			dfs(i,1);
			k++;
		}
	}
	if(!ok)
	{
		cout << 0 << ' ' << 1 << endl;
		return 0;
	}
	for(int i=0;i<n;i++)num[group[i]][color[i]+1]++;
	//for(int i=0;i<n;i++)cout << group[i] << ' ' << color[i] << endl;
	for(int i=0;i<k;i++)
	{
		if(num[i][0]>1)
		{
			ll x = num[i][0];
			ans += x*(x-1)/2ll;
		}
		if(num[i][2]>1)
		{
			ll x = num[i][2];
			ans += x*(x-1)/2ll;
		}
	}
	cout << 1 << ' ' << ans << endl;
	return 0;
}
