//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define mem(name,value) memset(name,value,sizeof(name))
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;

const int maxn = 3000+10;
const int inf = 0x3f3f3f3f;

int d[maxn][maxn];

vector<int>G[maxn];

bool vis[maxn];

void bfs(int s){
    mem(vis,false);
    vis[s] = true;
    d[s][s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!vis[v]){
                d[s][v] = d[s][u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    mem(d,inf);
    int n,m,u,v,s1,t1,l1,s2,t2,l2;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    FOR(i,n) bfs(i);

    int ans = inf;
    if(d[s1][t1] <= l1 && d[s2][t2] <= l2) ans = d[s1][t1] + d[s2][t2];
    else{
        printf("-1\n",ans);
        return 0;
    }
    FOR(i,n) FOR(j,n){
        int tmp1 = d[s1][i] + d[i][j] + d[j][t1] + d[s2][i] + d[j][t2];
        if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2) ans = min(ans,tmp1);
        int tmp2 = d[s1][i] + d[i][j] + d[j][t1] + d[s2][j] + d[i][t2];
        if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][j] + d[j][i] + d[i][t2] <= l2) ans = min(ans,tmp2);
    }
    printf("%d\n",m - ans);
    return 0;
}
