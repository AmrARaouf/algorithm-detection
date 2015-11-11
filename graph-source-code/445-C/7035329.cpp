//Language: GNU C++


#pragma comment(linker, "/STACK:64777216")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<memory.h>
#include<ctime>
#include<cassert>

#define pb push_back
#define sz(a) (int)a.size()
#define bs binary_search
#define np next_permutation
#define mp make_pair
#define all(a) a.begin(),a.end()
#define read(a) scanf("%d", &a)
#define writeln(a) printf("%d\n", a);
#define forn(i, n) for (int i = 0; i < n; ++i)
#define forv(i, v) for (int i = 0; i < sz(v); ++i)
#define _(a, b) memset(a, b, sizeof a)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<class T> inline T sqr(T x) { return x * x; }

const double pi = acos(-1.0), eps = 1e-18;
const int INF = 1000 * 1000 * 1000, MAXN = 100005, MOD = INF + 7;

int n, m, a, b, cost, x[505];

void prepare(string s) {
#ifdef _DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt","w",stdout);
#else
   if (sz(s) != 0) {
       freopen((s + ".in").c_str(), "r", stdin);
       freopen((s + ".out").c_str(), "w", stdout);
   }
#endif
}

void solve()
{
    cin >> n >> m;
	forn (i, n) cin >> x[i];
	double MAX = 0;
	forn (i, m) {
		cin >> a >> b >> cost;
		double pl = (double)(x[a-1] + x[b-1]) / (double)cost;
		MAX = max(MAX, pl);
	}
	printf("%.12f", MAX);
}

int main()
{
   prepare("");

   solve();

   return 0;
}