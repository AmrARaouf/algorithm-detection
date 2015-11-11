//Language: GNU C++


#include <cstdio>
#include <algorithm>

#define pe pair<int,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int MAX_N=2010;

int n,m;
char a[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
bool viz[MAX_N][MAX_N];
pe to[MAX_N][MAX_N]; 

int dfs(int x,int y) {
    if(viz[x][y]&&!d[x][y]) {
        return -1;
    }
    else if(d[x][y]) {
        return d[x][y];
    }
    viz[x][y]=true;
    int nx=x,ny=y;
    if(a[x][y]=='^') {
        nx--;
    }
    else if(a[x][y]=='>') {
        ny++;
    }
    else if(a[x][y]=='<') {
        ny--;
    }
    else {
        nx++;
    }

    if(a[nx][ny]!='#') {
        int k=dfs(nx,ny);
        if(k==-1) {
            return -1;
        }
        to[x][y]=to[nx][ny];
        return d[x][y]=k+1;
    }
    else {
        to[x][y]=mp(x,y);
        return d[x][y]=1;
    }
    return 0;
}

int main() {
    //freopen("fis.in","r",stdin);
    //freopen("fis.out","w",stdout);
    scanf(" %d %d ",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf(" %s ",a[i]+1);
    }

    int mx=0;
    pe cord;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j]!='#'&&!viz[i][j]) {
                if(dfs(i,j)==-1) {
                    printf("-1");
                    return 0;
                }
                if(d[i][j]>mx) {
                    mx=d[i][j];
                    cord=to[i][j];
                }
            }
        }
    }

    if(mx==0) {
        printf("0\n");
        return 0;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(d[i][j]==mx&&to[i][j]!=cord) {
                printf("%d\n",2*mx);
                return 0;
            }
        }
    }
    printf("%d\n",2*mx-1);
    return 0;
}

