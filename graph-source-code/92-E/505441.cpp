//Language: GNU C++


#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define AUTO(it, expr) __typeof__(expr) it = (expr)
#define FOR(it, c) for (AUTO(it, (c).begin()); (it) != (c).end(); ++(it))

typedef pair<int, int> edge; // no dest
typedef vector<edge> vertex;
typedef vector<vertex> graph;

struct mfset {
    vector<int> v;
    mfset(int n) : v(n, -1) {}
    int find(int x) {
	return v[x] < 0 ? x : (v[x] = find(v[x]));
    }
    bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
	    if (-v[x] < -v[y])
		swap(x, y);
	    v[x] += v[y];
	    v[y] = x;
	    return true;
	}
	return false;   
    }
    int size(int x) {
	return -v[find(x)];
    }
};

const int MOD = 1000000009;

template<typename T>
void debug(const vector<T>& v) { // for old debuggers
    FOR (it, v)
	fprintf(stderr, "%d ", *it);
    puts("");
}

int main() {
    int n, m, count = 1;
    cin >> n >> m;
    mfset mfs(n);
    REP (i, m) {
	int u, v;
	cin >> u >> v;
	--u, --v;
	if (!mfs.merge(u, v))
	    count = count*2 % MOD;
	cout << (count ? count-1 : MOD-1) << endl;
    }
}
