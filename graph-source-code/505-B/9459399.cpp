//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<queue>
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std;
const int M=512;
struct G{
    struct E{
        int v,w,next;
    }e[M];
    int le,head[M];
    void init(){
        le=0;
        mt(head,-1);
    }
    void add(int u,int v,int w){
        e[le].v=v;
        e[le].w=w;
        e[le].next=head[u];
        head[u]=le++;
    }
}g;
queue<int> q;
bool vis[M];
int bfs(int s,int t,int c){
    mt(vis,0);
    vis[s]=true;
    while(!q.empty()) q.pop();
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==t) return 1;
        for(int i=g.head[u];~i;i=g.e[i].next){
            int w=g.e[i].w;
            if(w!=c) continue;
            int v=g.e[i].v;
            if(vis[v]) continue;
            vis[v]=true;
            q.push(v);
        }
    }
    return 0;
}
int main(){
    int n,m,u,v,w,q;
    while(~scanf("%d%d",&n,&m)){
        g.init();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g.add(u,v,w);
            g.add(v,u,w);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&u,&v);
            int ans=0;
            for(int i=1;i<=m;i++){
                ans+=bfs(u,v,i);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
