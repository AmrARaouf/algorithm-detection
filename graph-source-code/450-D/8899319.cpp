//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int head[100005];
int dis[100005];
bool in[100005];
int cou[100005];
int mp[100005];
struct edge{
    int v,w,next;
}E[100005*8];
struct cmp{
    int u,w;
    bool operator <(const cmp &a)const{
        return w>a.w;
    }
}p,te;

int n,ind;
void add(int u,int v,int w){
    E[ind].v=v;
    E[ind].w=w;
    E[ind].next=head[u];
    head[u]=ind++;
}
void init(){
    for(int i=1;i<=n;i++){
        head[i]=-1;
        dis[i]=0x3f3f3f3f;
        in[i]=false;
        mp[i]=0x3f3f3f3f;
    }
    ind=0;
}
void spfa(int u){
    priority_queue<cmp> Q;
    while(!Q.empty())
        Q.pop();
    dis[u]=0;
    p.w=0,p.u=u;
    Q.push(p);
    while(!Q.empty()){
        p=Q.top();
        Q.pop();
        if(in[p.u]) continue;
        in[p.u]=true;
        for(int it=head[p.u];it!=-1;it=E[it].next){
            int v=E[it].v;
            int w=E[it].w;
            if(p.w+w<dis[v]){
                dis[v]=p.w+w;
                cou[v]=1;
            }
            else if(p.w+w==dis[v])
                cou[v]=2;   
            else continue;
            te.u=v;
            te.w=p.w+w;
            Q.push(te);
        }
        
    }
}

int main(void){
    int m,k;
    int u,v,w;
    while(~scanf("%d%d%d",&n,&m,&k)){
        init();
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        for(int i=0;i<k;i++){
            scanf("%d%d",&v,&w);
            if(w<mp[v])
                mp[v]=w;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(mp[i]!=0x3f3f3f3f)
                add(1,i,mp[i]),ans++;
        spfa(1);
        
        for(int i=1;i<=n;i++){
            if(mp[i]!=0x3f3f3f3f){
                if(dis[i]<mp[i])
                    ans--;
                else if(dis[i]==mp[i]&&cou[i]==2)
                    ans--;
            }
        }
        printf("%d\n",k-ans);
    }
    
    return 0;
}