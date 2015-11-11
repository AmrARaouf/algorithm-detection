//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sqr(x) (x) * (x)
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const int maxn = 1005;
char s[11];
vector<pii> g[maxn];
int comp[maxn],C = 0,cntC[maxn],pC[maxn],cnt[maxn],p[maxn];
void dfs(int v) {
    comp[v] = C;
    for (int i = 0; i < sz(g[v]); i++) {
        int to = g[v][i].first;
        int good = g[v][i].second;
        if (good < 0 || comp[to] != 0) continue;
        dfs(to);
    }
}
int getC(int v) {
    return v == pC[v] ? v : pC[v] = getC(pC[v]);
}
int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m; cin >> n >> m;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int a,b; scanf("%d%d%s",&a,&b,s); --a; --b;
        g[a].pb(mp(b,s[0] == 'S' ? i + 1 : -(i + 1)));
        g[b].pb(mp(a,s[0] == 'S' ? i + 1 : -(i + 1)));
    }
    for (int i = 0; i < n; i++) if (comp[i] == 0) {
        ++C;
        dfs(i);
    }
    //cout << C << " " << (n - 1) / 2 << endl;
    if (C - 1 > (n - 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i <= C; i++) {
        pC[i] = i;
        cntC[i] = 1;
    }
    int add = (n - 1) / 2;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(g[i]); j++) {
            int to = g[i][j].first;
            int good = g[i][j].second;
            if (good > 0) continue;
            if (C > 1) {
                int u = getC(comp[i]);
                int v = getC(comp[to]);
                if (u != v) {
                    res.pb(good);
                    if (cntC[u] > cntC[v]) swap(u,v);
                    cntC[v] += cntC[u];
                    pC[u] = v;
                    u = get(i);
                    v = get(to);
                    if (cnt[u] > cnt[v]) swap(u,v);
                    cnt[v] += cnt[u];
                    p[u] = v;
                    --C;
                    --add;
                }               
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(g[i]); j++) {
            int to = g[i][j].first;
            int good = g[i][j].second;
            if (good > 0) continue;
            if (add > 0) {
                int u = get(i);
                int v = get(to);
                if (u != v) {
                    res.pb(good);
                    if (cnt[u] > cnt[v]) swap(u,v);
                    cnt[v] += cnt[u];
                    p[u] = v;
                    --add;
                }
            }
        }
    }
    if (C != 1 || add != 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(g[i]); j++) {
            int to = g[i][j].first;
            int good = g[i][j].second;
            if (good < 0) continue;
            int u = get(i);
            int v = get(to);
            if (u != v) {
                res.pb(good);
                if (cnt[u] > cnt[v]) swap(u,v);
                cnt[v] += cnt[u];
                p[u] = v;
            }
        }
    }
    cout << n - 1 << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << abs(res[i]) << " ";
    }
    return 0;
}
