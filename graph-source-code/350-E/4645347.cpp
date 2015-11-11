//Language: GNU C++0x


#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }

const int maxN = 1024;
int N, M, K;
int mark[maxN];

set<pii> edge;

bool has_edge(int a, int b) {
	if (a > b) swap(a, b);
	return has(edge, pii(a,b));
}

bool add_edge(int a, int b) {
	if (a > b) swap(a, b);
	if (has(edge, pii(a,b))) return false;
	edge.insert(mp(a,b));
	M--;
	return true;
}

int main() {
	cin >> N >> M >> K;
	FOR(i,1,K+1) {
		int tmp; cin >> tmp;
		mark[tmp] = 1;
	}

	int A = 0, B = 0, U = 0;
	FOR(i,1,N+1) {
		if (mark[i]) {
			if (!A) A = i;
			else if (!B) B = i;
		} else {
			if (!U) U = i;
		}
		if (U && B) break;
	}

	if (!U || M == N*(N-1) / 2) {
		cout << -1 << endl;
		return 0;
	}

	add_edge(A, U);
	add_edge(U, B);

	int prev = A;
	FOR(i,1,N+1) {
		if (i == A || i == B || i == U) continue;
		add_edge(prev, i);
		prev = i;
	}

	FOR(i,1,N+1) {
		if (!M) break;
		FOR(j,i+1,N+1) {
			if (!M) break;

			if (i == A && j == B) continue;
			if (i == A && mark[j] && has_edge(j, B)) continue;
			if (i == B && mark[j] && has_edge(j, A)) continue;
			if (j == B && mark[i] && has_edge(i, A)) continue;
			if (j == A && mark[i] && has_edge(i, B)) continue;
			add_edge(i, j);
		}
	}

	if (M) {
		cout << -1 << endl;
		return 0;
	}

	for (const auto &e : edge) {
		cout << e.first << " " << e.second << endl;
	}
}
