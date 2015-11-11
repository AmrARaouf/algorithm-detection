//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<cmath>
#include<math.h>
#include<set>
#include<map>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define cint const int
#define ll long long
#define fname "a"
using namespace std;
const int maxn = (int)(1e5) + 123;
const ll inf = (ll)(1e18);
const int INF = (int)(1e9);
int n, m, used[maxn], start;
int main()
{
	//freopen(fname".in", "r", stdin);
	//freopen(fname".out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		used[a] = used[b] = 1;
	}
	for(int i = 1; i <= n; ++i)
		if(!used[i])
		{
			start = i;
			break;
		}
	cout << n - 1 << endl;
	for(int i = 1; i <= n; ++i)
	{
		if(i != start)
			cout << start << " " << i << endl;
	}
	return 0;
}
