//Language: MS C++


#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdio>

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back

#define DEBUG(x) cout << #x << ": " << (x) << endl;

list <int>   G[100010];
set  <int> res[100010];
bool       was[100010];

void dfs1(int u) {
    was[u] = true;

    for (list <int>::iterator it = G[u].begin(); it != G[u].end();) {
        int v = *it;

        if ( !was[v] ) {
            it = G[u].erase(it);

            res[v].insert(u);
            dfs1(v);

            continue;
        }

        it++;
    }
}

void dfs2(int u, int from) {
    was[u] = true;

    for (list <int>::iterator it = G[u].begin(); it != G[u].end(); it++) {
        int v = *it;

        if ( !was[v] ) {
            res[u].insert(v);
            dfs2(v, u);

            continue;
        }
        
        if ( v != from && u < v )
            res[u].insert(v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen( "input.txt", "rt", stdin );
    //freopen("output.txt", "wt", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        G[a].pb(b);
        G[b].pb(a);
    }

    dfs1(1);

    memset(was, 0, sizeof(was));

    dfs2(1, 0);

    for (int i = 1; i <= n; i++)
        if ( !was[i] ) {
            printf("%d", 0);
            return ( 0 );
        }

    for (int i = 1; i <= n; i++)
        for (set <int>::iterator it = res[i].begin(); it != res[i].end(); it++)
            printf("%d %d\n", i, *it);

//exit:
    return ( 0 );
}
