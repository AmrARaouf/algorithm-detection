//Language: GNU C++0x


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)

#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define sz(a) ((int)a.size())
#define mset(a, v) memset(a, v, sizeof(a))

#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << x << " "
#define dbs(x) cerr << x << " "

const int N = 100100;

int col[N];
set <int> adj[N];

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    rep(i, n) cin >> col[i];

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if(col[u] != col[v]) {
            adj[col[u]].insert(col[v]);
            adj[col[v]].insert(col[u]);
        }
    }

    int bestVal = -1, bestCol = -1;
    rep(i, n) {
        if(bestVal < sz(adj[col[i]])) {
            bestVal = sz(adj[col[i]]);
            bestCol = col[i];
        } else if(bestVal == sz(adj[col[i]])) {
            bestCol = min(bestCol, col[i]);
        }
    }
    cout << bestCol << '\n';
    return 0;
}