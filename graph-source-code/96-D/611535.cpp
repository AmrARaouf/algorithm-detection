//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#define inf 9999999999999999
using namespace std;

struct Car {
    int dis,cost;
}car[1010];

struct Data {
    __int64 y, w;
    Data(__int64 a, __int64 b): y(a), w(b) {}
};

vector<Data> G1[1010];
vector<Data> G2[1010];
__int64 Dist[1010][1010];

void spfa(int n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) Dist[i][j] = inf;
        Dist[i][i] = 0;
        bool vis[1010];
        queue<int> que;
        memset(vis, 0,sizeof(vis));
        que.push(i);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            vis[u] = 0;
            for(int k = 0; k < G1[u].size(); ++k) {
                Data v = G1[u][k];
                if(Dist[i][u] + v.w < Dist[i][v.y]) {
                    Dist[i][v.y] = Dist[i][u] + v.w;
                    if(!vis[v.y]) {
                        que.push(v.y); vis[v.y] = 1;
                    }
                }
            }
        }
    }
}

void Creat(int n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) continue;
            if(car[i].dis >= Dist[i][j]) {
                G2[i].push_back(Data(j, car[i].cost));
            }
        }
    }
}

void SPFA(int n, int s, int e) {
    __int64 dist[1010];
    bool vis[1010];
    queue<int> que;
    for(int i = 0; i <= n; ++i) {
        dist[i] = inf;
        vis [i] = 0;
    }
    dist[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        for(int i = 0; i < G2[u].size(); ++i) {
            Data v = G2[u][i];
            if(dist[u] + v.w < dist[v.y]) {
                dist[v.y] = dist[u] + v.w;
                if(!vis[v.y]) {
                    que.push(v.y); vis[v.y] = 1;
                }
            }
        }
    }
    if(dist[e] == inf) printf("-1\n");
    else printf("%I64d\n", dist[e]);
}

int main() {
    int n,m,s,e;
    scanf("%d %d %d %d",&n,&m,&s,&e);
    int i,j;
    int a,b;
    __int64 c;
    for(i = 1; i <= m; ++i) {
        scanf("%d %d %I64d", &a, &b, &c);
        G1[a].push_back(Data(b, c));
        G1[b].push_back(Data(a, c));
    }
    for(i = 1; i <= n; ++i) {
        scanf("%d %d",&car[i].dis, &car[i].cost);
    }
    spfa(n);

    /*
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j)
            cout<<G1[i][j]<<" ";
        cout<<endl;
    }
    */

    Creat(n);

    /*
    for(i = 1; i <= n; ++i) {
        for(j = 0; j < G2[i].size(); ++j)
            cout<<G2[i][j].y<<" ";
        cout<<endl;
    }
    */

    SPFA(n, s, e);
    return 0;
}
