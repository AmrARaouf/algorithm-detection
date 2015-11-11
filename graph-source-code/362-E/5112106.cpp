//Language: GNU C++


#include <vector>

#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define mod  1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define VI vector <int>
#define VII vector < vector <int> >
#define S1(x) scanf("%llu",&x)
#define MAX 100009
#define LOGMAXN 20
#define EPS 0.000001
using namespace std;

// Floyd Warshall Algorithm
const int INF  = 0x3f3f3f3f;
void input()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
}

int source,sink,n,k;
vector< vector <int> > s,g;
vector <bool> used;
int r12;
const int maxe = 100000;
const int maxn = 205;

struct Edge{
    int u,v,flow,cap,cost;
    int next;
    Edge(int u=0,int v=0,int flow=0,int cap=0,int cost=0,int next=0):
        u(u), v(v), flow(flow), cap(cap), cost(cost), next(next){}
};

struct MCMF{
    Edge edges[maxe];
    int head[maxn],cnt;
    int d[maxn];
    bool inq[maxn];
    int pa[maxn];
    int res[maxn];

    void init(){
        memset(head,-1,sizeof(head));
        cnt = 0;
    }

    void addedge(int u,int v,int cap, int xx, int cost, int yy){
        edges[cnt] = Edge(u,v,0,cap,cost,head[u]);
        head[u] = cnt++;
        edges[cnt] = Edge(v,u,0,0,-cost,head[v]);
        head[v] = cnt++;
    }

    bool SPFA(int s,int t,int& flow,int& cost){
        memset(d,0x3f,sizeof(d));
        memset(inq,0,sizeof(inq));

        queue<int> Q;
        Q.push(s);
        inq[s] = true;  d[s] = 0;
        res[s] = INF;  res[t] = 0;

        while(!Q.empty()){
            int u = Q.front();   Q.pop();
            inq[u] = false;

            for(int i=head[u];i!=-1;i=edges[i].next){
                Edge&  e = edges[i];
                if(e.cap>e.flow && d[e.v] > d[u] + e.cost){
                    d[e.v] = d[u] + e.cost;
                    pa[e.v] = i;
                    res[e.v] = min(res[u],e.cap-e.flow);
                    if(!inq[e.v]){
                        Q.push(e.v);
                        inq[e.v] = true;
                    }
                }
            }
        }
        if(res[t] == 0)  return false;
        flow += res[t];
        cost += res[t]*d[t];
        for(int i=t;i!=s;i=edges[pa[i]].u){
            edges[pa[i]].flow   += res[t];
            edges[pa[i]^1].flow -= res[t];
        }
        return true;
    }

    int MinCost(int s,int t){
        int flow = 0,cost = 0;
        while(SPFA(s,t,flow,cost)){}
        r12 = flow;
        return cost;
    }
};
struct MCMF solver;

bool is_path(int s, int t, int c)
{
    if(s == t) return true;
    if(used[s]) return false;
    used[s] = true;
    for(int i = 0; i < n; i++)
        if(g[s][i] >= c && is_path(i, t, c)) {
            g[s][i]-=c;
            g[i][s]+=c;
            return true;
        }
    return false;
}



bool check (int xx)
{
    solver.init();
    int i,j;
    F (i, 0, n) {
        F (j, 0, n) {
            if (s[i][j] == 0) {
                continue;
            }
            int x = g[i][j];
            if (x >= 0) {
                solver.addedge(i, j, x, 0, 0, 0);
                solver.addedge(i, j, k, 0, 1, 0);
            }
        }
    }
    solver.addedge(n-1, n, xx, 0, 0, 0);
    int value = solver.MinCost(0, n);

    if (value > k) {
        return false;
    }
    return true;
}

int max_flow(int s, int t, vector<vector<int> > _g)//& is used for changing _g in up-level min_cut function
{
    g = _g;
    n = g.size();
    used = vector<bool> (n, false);

    int flow = 0, c = INF;
    while(c > 0) {
        if(is_path(s, t, c))
            flow += c;
        else
            c /= 2;
        fill(used.begin(), used.end(), false);
    }
    int sum = flow;

    flow = 0;
    //cout << sum << endl;


    int xx = 0;

    int a = 0,b=k;

    while (a <= b) {
        int mid = (a + b)/2;
        if (a == b) {
            check (a);
            xx = max (xx, r12);
            break;
        }
        if (b-a == 1) {
            if (check (b)) {
                xx = max (xx, r12);
                break;
            }
            check (a);
            xx = max (xx, r12);
            break;
        }
        if (check (mid)) {
            a = mid;
            xx = max (xx, r12);
        } else {
            b = mid;
        }
    }

    sum = sum + xx;
    return sum;
}

int main()
{
    input();
    S (n);
    S (k);

    solver.init();
    int i,j;

    s.clear();
    s.resize (n);
    F (i, 0, n) {
        F (j, 0, n) {
            int x;
            S (x);
            s[i].pb (x);

        }
    }
    source = 0;
    sink = n-1;

    printf ("%d\n", max_flow(source, sink, s));

    return 0;
}
