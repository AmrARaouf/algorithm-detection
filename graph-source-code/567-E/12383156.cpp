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
const int SIZE = 1e5+10;
const LL INF = 1e15;
const int MN = 300;
const int MOD0=1000000007;
const int MOD1=1000000009;
const int MOD2=1000000021;

struct Integer
{
    int a0, a1, a2;
    Integer()
    {
        //
    }
    Integer(int x)
    {
        *this=x;
    }
    Integer& operator= (const int x)
    {
        a0=a1=a2=x;
        return *this;
    }
    Integer operator+ (const Integer& other) const
    {
        Integer ret;
        ret.a0=a0+other.a0;
        if(ret.a0>=MOD0)
            ret.a0-=MOD0;
        ret.a1=a1+other.a1;
        if(ret.a1>=MOD1)
            ret.a1-=MOD1;
        ret.a2=a2+other.a2;
        if(ret.a2>=MOD2)
            ret.a2-=MOD2;
        return ret;
    }
    Integer operator* (const Integer& other) const
    {
        Integer ret;
        ret.a0=1LL*a0*other.a0%MOD0;
        ret.a1=1LL*a1*other.a1%MOD1;
        ret.a2=1LL*a2*other.a2%MOD2;
        return ret;
    }
    bool operator== (const Integer& other) const
    {
        return a0==other.a0 && a1==other.a1 && a2==other.a2;
    }
};
#define LOCALTEST 0 // change this to 1 to perform localtest on "in.txt"
int n,m,s,t;
vector<PII> edges;
LL cost[SIZE];
int good[SIZE];
vector<vector<int> > g, re;
int vis[SIZE];
vector<int> goodedges;
int canreacht[SIZE];
vector<vector<int> > parentedges;
LL di[SIZE];
LL sssp[2][SIZE];
Integer numways[2][SIZE];
Integer numwaysmod[2][SIZE];
int other(PII &e, int x) {
    if (e.F == x) return e.S;
    return e.F;
}
int contains(PII &e, int x) {
    return e.F == x || e.S == x;
}
void markdefinite() {
    set<pair<LL,PII> > q;
    MS0(vis);
    q.insert(MP(0,MP(t,-1)));
    while (!q.empty()) {
        pair<LL,PII> a = *q.begin();
        q.erase(q.begin());
        int u = a.S.F;
        LL c = a.F;
        int cnt = 0;
        REP(i,SZ(parentedges[u])) {
            int e = parentedges[u][i];
            q.insert(MP(c + cost[e], MP(other(edges[e], u), e)));
            cnt++;
        }
        if (SZ(q) == 1 && cnt == 1) {
            int e = q.begin()->S.S;
            good[e] = 0;
        }
    }
    //REP(i,m) printf("good[%d] = %d\n",i,good[i]);
}
void dijkstra() {
    MS0(vis);
    MS0(numways);
    MS0(numwaysmod);
    numways[0][s] = 1;
    numwaysmod[0][s] = 1;
    parentedges.clear(); parentedges.resize(n+1);
    REP(i,n+1) di[i] = INF;
    REP(i,2) REP(j,n+1) sssp[i][j] = INF;
    di[s] = sssp[0][s] = 0;
    set<pair<LL,int> > q;
    q.insert(MP(0,s));
    while (!q.empty()) {
        pair<LL,int> a = *q.begin();
        q.erase(q.begin());
        int u = a.S;
        LL c = a.F;
        if (vis[u]) continue;
        vis[u] = 1;
        REP(i,SZ(g[u])) {
            int v = other(edges[g[u][i]], u);
            if (cost[g[u][i]] + c < di[v]) {
                parentedges[v] = vector<int>();
                parentedges[v].PB(g[u][i]);
                di[v] = cost[g[u][i]] + c;
                q.insert(MP(di[v], v));
                sssp[0][v] = di[v];
                numways[0][v] = numways[0][u];
            } else if (cost[g[u][i]] + c == di[v]) {
                parentedges[v].PB(g[u][i]);
                numways[0][v] = numways[0][v] + numways[0][u];
            }
        }
    }

/*
    REPP(i,1,n+1) {
        printf("parent edges of %d:",i);
        REP(j,SZ(parentedges[i])) {
            printf(" %d",parentedges[i][j]);
        }
        printf("\n");
    }
*/


    //markdefinite();



    q.clear();
    MS0(vis);
    REP(i,n+1) di[i] = INF;
    REP(j,n+1) sssp[1][j] = INF;
    di[t] = sssp[1][t] = 0;
    q.insert(MP(0,t));
    numways[1][t] = 1;
    numwaysmod[1][t] = 1;
    while (!q.empty()) {
        pair<LL,int> a = *q.begin();
        q.erase(q.begin());
        int u = a.S;
        LL c = a.F;
        if (vis[u]) continue;
        vis[u] = 1;
        REP(i,SZ(re[u])) {
            int v = other(edges[re[u][i]], u);
            if (cost[re[u][i]] + c < di[v]) {
                parentedges[v] = vector<int>();
                parentedges[v].PB(re[u][i]);
                di[v] = cost[re[u][i]] + c;
                q.insert(MP(di[v], v));
                sssp[1][v] = di[v];
                numways[1][v] = numways[1][u];
            } else if (cost[re[u][i]] + c == di[v]) {
                parentedges[v].PB(re[u][i]);
               numways[1][v] = numways[1][v] + numways[1][u];
            }
        }
    }
}
int main(){
    if (LOCALTEST) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    while (RII(n,m) == 2) {
        RII(s,t);
        edges.clear();
        MS0(cost);
        MS1(good);
        g.clear(); g.resize(n+1);
        re.clear(); re.resize(n+1);
        REP(i,m) {
            DRIII(x,y,z);
            edges.PB(MP(x,y));
            cost[i] = z;
            g[x].PB(i); re[y].PB(i);
        }
        dijkstra();
        //printf("s -> t %I64d\n",sssp[0][t]);
        REP(i,m) {
                int x = edges[i].F, y = edges[i].S;
                //printf("numways[1][%d] = %I64d, numways[0][%d] = %I64d\n",y,numways[1][y],x,numways[0][x]);
                if (sssp[0][x] + sssp[1][y] + cost[i] == sssp[0][t] && numways[0][x] * numways[1][y] == numways[0][t]) {
                    printf("YES\n");
                } else if (contains(edges[i], s) && sssp[1][other(edges[i], s)] > sssp[0][t]
                    || contains(edges[i], t) && sssp[0][other(edges[i], t)] > sssp[0][t]) {
                    printf("NO\n");
                } else if (sssp[0][t] > sssp[0][x] + sssp[1][y] + 1) {
                    //printf("%I64d > %I64d + %I64d + 1 for x %d y %d\n",sssp[0][t], sssp[0][x], sssp[1][y],x,y);
                    int cc = cost[i] - (sssp[0][t] - sssp[0][x] - sssp[1][y] - 1);
                    printf("CAN %d\n", cc);
                } else {
                    printf("NO\n");
                }

        }
    }
    return 0;
}
