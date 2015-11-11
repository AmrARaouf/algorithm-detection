//Language: GNU C++0x


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n;
int ans[100005], c;
struct Edge {
    int v, w, next;
    Edge(int v, int w, int next):
        v(v), w(w), next(next){}
    Edge(){}
}edge[300005];
int head[100005], E;
void init() {
    E = 0;
    memset(head, -1, sizeof(head));
}
void add(int s, int t, int w) {
    edge[E] = Edge(t, w, head[s]);
    head[s] = E++;
}
bool dfs(int u, int fa) {
    int i;
    bool flag = false;
    for(i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if(v == fa) continue;
        bool ok = dfs(v, u);
        if(!ok && edge[i].w) {
            ans[c++] = v;
            flag = true;
        }
        if(ok) flag = true;
    }
    if(flag) return true;
    return false;
}
int main() {
    int i;
    init();
    scanf("%d", &n);
    for(i = 1; i < n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(z==2) z = 1;
        else z = 0;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, 0);
    printf("%d\n", c);
    for(i = 0; i < c; i++)
        printf("%d ", ans[i]);
    return 0;
}
