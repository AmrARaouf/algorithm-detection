//Language: GNU C++0x


//why are you stalking me?
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <deque>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <complex>
#include <iomanip>
//#define NDEBUG 1
#include <cassert>

using namespace std;

#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 100010;

struct edge {
	int u, v, id;
	edge (int _u, int _v, int _id) {
		u = _u;
		v = _v;
		id = _id;
	}
};

void kill (bool b) {
	if (b) {
		cout << -1;
		exit(0);
	}
}

int N, M;
vector<edge> vs, vm;
int par[MAXN];

void reset() {
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
}

int find (int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge (int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	par[x] = y;
	return true;
}

int main() {
	//why are you stalking me?
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	kill(N % 2 == 0);
	int half = N / 2;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		if ((cin.get(), cin.get()) == 'S') {
			vs.push_back(edge(a, b, i));
		} else {
			vm.push_back(edge(a, b, i));
		}
	}
	reset();
	int comp = N;
	for (edge e : vm) {
		comp -= merge(e.u, e.v);
	}
	kill(comp > half + 1);
	vector<edge> s;
	for (edge e : vs) {
		if (merge(e.u, e.v)) {
			s.push_back(e);
		}
	}
	reset();
	for (edge e : s) {
		merge(e.u, e.v);
	}
	for (edge e : vs) {
		if (s.size() == half) {
			//put more "s" edges until there are exactly "half" S's
			break;
		}
		if (merge(e.u, e.v)) {
			s.push_back(e);
		}
	}
	kill(s.size() != half);
	cout << N - 1 << endl;
	for (edge e : s) {
		cout << e.id << ' ';
	}
	for (edge e : vm) {
		//can't directly print out other vector's contents :(
		//but still there are more than enough.
		if (merge(e.u, e.v)) {
			cout << e.id << ' ';
		}
	}
}