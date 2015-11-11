//Language: MS C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f_min(int x,int y){return x<y?x:y;}
struct Edge{
    int u,v,w,id,next;//0:none 1:alo 2: any
    bool mk;
    bool friend operator<(Edge a,Edge b){
        return a.w<b.w;
    }
};
Edge edge[500005],edge2[500005];
int head[500005],en,head2[500005],en2,N,M,fa[500005];
int mark[500005],md;
void insert(int u,int v,int w,int id){
    edge[en].u=u;edge[en].v=v;edge[en].w=w;edge[en].id=id;
    edge[en].next=head[u];head[u]=en++;
}
void insert2(int u,int v,int w,int id){
    edge2[en2].u=u;edge2[en2].v=v;edge2[en2].w=w;edge2[en2].id=id;
    edge2[en2].mk=0;
    edge2[en2].next=head2[u];head2[u]=en2++;
}
int fstk[100005];
int findf(int x,int d){
    if(fa[x]!=x)fa[x]=findf(fa[x],d+1);
    return fa[x];
}
void get_data(){
    memset(head,-1,sizeof(head));en=0;
    int i,u,v,w;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d%d%d",&u,&v,&w);u--;v--;
        insert(u,v,w,i);
    }
    sort(edge,edge+en);
}
int typ[500005];
int stk[500005],sn,tim,instk[500005],sd,dfn[500005],now[500005];
void dfs(int u){
    int i,v;
    now[u]=dfn[u]=tim++;
    stk[sn++]=u;instk[u]=sd;
    for(i=head2[u];i!=-1;i=edge2[i].next){//printf("%d %d\n",i,edge2[i].next);
        if(edge2[i].mk)continue;
        edge2[i^1].mk=1;
        v=edge2[i].v;
        if(instk[v]!=sd)dfs(v),dfn[u]=f_min(dfn[u],dfn[v]);
        else dfn[u]=f_min(dfn[u],now[v]);
        if(dfn[v]>now[u]){
            typ[edge2[i].id]=2;
        }
    }
}
/*
4 5
1 2 1
1 3 1
2 3 0
2 4 1
3 4 1
*/
void run(){
    int s,e,i,u,v,cnt=0;
    for(i=0;i<N;i++)fa[i]=i;
    for(i=0;i<M;i++)typ[i]=-1;
    for(s=0;s<M;s=e){
        for(e=s;e<M&&edge[e].w==edge[s].w;e++);
        for(i=s;i<e;i++){
            u=findf(edge[i].u,0);v=findf(edge[i].v,0);
            if(u==v)typ[edge[i].id]=0;
        }
        md++;en2=0;
        for(i=s;i<e;i++){
            if(typ[edge[i].id]==0)continue;
            u=findf(edge[i].u,0);v=findf(edge[i].v,0);
            if(mark[u]!=md){head2[u]=-1;mark[u]=md;}
            if(mark[v]!=md){head2[v]=-1;mark[v]=md;}
            insert2(u,v,edge[i].w,edge[i].id);
            insert2(v,u,edge[i].w,edge[i].id);
        }
        sn=0;tim=0;sd++;
        for(i=s;i<e;i++){
            if(typ[edge[i].id]==0)continue;
            if(instk[findf(edge[i].u,0)]!=sd)dfs(findf(edge[i].u,0));
            if(instk[findf(edge[i].v,0)]!=sd)dfs(findf(edge[i].v,0));
        }
        for(i=s;i<e;i++){
            u=findf(edge[i].u,0);v=findf(edge[i].v,0);
            if(u!=v)fa[u]=v,cnt++;
            if(typ[edge[i].id]==-1)typ[edge[i].id]=1;
        }
    }
    for(i=0;i<M;i++){
        if(cnt!=N-1)printf("none\n");
        else if(typ[i]==0)printf("none\n");
        else if(typ[i]==1)printf("at least one\n");
        else printf("any\n");
    }
}
int main(){
    memset(instk,0,sizeof(instk));sd=0;
    memset(mark,0,sizeof(mark));md=0;
    get_data();
    run();
    return 0;
}