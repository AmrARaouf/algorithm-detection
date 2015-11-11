//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)a.size()
#define all(c) c.begin(), c.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rept(i, a, b) for(int i = (a); i < (b); i++)
#define fill(a, v) memset(a, v, sizeof(a))
#define foreach(c, it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

#define N 100100
vector <pii> adj[N];
bool vis[N];
set <int> choosen;

bool dfs(int u) {
    if(vis[u]) return false;
    vis[u] = true;
    bool chk = false;
    foreach(adj[u], it) {
        if(!vis[it->ff]) {
            if(dfs(it->ff)) {
                chk = true;
                continue;
            }
            if(it->ss == 2) choosen.insert(it->ff), chk = true;
        }
    }
    return chk;
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    rep(i, n - 1) {
        int x, y, t;
        cin >> x >> y >> t;
        adj[x].pb(mp(y, t));
        adj[y].pb(mp(x, t));
    }
    fill(vis, 0);
    dfs(1);
    cout << sz(choosen) << endl;
    foreach(choosen, it) cout << *it << " "; cout << endl;
}