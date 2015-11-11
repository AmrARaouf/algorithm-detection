//Language: GNU C++


#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;
typedef double ld;
//typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }

typedef pair<int, int> II;

const double PI = acos(-1.0);
const double eps = 1e-10;

const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};

const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ll mod = (ll)1e9 + 7;

#define ok puts("ok")
#define maxn 1005
#define maxe 20005
#define maxv 20005

string t, s[maxn];
int a[maxn], N;
int tnum[33], num[maxn][33];

struct Dinic {
    int n, s, t, E, adj[maxe], flow[maxe], cap[maxe], next[maxe], last[maxv], run[maxv], level[maxv], que[maxv];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t; E = 0;
        For(i, 0, n) last[i] = -1;
    }

    void add(int u, int v, int c1, int c2, int id) {
        adj[E] = v; flow[E] = (id ? c1 : 0); cap[E] = c1; next[E] = last[u]; last[u] = E++;
        adj[E] = u; flow[E] = (id ? c2 : 0); cap[E] = c2; next[E] = last[v]; last[v] = E++;
    }

    bool bfs() {
        For(i, 0, n) level[i] = -1;
        level[s] = 0;

        int qsize = 0;
        que[qsize++] = s;

        Rep(i, qsize) {
            for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
                int v = adj[e];
                if (flow[e] < cap[e] && level[v] == -1) {
                    level[v] = level[u] + 1;
                    que[qsize++] = v;
                }
            }
        }

        return level[t] != -1;
    }

    int dfs(int u, int bot) {
        if (u == t) return bot;
        for (int &e = run[u]; e != -1; e = next[e]) {
            int v = adj[e], delta = 0;
            if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
                flow[e] += delta; flow[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }

    int maxflow() {
        int total = 0;
        while (bfs()) {
            For(i, 0, n) run[i] = last[i];
            for (int delta = dfs(s, inf); delta > 0; delta = dfs(s, inf)) ;
        }
        Rep(i, N) total += flow[i * 2];

        return total;
    }
} dinic;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ms(tnum, 0);
    ms(num, 0);
    cin >> t;
    Rep(i, t.length()){
        tnum[t[i] - 'a' + 1] ++;
    }
    cin >> N;
    For(i, 1, N) {
        cin >> s[i] >> a[i];
        Rep(j, s[i].length())
            num[i][s[i][j] - 'a' + 1]++;
    }

    dinic.init(54 + N + N, 53 + N + N, 54 + N + N);

    For(i, 1, N) dinic.add(52 + i, 52 + N + i, a[i], 0, 0);
    For(i, 1, 26) dinic.add(53 + N + N, i, inf, 0, 0);
    For(i, 1, 26) dinic.add(26 + i, 54 + N + N, tnum[i], 0, 0);
    For(j, 1, N){
        For(i, 1, 26) dinic.add(i, 52 + j, num[j][i], 0, 0);
        For(i, 1, 26) dinic.add(52 + N + j, 26 + i, num[j][i], 0, 0);
        dinic.maxflow();
    }

    if(dinic.maxflow() < t.length()){
        cout << -1;
        return 0;
    }

    int res = 0;

    Rep(i, N){
//      cout << dinic.flow[i * 2] << endl;
        res += dinic.flow[i * 2] * (i + 1);
    }

    cout << res << endl;

    return 0;
}
