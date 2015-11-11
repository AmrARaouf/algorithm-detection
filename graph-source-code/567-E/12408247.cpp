//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const ll inf = 1e17;
struct Edge {
    int from, to, dis, cut, nex;
}edge[2][N << 1];
int head[2][N], edgenum[2];
void add(int u, int v, int d, Edge*edge, int *head, int &edgenum) {
    Edge E = { u,v,d,0,head[u] };
    edge[edgenum] = E;
    head[u] = edgenum++;
}
int Low[N], DFN[N];//Belong数组的值是1~block  
int Index, top;
bool Instack[N];
int n, m, s, t;

void addedge(int u, int v, Edge * edge, int*head, int&edgenum) {
    add(u, v, 0, edge, head, edgenum);
    add(v, u, 0, edge, head, edgenum);
}
void Tarjan(int u, int pre, Edge * edge, int*head) {
    int v;
    Low[u] = DFN[u] = ++Index;
    Instack[u] = true; int pre_num = 0;
    for (int i = head[u]; ~i;i = edge[i].nex) {
        v = edge[i].to;
        if (v == pre && pre_num++ == 0) continue; 
        if (!DFN[v]) {
            Tarjan(v, u, edge, head);
            Low[u] = min(Low[u], Low[v]);
            if (Low[v] > DFN[u]) {
                edge[i].cut = true;
                edge[i ^ 1].cut = true;
            }
        }
        else if (Instack[v])Low[u] = min(Low[u], DFN[v]);
    }
    Instack[u] = false;
}
void work(int x, Edge *edge, int *head) {
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    Index = top = 0;
    Tarjan(x, x, edge, head);
}
ll D[2][N];
bool inq[N];
void spfa(int from, int to, ll *dis, int*head, Edge*edge) {
    for (int i = 1; i <= n; i++)dis[i] = inf, inq[i] = false;
    dis[from] = 0;
    priority_queue<pii>q;
    q.push({ 0, from });
    while (!q.empty()) {
        pii tmp = q.top(); q.pop(); int u = tmp.second; inq[u] = false;
        for (int i = head[u];~i; i = edge[i].nex) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].dis) {
                dis[v] = dis[u] + edge[i].dis;
                if (!inq[v])inq[v] = 1, q.push({ -dis[v], v });
            }
        }
    }
}
int p[N];
int main() {
    rd(n);rd(m);rd(s);rd(t);
    memset(head[0], -1, sizeof head[0]);edgenum[0] = 0;
    memset(head[1], -1, sizeof head[1]);edgenum[1] = 0;
    while (m--) {
        int u, v, d;
        rd(u);rd(v);rd(d);
        add(u, v, d, edge[0], head[0], edgenum[0]);
        add(v, u, d, edge[1], head[1], edgenum[1]);
    }
    spfa(s, t, D[0], head[0], edge[0]);
    spfa(t, s, D[1], head[1], edge[1]);
    ll len = D[0][t];
    if (len == inf) { while (edgenum[0]--)puts("NO");return 0; }
    memset(head[1], -1, sizeof head[1]); edgenum[1] = 0;
    memset(p, -1, sizeof p);
    for (int i = 0; i < edgenum[0]; i++)
        if (len == D[0][edge[0][i].from] + edge[0][i].dis + D[1][edge[0][i].to])
        {
            addedge(edge[0][i].from, edge[0][i].to, edge[1], head[1], edgenum[1]);
            p[i] = edgenum[1] - 2;
        }
    work(s, edge[1], head[1]);
    for (int i = 0; i < edgenum[0]; i++) {
        int u = edge[0][i].from, v = edge[0][i].to;
        if (p[i] != -1 && edge[1][p[i]].cut) {
            puts("YES");
        }
        else {
            ll tmp = len - (D[0][u] + edge[0][i].dis + D[1][v]);
            tmp = -tmp + 1;
            if (tmp >= edge[0][i].dis)
                puts("NO");
            else {
                printf("CAN %d\n", tmp);
            }
        }
    }
    return 0;
}
/*
7 8 1 7
1 2 1
2 3 1
3 5 1
5 7 1
2 4 1
4 6 1
6 7 1
1 7 4


*/