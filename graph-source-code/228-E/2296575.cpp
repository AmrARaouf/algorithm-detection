//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>


#define MAXN 120
#define pb push_back
#define mk make_pair
#define F first
#define S second

using namespace std;

int to, w, ans;
int col[MAXN];
vector < pair <int, int> > a[MAXN];
int x, y, z, n, m;
int dfs(int v)
{
 	
	//cerr << 1 << endl;

	for (int i = 0; i < a[v].size(); i++)
	{
	 	   to = a[v][i].F;
	 	   w = a[v][i].S;
	 	   if (w) x = col[v]; else x = 3 - col[v];
                   if (col[to] == 0)
                   {
                    	col[to] = x;
                    	dfs(to);
                   }
                   else
                   if (col[to] != x)
                   {
                    	cout <<"Impossible";
                    	exit(0);
                   }
	}
}
int main(){

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= m; i++)	
	{                                                            
		cin >> x >> y >> z;
		a[x].pb(mk(y, z));
		a[y].pb(mk(x, z));
	}

	for (int i = 1; i <= n; i++)
	if (col[i] == 0)
	{
	 	col[i] = 1;
	 	dfs(i);
	}
	int ans = 0;

	for (int i = 1; i <= n; i++)
	if (col[i] == 1)
	ans++;

	cout << ans << endl;

	for (int i = 1; i <= n; i++)
	if (col[i] == 1)

		cout << i << " ";

	return 0;
}
