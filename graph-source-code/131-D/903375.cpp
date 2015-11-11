//Language: GNU C++


#include <cstdio>
#include <cstring>
const int N = 3005;
int n,e,head,tail;
int du[N];
int Q[N];
int v[N];
int vis[N];
struct edge{ int x,y; edge *next; } *ls[N],g[N*2];

void add(int x,int y){
    g[++e].x=x; g[e].y=y; g[e].next=ls[x]; ls[x]=&g[e];
}

int min(int x,int y){
    return x<y?x:y;
}

int dfs(int x,int d){
    if (!v[x]) return d;
    vis[x] = 1;
    int ret = 0x7FFFFFFF;
    for (edge *t=ls[x];t;t=t->next){
        if (vis[t->y]) continue;
        ret = min( ret , dfs(t->y,d+1) );
    }
    return ret;
}

int main(){
    e = 0;
    memset(ls,0,sizeof(ls));
    memset(du,0,sizeof(du));
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
        du[x]++;
        du[y]++;
    }
    head = 0;
    tail = 0;
    for (int i=1;i<=n;i++)
        if (du[i] == 1)
            Q[++tail] = i;
    while (head!=tail){
        head++;
        int x=Q[head];
        for (edge *t = ls[x] ; t ; t=t->next){
            if (du[t->y] == 1) continue;
            du[t->y]--;
            if (du[t->y] == 1) Q[++tail] = t->y;
        }
    }
    for (int i=1;i<=tail;i++) v[Q[i]]=1;
    for (int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        int ans = dfs(i,0);
        printf("%d ",ans);
    }
}
