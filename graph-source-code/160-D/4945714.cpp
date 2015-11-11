//Language: GNU C++


/*******************\
|* # By longbiau # *|
\*******************/

// #include C {
#include<cstring>
#include<cassert>
#include<cstdio>
#include<cctype>
#include<cmath>
// }

// #include C++ {
#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
typedef pair <char, char> PCC;
typedef pair <double, double> PDD;
// }
#ifndef ONLINE_JUDGE
// #parameter{
#define TYPE decltype
/////////////////////////////////////////////////////////////
#else
/////////////////////////////////////////////////////////////
#define TYPE __typeof
// }
#endif
// #define {
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = 2.0*acos(0.0);
const double EPS = 1e-6;

#define GREATER(x, y) ((x) > (y) + EPS)
#define GREATER_EQUAL(x, y) ((x) > (y) - EPS)
#define LESS(x, y) ((x) < (y) - EPS)
#define LESS_EQUAL(x, y) ((x) < (y) + EPS)
#define EQUAL(x, y) (abs((x) - (y)) < EPS)

#define MAX_N 100005
#define MAXX 0x3f
#define MAX 2005
#define UPPER 2147483647LL
#define INF (1<<29)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
struct data{
    int a, b, w;
}edge[MAX_N];
int idx[MAX_N];
bool compare(int a, int b){
    return edge[a].w < edge[b].w;
}
struct data2{
    int v, at;
    struct data2 *next;
} adj[3*MAX_N], *head[MAX_N];
void add_edge(int u, int v, int id){
    static int tail;
    adj[++tail].v = v;
    adj[tail].at = id;
    adj[tail].next = head[u];
    head[u] = adj+tail;
}
int type[MAX_N];
int boss[MAX_N];
int find_boss(int x){
    if (boss[x] == 0)
        return x;
    return boss[x] = find_boss(boss[x]);
}
set <int> S;
int dpt[MAX_N], low[MAX_N];
bitset <MAX_N> visit;
static int stamp;
void tarjan(int vtx){
    dpt[vtx] = low[vtx] = ++stamp;
    for(data2 *p=head[vtx]; p!=NULL; p=p->next){
        if(visit[p->at])
            continue;
        visit[p->at] = true;
        if(dpt[p->v] != 0)
            low[vtx] = min(low[vtx], dpt[p->v]);
        else{
            tarjan(p->v);
            if(low[p->v] > dpt[vtx])
                type[p->at] = 2;
            low[vtx] = min(low[vtx], low[p->v]);
        }
    }
}
/////////////////////////////////////////////////////////////
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        data &e = edge[i];
        scanf("%d %d %d", &e.a, &e.b, &e.w);
        idx[i] = i;
    }
    sort(idx+1, idx+m+1, compare);
    for(int i=1, j=0; i<=m; i=j){
        for(j=i; j<=m; j++)
            if(edge[idx[j]].w != edge[idx[i]].w)
                break;
        FOR(cc, S){
            dpt[*cc] = low[*cc] = 0;
            head[*cc] = NULL;
        }
        S.clear();
        ::stamp = 0;
        for(int e=i; e<j; e++){
            int u = find_boss(edge[idx[e]].a);
            int v = find_boss(edge[idx[e]].b);
            if(u != v){             
                type[idx[e]] = 1;
                add_edge(u, v, idx[e]);
                add_edge(v, u, idx[e]);
                S.insert(u);
                S.insert(v);
            }
        }
        FOR(ss, S)
            if(dpt[*ss] == 0)
                tarjan(*ss);
        for(int e=i; e<j; e++){
            int u = find_boss(edge[idx[e]].a);
            int v = find_boss(edge[idx[e]].b);
            if(u != v)
                boss[u] = v;
        }
    }
    for(int i=1; i<=m; i++)
        if(type[i] == 0)
            puts("none");
        else if(type[i] == 1)
            puts("at least one");
        else
            puts("any");
    return 0;
}