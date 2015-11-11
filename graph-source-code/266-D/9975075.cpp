//Language: GNU C++0x


/*
user  : triveni
date  : 24/02/2015
time  : 03:31:47
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      pb(a)             std::push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

typedef long long LL;
LL MOD = 1000000007;

int d[201][201];
pair<pair<int,int>, int> E[20000];
vector<pii> Intervals;
int n, m;

bool check(int idx, int x){
	int u = E[idx].X.X, v = E[idx].X.Y, w = E[idx].Y;
	Intervals.clear();
	for(int i = 0; i < n; ++i){
		int d1 = d[u][i], d2 = d[v][i];
		if(d1 > x and d2 > x) return 0;
		int a = 0, b = w;
		a = min(w, x - d1) + 1;
		b = max(0, w - (x - d2)) - 1;
		if(d1 <= x and d2 <= x){
			if(a > b) continue;
			else Intervals.push_back(mp(a, b));
		}
		else if(d1 <= x){
			if(a <= w) Intervals.push_back(mp(a, w));
		}
		else{
			if(b >= 0) Intervals.push_back(mp(0, b));
		}
	}
	if(Intervals.size() < 1) return 1;
	sort(Intervals.begin(), Intervals.end());
	if(Intervals[0].X > 0) return 1;
	int maxY = Intervals[0].Y;
	for(int i = 1; i < Intervals.size(); ++i){
		if(Intervals[i].X > maxY) return 1;
		maxY = max(maxY, Intervals[i].Y);
	}
	return maxY < w;
}

int solve(int idx){
	int u = E[idx].X.X, v = E[idx].X.Y;
	int l = 0, r = 0, m;
	for(int i = 0; i < n; ++i){
		r = max(r, min(d[u][i], d[v][i]));
	}
	r += E[idx].Y + 10;
	while(r - l > 1){
		m = (l + r) >> 1;
		bool f = check(idx, m);
		if(f) r = m;
		else l = m;
	}
	if(check(idx, l)) return l;
	else return r;
}

int main()
{
	int u, v, w;
	scanf("%d %d",&n,&m);
	rep(i, n) rep(j, n) d[i][j] = (i == j ? 0 : MOD);
	rep(i, m){
		scanf("%d %d %d",&u, &v, &w);
		u -= 1, v -= 1, w <<= 1;
		d[u][v] = d[v][u] = w;
		E[i] = mp(mp(u, v), w);
	}
	// Floyd Warshal Algorithm for all pair shortest path
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k){
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
	}
	int ans = MOD;
	rep(i, m) ans = min(ans, solve(i));
	cout << ans / 2.0 << endl;
	return 0;
}
