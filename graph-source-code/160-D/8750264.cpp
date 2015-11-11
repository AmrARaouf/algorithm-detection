//Language: GNU C++0x


/* Teen Paryatak */
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define rep(i,n)        for(int (i)=(0);(i)<(n);(i)++)
#define foreach(it,c)   for(__typeof(c.begin()) it=(c).begin();it!=(c).end();++it)
#define fill(a,v)       memset(a,v,sizeof(a))
#define db(a)           cerr << #a << ": " << (a) << endl;

#define mp                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second

const int INF = (int) 1e9;
const ll LINF = INF * (ll) INF;
const int MAXN = (int) 1e6 + 5;

vector<pii> edges[MAXN];
vector<vector<int> > g;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        rep(i, n) parent[i] = i;
    }
    int findParent(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = findParent(parent[x]);
    }
    void merge(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

vector<int> fup, tin, visited;
int timer;
set<pii> bridges;

void dfs(int from, int par = -1) {
    visited[from] = true;
    tin[from] = timer;
    fup[from] = timer;
    timer++;
    rep(i, g[from].size()) {
        int to = g[from][i];
        if (to == par) {
            continue;
        }
        if (!visited[to]) {
            dfs(to, from);
            fup[from] = min(fup[from], fup[to]);
            if (fup[to] > tin[from]) {
                int from1 = from;
                int to1 = to;
                if (from1 > to1) {
                    swap(from1, to1);
                }
                bridges.insert(mp(from1, to1));
            }
        } else {
            fup[from] = min(fup[from], tin[to]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<pii> actualEdges;

    rep(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        if (x > y) {
            swap(x, y);
        }
        edges[w].pb(make_pair(x, y));
        actualEdges.pb(mp(x, y));
    }

    map<pii, int> Type;

    DSU dsu(n);
    rep(w, MAXN) {
        if (edges[w].size() == 0) {
            continue;
        }
        //cout << "current weight " << w << endl;
        vector<pii> newEdges;

        set<int> vertices;

        rep(it, edges[w].size()) {
            int x = edges[w][it].ff;
            int y = edges[w][it].ss;
            int px = dsu.findParent(x);
            int py = dsu.findParent(y);
            if (px != py) {
                if (px > py) {
                    swap(px, py);
                }
                newEdges.pb(mp(px, py));
                vertices.insert(px);
                vertices.insert(py);
            }
        }

        map<int, int> Map, revMap;

        int cnt = 0;
        foreach(it, vertices) {
            Map[*it] = cnt;
            revMap[cnt] = *it;
            cnt++;
        }

        // create graph
        g.clear();
        g.resize(cnt);
        set<pii> takenEdges, invalid;
        rep(i, newEdges.size()) {
            int x = Map[newEdges[i].ff];
            int y = Map[newEdges[i].ss];
            if (x > y) {
                swap(x, y);
            }
            if (takenEdges.find(mp(x, y)) == takenEdges.end()) {
                //cout << "here " << x << " " << y << endl;
                g[x].pb(y);
                g[y].pb(x);
                takenEdges.insert(mp(x, y));
            } else {
                invalid.insert(mp(x, y));
            }
        }

        tin.clear(); tin.resize(cnt);
        fup.clear(); fup.resize(cnt);
        bridges.clear();
        visited.clear(); visited.resize(cnt);

        timer = 1;
        rep(i, cnt) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        rep(it, edges[w].size()) {
            int x = edges[w][it].ff;
            int y = edges[w][it].ss;
            int px = dsu.findParent(x);
            int py = dsu.findParent(y);
            if (px != py) {
                px = Map[px];
                py = Map[py];
                if (px > py) {
                    swap(px, py);
                }
                if (bridges.find(mp(px, py)) != bridges.end() && invalid.find(mp(px, py)) == invalid.end()) {
                    Type[mp(x, y)] = 1;
                }
            }
        }

        rep(it, edges[w].size()) {
            int x = edges[w][it].ff;
            int y = edges[w][it].ss;
            int px = dsu.findParent(x);
            int py = dsu.findParent(y);
            if (px != py) {
                if (Type.find(mp(x, y)) == Type.end()) {
                    Type[mp(x, y)] = 3;
                }
            }
        }

        rep(it, edges[w].size()) {
            int x = edges[w][it].ff;
            int y = edges[w][it].ss;
            int px = dsu.findParent(x);
            int py = dsu.findParent(y);
            if (px != py) {
                dsu.merge(x, y);
            }
        }
    }

    rep(i, actualEdges.size()) {
        int x = actualEdges[i].ff;
        int y = actualEdges[i].ss;
        int t = 2;
        if (Type.find(mp(x, y)) != Type.end()) {
            t = Type[mp(x, y)];
        }
        if (t == 1) cout << "any" << endl;
        else if (t == 3) cout << "at least one" << endl;
        else cout << "none" << endl;
    }

    return 0;
}
