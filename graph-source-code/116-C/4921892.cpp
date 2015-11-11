//Language: MS C++


#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <complex>

using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXN = 1e6 + 5;
const double EPS = 1e-7;
const int INF = 1000000000 + 5;
const int MAXN2 = 3000 + 5;

vi g[MAXN2];
bool visited[MAXN2][MAXN2];
bool is_root[MAXN];

int mx = 0;
int st = 0;

void dfs(int v,int d = 1)
{
	mx = max(mx,d);
	visited[st][v] = true;
	int sz = g[v].size();
	for(int i=0;i<sz;i++)
	{
		int to = g[v][i];
		if(!visited[st][to])
		{
			dfs(to,d+1);
		}
	}
}

int main()
{
	//freopen(file".in","r",stdin); freopen(file".out","w",stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif		
	int n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a != -1)
		{
			g[a].pb(i);
		}
		else
		{
			is_root[i] = true;
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(is_root[i])
		{
			dfs(i);
			st++;
		}
	}

	cout<<mx;
	return 0;
}