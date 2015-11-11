//Language: GNU C++


#include<cstdio>
#include<algorithm>
using namespace std;
const int inf = 1<< 22;
const int maxl = 1512000;

struct node { int x,y;}tmp;
int c[210],v[210],dis[210][210],lis[maxl],pre[210][210];
int u[101011],f[210][210],pr[210][210],w[210];
int n,m,k,maxk,p1,q1,ans,x_;

bool fit(node &a) {
     return a.x>0 && a.x<=n && a.y>0 && a.y<= m;
}
int pos(int i, int j) 
{
    return (i-1)* m + j;
}

void updata(int x0, int y0, int x1, int y1, int z) {
     if (f[x0][y0] <= z) return;
     f[x0][y0] = z;
     if (y0 == y1) pr[x0][y0] = -x1; else pr[x0][y0] = y1;
     x1 = (y0 << k) + x0;
     if (!u[x1]) {
        lis[++q1] = x1;
        u[x1] = 1;
     }
}

void bfs() {
     int x0,y0,sta,pu;
     for (p1 = 1; p1 <= q1; ++p1) {
         u[lis[p1]] = 0;
         sta = (lis[p1] & ((1<< k)-1));
         lis[p1] >>= k;
         x0 = (lis[p1]-1)/m + 1; y0 = (lis[p1]-1)%m + 1;
         pu = f[sta][lis[p1]];
         
         for (int i = 1; i <= maxk; ++i)
             if ((i & sta)== 0) 
                updata(i ^ sta, lis[p1], sta, lis[p1], f[i][lis[p1]] + pu - v[lis[p1]]);
         
         for (int t,i = -1; i <= 1; ++i)
             for (int j = (i!=0?0:-1); j <= 1; j += 2) {
                 tmp.x = x0 + i;
                 tmp.y = y0 + j;
                 if (!fit(tmp)) continue;
                 t = pos(tmp.x, tmp.y);
                 
                 updata(sta, t, sta, lis[p1], pu + v[t]);
             }
         
     }
}

void wfin(int mask, int x) {
     w[x] = 1;
     if (!mask || !pr[mask][x]) return ;
     if (pr[mask][x] < 0) {
        wfin(-pr[mask][x], x);
        wfin(mask ^ (-pr[mask][x]), x);
     } else {
        wfin(mask & (mask ^ c[x]), pr[mask][x]);
     }
}

void printout() {
     for (int i = 1; i <= n; ++i) {
         for (int j = 1; j <= m; ++j)
             if (w[pos(i,j)]) printf("X"); else printf(".");
         printf("\n");
     }
}

int main() {
    //freopen("garden.in", "r", stdin);freopen("garden.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    maxk = 1<< k;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) scanf("%d", v+pos(i,j));
    for (int x1,y1,i = 0; i <= k-1; ++i) {
        scanf("%d%d", &x1, &y1);
        c[pos(x1,y1)] = 1<< i;
    }
    
    ans = inf;
    x_ = 0;
    --maxk;
    for (int i = 1; i <= maxk; ++i) fill(f[i], f[i]+n*m + 1, inf);
    
    q1 = 0;
    fill(u, u+n*m*(maxk+5)+1, 0);
    for (int i = 1; i <= n*m; ++i) 
        if (c[i]) {
           u[lis[++q1] = (i << k)+c[i]] = 1;
           f[c[i]][i] = v[i];
        }
    bfs();
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) if (f[maxk][pos(i,j)] < ans) {
                 ans = f[maxk][pos(i,j)];
                 x_ = pos(i,j);
            }
            
    printf("%d\n", ans);
    wfin(maxk, x_);
    printout();
    return 0;
}
