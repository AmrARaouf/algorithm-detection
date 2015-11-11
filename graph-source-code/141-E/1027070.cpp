//Language: GNU C++


#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

#define FILENAME ""

int n;
int m;

vi v1, v2;
int x1[100500], x2[100500];

int root[100500];

int get(int x) {
	if (x == root[x])
		re x;
	re root[x] = get(root[x]);
}

void merge(int a, int b) {
	if (rand() & 1)
		root[get(a)] = get(b);
	else
		root[get(b)] = get(a);
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
#endif

#ifndef LOCAL_BOBER
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif

	cin >> n >> m;
	rep(i, m) {
		int x, y;
		string s;
		cin >> x >> y >> s;
		x--;
		y--;
		x1[i] = x;
		x2[i] = y;
		if (s == "S")
			v1.pb(i);
		else
			v2.pb(i);
	}

	if (n % 2 == 0) {
		cout << -1 << endl;
		re 0;
	}

	rep(i, n)
	root[i] = i;

	rep(i, sz(v1)) {
		int a = x1[v1[i]];
		int b = x2[v1[i]];
		if (get(a) != get(b))
			merge(a, b);
	}

	vi ans1, ans2;

	rep(i, sz(v2)) {
		int a = x1[v2[i]];
		int b = x2[v2[i]];
		if (get(a) != get(b)) {
			merge(a, b);
			ans2.pb(v2[i]);
		}
	}

	rep(i, n)
	if (get(0) != get(i)) {
		cout << -1 << endl;
		re 0;
	}

	rep(i, n)
	root[i] = i;

	rep(i, sz(ans2)) {
		int a = x1[ans2[i]];
		int b = x2[ans2[i]];
		if (get(a) != get(b))
			merge(a, b);
	}

	rep(i, sz(v2)) {
		if (sz(ans2) >= (n - 1) / 2)
			break;
		int a = x1[v2[i]];
		int b = x2[v2[i]];
		if (get(a) != get(b)) {
			merge(a, b);
			ans2.pb(v2[i]);
		}
	}

	if (sz(ans2) != (n - 1) / 2) {
		cout << -1 << endl;
		re 0;
	}

	rep(i, sz(v1)) {
		int a = x1[v1[i]];
		int b = x2[v1[i]];
		if (get(a) != get(b)) {
			merge(a, b);
			ans1.pb(v1[i]);
		}
	}

	cout << n - 1 << endl;
	rep(i, sz(ans1))
	cout << ans1[i] + 1 << ' ';
	rep(i, sz(ans2))
	cout << ans2[i] + 1 << ' ';
	cout << endl;


	re 0;
}
