//Language: GNU C++


#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define PER(I, N) for (int I = (N); I >= 0; --I)
#define PERR(I, A, B) for (int I = (A); I >= B; --I)
#define ITR(I, A) for (__typeof((A).begin()) I=(A).begin(), _##i=(A).end(); I!=_##i; ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
#define LB(X) __builtin_ctz((X))
#define ONES(X) __builtin_popcount((X))
typedef long long LL;
using namespace std;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int MOD = 1e9+7;
const int SIZE = 3000+10;
#define LOCALTEST 0 // change this to 1 to perform localtest on "in.txt"
int n;
vector<vector<int> > g;
int tim, dfslow[SIZE], dfscur[SIZE], was[SIZE], sccmade[SIZE];
vector<vector<int> > scc;
int cmp[SIZE];
int di[SIZE];
stack<int> st;
int onstack[SIZE];
void dfs(int u, int p) {
    if (dfscur[u] != -1) return;
    dfscur[u] = dfslow[u] = tim++;
    onstack[u] = 1;
    st.push(u);

    REP(i,SZ(g[u])) {
        int v = g[u][i];
        if (v == p) continue;
        if (dfscur[v] == -1) {
            dfs(v, u);
            smin(dfslow[u], dfslow[v]);
        } else if (onstack[v]) {
            smin(dfslow[u], dfscur[v]);
        }
    }

    if (dfscur[u] == dfslow[u]) {
        scc.PB(vector<int>());
        while (!st.empty()) {
            int tp = st.top();
            st.pop();
            cmp[tp] = SZ(scc)-1;
            scc[SZ(scc)-1].PB(tp);
            onstack[tp] = 0;

            if (tp == u) break;
        }
    }
}
void dijkstra(int ring) {
    set<PII> q;
    REP(i,SZ(scc[ring])) q.insert(MP(0,scc[ring][i]));
    MS0(was); memset(di, 0x3f3f3f3f, sizeof(di));
    while (!q.empty()) {
        PII f = *q.begin();
        q.erase(q.begin());
        int w = f.F, u = f.S;
        if (was[u] || di[u] <= w) continue;
        was[u] = 1;
        di[u] = w;
        REP(i,SZ(g[u])) {
            int v = g[u][i];
            q.insert(MP(di[u] + 1, v));
        }
    }
}
int main(){
    if (LOCALTEST) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    while (RI(n) == 1) {
        g.clear();
        g.resize(n);
        REP(i,n) {
            DRII(x,y);
            x--,y--;
            g[x].PB(y); g[y].PB(x);
        }
        tim = 0; MS1(dfslow); MS1(dfscur); MS0(onstack); scc.clear();
        REP(i,n) dfs(i,-1);

        int ring = -1;
        REP(i,SZ(scc)) {
            //printf("scc %d: ",i);
            //REP(j,SZ(scc[i])) printf("%d%c",scc[i][j],j==SZ(scc[i])-1?'\n':' ');
            if (SZ(scc[i]) > 1) ring = i;
        }

        dijkstra(ring);

        REP(i,n) {
            printf("%d%c",di[i],i==n-1?'\n':' ');
        }
    }
    return 0;
}
