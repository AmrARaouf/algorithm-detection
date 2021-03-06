//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 1110
#define INF (1<<29)


char mmap[MAX][MAX];
queue<int> qu;
int n,m,k,st[MAX],nn,mm,ans;
int in[MAX][MAX],pre[MAX][MAX];
int cost[MAX][MAX],arr[MAX][MAX];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


void Initial() {

    ans = INF;
    nn = (1<<k),mm = n * m;
    for (int i = 0; i < nn; ++i)
        for (int j = 0; j < mm; ++j)
            cost[j][i] = INF;
    memset(st,0,sizeof(st));
    memset(in,0,sizeof(in));
    memset(pre,-1,sizeof(pre));
}
void Update(int u,int nst,int w,int fa){

    if (cost[u][nst] > w) {

        cost[u][nst] = w;
        pre[u][nst] = fa;
        if (!in[u][nst]) {

            in[u][nst] = 1;
            qu.push(u*MAX+nst);
        }
    }
}
int Check(int x,int y) {

    return x >= 0 && x < n && y >= 0 && y < m;
}
void Steiner_Tree() {

    int i,j,t,u,nst;
    int xx,yy,x,y;


    while (!qu.empty()) {
        
        u = qu.front() / MAX;
        nst = qu.front() % MAX;
        x = u / m,y = u % m;
        qu.pop(),in[u][nst] = 0;


        for (i = 0; i < 4; ++i) {

            xx = x + dir[i][0];
            yy = y + dir[i][1];
            if (Check(xx,yy) == 0) continue;
            t = xx * m + yy;
            Update(t,nst|st[t],cost[u][nst]+arr[xx][yy],u*MAX+nst);
        }


        t = nn - 1 - nst;
        for (i = (t-1) & t; i; i = (i-1) & t)
            Update(u,nst|i,cost[u][nst]+cost[u][i]-arr[x][y],u*MAX+nst);
    }
}
void Find_Path(int u,int nst) {

    int x = u / m,y = u % m;
    mmap[x][y] = 'X';
    if (pre[u][nst] == -1) return ;


    int uu = pre[u][nst] / MAX;
    int nnst = pre[u][nst] % MAX;


    Find_Path(uu,nnst);
    if (nst - nnst) Find_Path(uu,nst-nnst);
}
void Solve_DP() {

    int i,u,nst;
    for (i = 0; i < mm; ++i)
        if (cost[i][nn-1] < ans) {

            ans = cost[i][nn-1];
            u = i;
        }


    Find_Path(u,nn-1);
}


int main()
{
    int i,j,t,x,y;


    while (scanf("%d%d%d",&n,&m,&k) != EOF) {

        Initial();
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j) {

                scanf("%d",&arr[i][j]);
                mmap[i][j] = '.';
            }
        for (i = 0; i < k; ++i) {

            scanf("%d%d",&x,&y);
            x--, y--;
            t = x * m + y;
            st[t] = (1<<i);
            Update(t,st[t],arr[x][y],-1);
        }


        Steiner_Tree();
        Solve_DP();
        printf("%d\n",ans);
        for (i = 0; i < n; ++i)
            printf("%s\n",mmap[i]);
    }
}