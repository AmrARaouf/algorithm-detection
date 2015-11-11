//Language: GNU C++11


#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forn1(i, n) for(int i = 1; i <= int(n); i++)
#define forr(i, n) for(int i = n - 1; i >= 0; i--)
#define forr1(i, n) for(int i = n; i >= 1; i--)
#define forl(i, l, r) for(int i = int(l); i <= int(r); i++)
#define forit(it, DS) for(it = typeof((DS).begin()); it != (DS).end(); it++) 
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define y1 __y1
#define sqr(x) ((x) * (x))
#define X first
#define Y second
#define ft first
#define sc second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

ostream& operator <<(ostream out, const pt &a)
{
    out << "point == " << a.first << ' ' << a.second << endl;;
    return out;
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

const ld pi = ld(3.1415926535897932384626433832795);
const ld eps = ld(1e-9);
const int INF = int(1e9 + eps);
const li INF64 = INF * 1LL * INF;

const int N = 2e5 + 555;

vector<int> g[N];
set<pt> bad;
int n;

inline bool read()
{
    if(!(cin >> n))
        return false;

    forn(i, n - 1)
    {
        int u, v, t;
        assert(scanf("%d %d %d", &u, &v, &t) == 3);
        g[u].pb(v);
        g[v].pb(u);
        if(t == 2)
        {
            bad.insert(mp(u, v));
            bad.insert(mp(v, u));
        }
    }

    return true;
}

int depth[N];
vector<pt> bads;
bool used[N];
int p[N];

void dfs(int v, int p, int deep, bool bad)
{
    depth[v] = deep;
    ::p[v] = p;

    if(bad)
    {
        bads.pb(mp(deep, v));
    }

    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if(to == p)
            continue;
        bool nbad = ::bad.count(mp(v, to));
        dfs(to, v, deep + 1, nbad);
    }

    return;
}

inline void solve()
{
    dfs(1, 0, 1, 0);

    vector<int> ans;
    sort(all(bads));
    reverse(all(bads));

    forn(i, sz(bads))
    {
        int v = bads[i].Y;
        //cerr << "v == " << v << endl;
        if(used[v])
            continue;
        ans.pb(v);

        while(v > 0 && !used[v])
        {
            used[v] = true;
            v = p[v];
        }
    }

    printf("%d\n", sz(ans));
    forn(i, sz(ans))
        printf("%d ", ans[i]);
    cout << endl;

    return;
}

inline void clear()
{
    return;
}
 
int main(){
#ifdef _DEBUG
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#else
    //assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    srand(int(time(NULL)));

#ifdef _DEBUG
    while(read()) {
#else
    int T = 1;

    forn(tt, T)
    {
        assert(read());
#endif

        solve();
        clear();
    }

#ifdef _DEBUG
    cerr << "TIME == " << clock() << " ms" << endl;
#endif
    return 0;
}