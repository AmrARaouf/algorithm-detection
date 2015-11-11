//Language: GNU C++


//#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
typedef long  long LL;

const int N = 505;
const int inf = 1<<29;
const double eps = 1e-8;
using namespace std;
int n,m,k;
int tot,pre[100005];
struct edge{
    int v,next;
}e[200005];
int maz[N][N],id[100005],c[N];

void init(){
    tot=0;
    memset(pre,-1,(n+2)*sizeof(int));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            maz[i][j]=inf;
        }
        maz[i][i]=0;
    }
}

void add(int u,int v){
    edge E={v,pre[u]};
    e[tot]=E,pre[u]=tot++;
}

void  input(){
    int sum=0;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=sum+1;j<=sum+c[i];j++) id[j]=i;
        sum+=c[i];
    }
    int u,v,x;
    while(m--){
        scanf("%d%d%d",&u,&v,&x);
        if(u>n||v>n) continue;
        if(x==0) add(u,v),add(v,u);
        if(id[u]==id[v]) continue;
        else{
            u=id[u],v=id[v];
            if(maz[u][v]>x) maz[u][v]=maz[v][u]=x;
        }
    }
}

int vis[100005];

bool bfs(int s){
    if(vis[s]) return 1;
    bool hehe[N];
    memset(hehe,0,sizeof(hehe));
    hehe[id[s]]=1;
    int cc=c[id[s]],sum=1;
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=pre[u];~i;i=e[i].next){
            int v=e[i].v;
            if(!vis[v]){
                sum++;
                vis[v]=1,q.push(v);
                if(!hehe[id[v]]) hehe[id[v]]=1,cc+=c[id[v]];
            }
        }
    }
//    cout<<cc<<" "<<sum<<endl;
    return cc==sum;
}

bool check(){
    memset(vis,0,(n+2)*sizeof(int));
    int sum=0;
    for(int i=1;i<=k;i++){
        if(!bfs(sum+1)) return 0;
        sum+=c[i];
    }
    return 1;
}

void floyd(){
    for(int t=1;t<=k;t++){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                maz[i][j]=min(maz[i][j],maz[i][t]+maz[t][j]);
            }
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(maz[i][j]>=inf) maz[i][j]=-1;
            printf("%d ",maz[i][j]);
        }
        puts("");
    }
}

int main(){
    //freopen("in","r",stdin);
    while(cin>>n>>m>>k){
        init();
        input();
        if(!check()) puts("No");
        else{
            puts("Yes");
            floyd();
        }
    }
    return 0;
}






