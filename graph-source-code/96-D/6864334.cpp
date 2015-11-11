//Language: MS C++


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <hash_set>
#include <hash_map>
#include <algorithm>

//define NDEBUG
#include <cassert>

#define FILE_READER assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
#define FAST_READER ios::sync_with_stdio(false); cin.tie(nullptr);
#define all_(v) (v).begin(), (v).end()
#define for_(i, a, b) for (int i = (a); i < (int)(b); i++)
#define ford_(i, a, b) for (int i = (a); i > (int)(b); i--)
#define foreach_(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define sz_(v) ((int)(v).size())
#define mp_ make_pair
#define pb_ push_back
typedef long long LL_;
typedef long double LD_;
template<class T> T sqr_(T a) {return a * a;}
template<class T> T abs_(T a) {return a > 0 ? a : -a;}
template<class T> T sgn_(T a) {return a > 0 ? 1 : (a < 0 ? -1 : 0);}

using namespace std;

const int maxn = (int)1e3 + 11;
int mat[maxn][maxn] = {0};
vector<pair<int, int> > v[maxn];
vector<pair<int, int> > g[maxn];
set<pair<int, int> > st;
vector<int> d(maxn);
const int inf = (int)1e9 + 11; //1e12 + 1
vector<int> used(maxn);
vector<int> t(maxn), c(maxn);
set<pair<long long, int> > set_;
vector<long long> dst(maxn);

int main() {

#ifndef ONLINE_JUDGE 
	FILE_READER 
#endif 	
	
	FAST_READER;

	int n, m;
	cin >> n >> m;
	int from, to;
	cin >> from >> to;
	for_(ss, 0, m) {
		int i, j, w;
		cin >> i >> j >> w;
		--i, --j;
		if (mat[i][j] == 0) 
			mat[i][j] = mat[j][i] = w;
		else
			if (w < mat[i][j])
				mat[i][j] = mat[j][i] = w; 
	}
	for_(i, 0, n) {
		for_(j, i + 1, n) {
			if (mat[i][j] != 0) {
				v[i].pb_(mp_(j, mat[i][j]));
				v[j].pb_(mp_(i, mat[i][j]));
			}
		}
	}
	for_(i, 0, n) cin >> t[i] >> c[i];
	for_(i, 0, n) {
		st.clear();
		for_(j, 0, n) d[j] = inf, used[j] = false;
		d[i] = 0;
		st.insert(mp_(0, i));
		pair<int, int> node;
		while (!st.empty()) {
			node = *st.begin();
			st.erase(st.begin());
			int dist = node.first;
			if (dist > t[i]) break;
			int vert = node.second;
			used[vert] = true;
			if (vert != i) g[i].pb_(mp_(vert, c[i]));
			int sz = sz_(v[vert]);
			for_(j, 0, sz) {
				int to = v[vert][j].first;
				if (used[to]) continue;
				int len = v[vert][j].second;
				if (dist + len >= d[to]) continue;
				st.erase(mp_(d[to], to));
				d[to] = dist + len;
				st.insert(mp_(d[to], to));
			}
		}
	}

	long long big = (long long)1e15;
	for_(i, 0, n) dst[i] = big, used[i] = false;
	--from, --to;
	dst[from] = 0;
	set_.insert(mp_(0, from));
	while(!set_.empty()) {
		pair<long long, int> node = *set_.begin();
		set_.erase(set_.begin());
		int vert = node.second;
		long long dist = node.first;
		if (vert == to) {
			cout << dist;
			return 0;
		}
		used[vert] = true;
		int sz = sz_(g[vert]);
		for_(i, 0, sz) {
			int to = g[vert][i].first;
			int len = g[vert][i].second;
			if (used[to])continue;
			if (dist + len >= dst[to]) continue;
			set_.erase(mp_(dst[to], to));
			dst[to] = dist + len;
			set_.insert(mp_(dst[to], to));
		}
	}
	cout << -1;
	return 0;
}