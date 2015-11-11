//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> edge;
const int MAXN = 1e5 + 10;

void kill() {
	puts("NO");
	exit(0);
}

int N, M, P, Q, C;
int par[MAXN];  //don't forget to init
ll S[MAXN];
multiset<edge> st;

int find (int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void merge (int x, int y, int v = -1) {
    x = find(x);
    y = find(y);
    if (v == -1) {
    	v = (int) min(1000000000ll, S[x] + S[y] + 1);
    }
    if (x == y) {
    	st.erase(st.find(edge(S[x], x)));
    	st.insert(edge(S[x] += v, x));
    	return;
    }
    st.erase(st.find(edge(S[x], x)));
    st.erase(st.find(edge(S[y], y)));
    st.insert(edge(S[y] += S[x] + v, y));
	par[x] = y;
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}
	scanf("%d %d %d %d", &N, &M, &P, &Q);
	for (int i = 1; i <= N; i++) {
		par[i] = i;
		st.insert(edge(0, i));
	}
	for (int i = 0, x, y, v; i < M; i++) {
		scanf("%d %d %d", &x, &y, &v);
		merge(x, y, v);
	}
	for (int i = 1; i <= N; i++) {
		if (i == find(i)) {
			C++;
		}
	}
	//P new roads. Q comps
	int rdn = C - Q;	//# of new roads
	if (rdn < 0) {
		kill();
	}
	if (rdn == 0 && N == C && P) {
		kill();
	}
	if (rdn > P) {
		kill();
	}
	puts("YES");
	for (; rdn; rdn--, P--) {
		//merge smallest two
		auto i1 = st.begin(), i2 = next(i1);
		// printf("aa %lld, %d %lld, %d\n", i1->first, i1->second, i2->first, i2->second);
		int x = i1->second, y = i2->second;
		printf("%d %d\n", x, y);
		merge(i1->second, i2->second);
	}
	if (P) {
		//P new regular stuff...yea
		for (int i = 1; i <= N; i++) {
			if (i != find(i)) {
				int j = find(i);
				while (P--) {
					printf("%d %d\n", i, j);
				}
				return 0;
			}
		}
	}
}
 	  		     				 			 	   	  	 	