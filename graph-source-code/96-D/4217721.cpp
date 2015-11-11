//Language: GNU C++


#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 10000 + 10;
const int maxm = 1000 * 1000;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct CSPFA{
    int head[maxn], nxt[maxm], u[maxm], v[maxm], w[maxm], S, T, e;
    long long d[maxn];
    bool inq[maxn];
    void init(){
        memset(head, -1, sizeof(head));
        e = 0;
    }
    void addEdge(int uu, int vv, int ww){
        u[e] = uu;
        v[e] = vv;
        w[e] = ww;
        nxt[e] = head[uu];
        head[uu] = e;
        e++;
    }
    void spfa(int S){
        memset(inq, 0, sizeof(inq));
        memset(d, 0x3f, sizeof(d));
        d[S] = 0;
        queue<int> qu;
        qu.push(S);
        while(!qu.empty()){
            int x = qu.front(); qu.pop();
            inq[x] = 0;
            for(int e = head[x]; e != -1; e = nxt[e]) if(d[v[e]] > d[x] + w[e]){
                d[v[e]] = d[x] + w[e];
                if(!inq[v[e]]){
                    qu.push(v[e]);
                    inq[v[e]] = 1;
                }
            }
        }
    }
}S1, S2;

int main()
{
    int n, m, x, y, i, j, uu, vv, ww, t, c;
    while(scanf("%d%d", &n, &m) == 2){
        scanf("%d%d", &x, &y);
        S1.init();
        for(i = 0; i < m; i++){
            scanf("%d%d%d", &uu, &vv, &ww);
            S1.addEdge(uu, vv, ww);
            S1.addEdge(vv, uu, ww);
        }
        S2.init();
        for(i = 1; i <= n; i++){
            scanf("%d%d", &t, &c);
            S1.spfa(i);
            for(j = 1; j <= n; j++) if(S1.d[j] <= t){
                S2.addEdge(i, j, c);
            }
        }
        S2.spfa(x);
        long long ret = S2.d[y] == INF ? -1 : S2.d[y];
        printf("%I64d\n", ret);
    }
    return 0;
}
