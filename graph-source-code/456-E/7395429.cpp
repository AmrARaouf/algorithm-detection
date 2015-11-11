//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>

#define ALL(v) v.begin(), v.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPD(i, a, b) for(int i = a; i > b; i--)
#define REPLL(i, a, b) for(ll i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FORLL(i, a, b) for(ll i = a; i <= b; i++)
#define INF 1000000001

#define vit vector<int>::iterator
#define sit set<int>::iterator
#define vi vector<int>
#define vpii vector<pii >

#define ll long long
#define ld long double

#define PB push_back
#define MP make_pair
#define pii pair<int, int>
#define pld pair<LD, LD>
#define st first
#define nd second

using namespace std;

#define MAXN 300004

int z, n, m, q, a, b, t, x, y;
int up[MAXN]; // rodzic
int ranks[MAXN]; // wysoko�� poddrzewa
int dist[MAXN];
pii lng[MAXN];
int vis[MAXN];
vi nbs[MAXN];
int parent[MAXN];
int lss, lssv;

void make_set(int i) {
	up[i] = i;
	ranks[i] = 0;
}

int find(int i) {
	if(i != up[i]) {
		up[i] = find(up[i]);
	}
	return up[i];
}

void Union(int i, int j) {
	i = find(i);
	j = find(j);
	if(ranks[i] > ranks[j]) {
		up[j] = i;
	}
	else up[i] = j;
	if(ranks[i] == ranks[j]) {
		ranks[j]++;
	}
}

pii dfs(int v, int p) {
    vis[v] = 1;
    int l = 0;
    int lv = v;
    //cout << v << ":" << p << endl;
    REP(i, 0, nbs[v].size()) {
        int nb = nbs[v][i];
        if(nb == p) continue;
        pii r = dfs(nb, v);
        r.st++;
        if(l + r.st > lss) {
            lss = l + r.st;
            lssv = r.nd;
        }
        if(l < r.st ) {
            l = r.st; lv = r.nd;
        }
    }
    return MP(l, lv);
}

void dfs_uf(int v, int p) {
    if(vis[v] != 1) return;
    vis[v] = 2;
    Union(v, p);
    //cout << v << " = " << find(v) << endl;
    REP(i, 0, nbs[v].size()) dfs_uf(nbs[v][i], p);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);

    REP(i, 0, m) {
        scanf("%d%d", &a, &b);
        --a; --b;
        nbs[a].PB(b);
        nbs[b].PB(a);
    }

    REP(i, 0, n) make_set(i);

    REP(i, 0, n) if(!vis[i] && nbs[i].size() == 1) {
        lss = 0;
        dfs(i, -1);
        dfs_uf(lssv, lssv);
        dist[lssv] = lss;
        //cout << lssv << " ::: " << lss << endl;
    }

    REP(i, 0, q) {
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d", &x);
            --x;
            printf("%d\n", dist[find(x)]);
        }
        else {
            scanf("%d%d", &x, &y);
            --x; --y;
            if(find(x) == find(y)) continue;
            int d1 = dist[find(x)];
            int d2 = dist[find(y)];
            Union(x, y);
            int dn = (d1+1)/2 + (d2+1)/2 + 1;
            dist[find(x)] = max(max(d1, d2), dn);
        }
    }

    return 0;
}

