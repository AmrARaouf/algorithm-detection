//Language: GNU C++


#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, v.size())
#define pb push_back
#define all(v) v.begin(), v.end()
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

void require(bool cond, const string& message = "Runtime error")
{
    if (!cond) {
        cerr << message << endl;
        assert(false);
    }
}

int n, m;
const int N = 100004;
vector<vi> g;
bool used[N];
int up[N];
int hi[N];
vector<pii> ans;

void readData()
{
    cin >> n >> m;
    g.resize(n);
    forn(i, m) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ans.reserve(m);
}

bool ok = true;

void dfs(int v, int p, int h)
{
    if (!ok) return;
    used[v] = true;
    up[v] = h;
    hi[v] = h;
    forv(i, g[v]) {
        int u = g[v][i];
        if (u == p) continue;
        if (!used[u]) {
            ans.pb(mp(v, u));
            dfs(u, v, h + 1);
            if (up[u] > h) {
                ok = false;
                return;
            }
        }
        else {
            if (hi[u] < hi[v]) {
                ans.pb(mp(v, u));
            }
        }
        up[v] = min(up[v], up[u]);
    }
}

void solve()
{
    dfs(0, -1, 0);
    if (!ok) {
        cout << 0 << endl;
        return;
    }
    forv(i, ans) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    readData();
    solve();
    return 0;
}
