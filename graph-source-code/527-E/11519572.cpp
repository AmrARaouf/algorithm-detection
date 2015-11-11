//Language: MS C++


//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 200010;
int n, m;
vi g[nmax];
map<ii, int> mp;
vi ans;

void euler(int u){
	while (!g[u].empty()) {
		int v = g[u].back(); g[u].pop_back();
		if (mp[ii(u, v)] > 0) {
			mp[ii(u, v)]--; mp[ii(v, u)]--;
			euler(v);
		}
	}
	ans.push_back(u);
}

void solve() {
	cin>>n>>m;
	FOR(i, 0, m) {int x, y; cin>>x>>y; x--; y--; g[x].push_back(y); mp[ii(x, y)]++;  {g[y].push_back(x); mp[ii(y, x)]++;}}
	vi d;
	FOR(i, 0, n) {if (sz(g[i]) % 2 == 1) d.push_back(i);}
	if (sz(d) % 2 == 1) {int i = d.back(); d.pop_back(); g[i].push_back(i);  mp[ii(i, i)]++;}
	while (sz(d)) {int x = d.back(); d.pop_back(); int y = d.back(); d.pop_back(); g[x].push_back(y); g[y].push_back(x); mp[ii(x, y)]++; mp[ii(y, x)]++;}
	euler(0);
	if (sz(ans) % 2 == 0) ans.push_back(0);
	cout<<ans.size() - 1<<"\n";
	bool st = true;
	FOR(i, 1, sz(ans)) {
		if (st) cout<<ans[i - 1] + 1<<" "<<ans[i] + 1<<"\n"; else cout<<ans[i] + 1<<" "<<ans[i - 1] + 1<<"\n"; st = !st;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}