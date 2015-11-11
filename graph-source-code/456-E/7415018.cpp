//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
struct edg {
    int v, n;
};

int n, m, q, c, w, rr;
int a, b, t, x, y;
int h[300001], r[300001];
int p[300001], v[300001];
edg e[600001];
inline void adde(int x, int y) {
    e[c].v=y, e[c].n=h[x], h[x]=c++;
    e[c].v=x, e[c].n=h[y], h[y]=c++; 
}
inline int find(int x) {
    return x==p[x] ? x : p[x]=find(p[x]);
}
inline void merge(int x, int y) {
    int fx=find(x), fy=find(y);
    if (fx!=fy) {
        int r1=r[fx], r2=r[fy];
        int rt=(r1+1)/2+(r2+1)/2+1;
        r[fy]=max(r1, max(r2, rt));
        p[fx]=fy;
    }
}
inline void dfs1(int x, int f, int r, int c) {
    p[x]=c;
    v[x]=1;
    if (r>rr)
        rr=r, w=x;
    for (int i=h[x]; ~i; i=e[i].n) if (e[i].v!=f)
        dfs1(e[i].v, x, r+1, c);
}
inline void dfs2(int x, int f, int r) {
    if (r>rr)
        rr=r;
    for (int i=h[x]; ~i; i=e[i].n) if (e[i].v!=f)
        dfs2(e[i].v, x, r+1);
}
int main(void) {
    scanf("%d%d%d", &n, &m, &q);
    memset(h, -1, sizeof(h));
    for (int i=1; i<=m; i++) {
        scanf("%d%d", &a, &b);
        adde(a, b);
    }
    for (int i=1; i<=n; i++) p[i]=i;
    for (int i=1; i<=n; i++) if (!v[i]) {
        rr=-1, w=-1;
        dfs1(i, -1, 0, i);
        rr=-1;
        dfs2(w, -1, 0);
        r[i]=rr;
    }
    for (int i=1; i<=q; i++) {
        scanf("%d", &t);
        if (t==1) {
            scanf("%d", &x);
            printf("%d\n", r[find(x)]);
        } else {
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
    }
}
