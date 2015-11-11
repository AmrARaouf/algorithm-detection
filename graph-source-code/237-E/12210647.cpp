//Language: GNU C++


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include<cstring>
#define V 10100
#define E 1000100
#define inf 99999999
using namespace std;
int vis[V];
int dist[V];
int pre[V],cntt[30];
char str[V];
struct Edge{
    int u,v,c,cost,next;
}edge[E];
int anss,head[V],cnt;

void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int c,int cost)
{
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].cost=cost;
    edge[cnt].c=c;edge[cnt].next=head[u];head[u]=cnt++;

    edge[cnt].u=v;edge[cnt].v=u;edge[cnt].cost=-cost;
    edge[cnt].c=0;edge[cnt].next=head[v];head[v]=cnt++;
}

bool spfa(int begin,int end){
    int u,v;
    queue<int> q;
    for(int i=0;i<=end+2;i++){
        pre[i]=-1;
        vis[i]=0;
        dist[i]=inf;
    }
    vis[begin]=1;
    dist[begin]=0;
    q.push(begin);
    while(!q.empty()){
        u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            if(edge[i].c>0){
                v=edge[i].v;
                if(dist[v]>dist[u]+edge[i].cost){
                    dist[v]=dist[u]+edge[i].cost;
                    pre[v]=i;
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return dist[end]!=inf;
}

int MCMF(int begin,int end){
    int ans=0,flow;
    int flow_sum=0;
    while(spfa(begin,end)){
        flow=inf;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u])
            if(edge[i].c<flow)
                flow=edge[i].c;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u]){
            edge[i].c-=flow;
            edge[i^1].c+=flow;
        }
        ans+=dist[end]*flow;
        flow_sum += flow;
    }
    anss=flow_sum;
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,a,b,c,cost,i,j,cc,len;
    scanf("%s",str);
    len=strlen(str);
    init();
    for (i=0;i<strlen(str);i++)
    cntt[str[i]-97]++;
    scanf("%d",&n);
    for (i=n+1;i<=n+26;i++)
        addedge(i,n+27,cntt[i-n-1],0);
    for (i=1;i<=n;i++)
    {
        scanf("%s%d",str,&cc);
        addedge(0,i,cc,i);
        memset(cntt,0,sizeof(cntt));
        for (j=0;j<strlen(str);j++)
        cntt[str[j]-97]++;    
        for (j=0;j<26;j++)
        addedge(i,n+1+j,cntt[j],0);
    }
    int z=MCMF(0,n+27);
    if (anss==len)
    printf("%d\n",z);
    else
    printf("-1");
    /*
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        addedge(0,1,2,0);
        addedge(n,n+1,2,0);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,1,c);
            addedge(b,a,1,c);
        }
    }
    */
    return 0;
}

		  		   	 			    	 	 	   	 	 	