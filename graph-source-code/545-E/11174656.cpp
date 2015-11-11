//Language: GNU C++


#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<iostream>
#include<set>
#include<cstdio>
#include<fstream>
//#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;
typedef  __int64 ll;
const int inf=0x3f3f3f3f;
const int maxn=300000+5;
const int MOD=1e9+7;

struct node{
    int w,v,id;
    node(int x,int y,int z) {
        v=x,w=y,id=z;
    }
};

vector<node> edg[maxn];
  int medg[maxn],f[maxn];
int n,m;
ll dis[maxn];
bool mark[maxn]={0};
void bfs(int x) {
    queue<int >q;
    dis[x]=0;
    q.push(x);
    bool vis[maxn]={0};
    while(!q.empty()) {
        int pre=q.front();
        q.pop();
        for(int e=0;e<edg[pre].size();e++) if(dis[edg[pre][e].v]>dis[pre]+edg[pre][e].w) {
                dis[edg[pre][e].v]=dis[pre]+edg[pre][e].w;
            //vis[edg[pre][e].id]=1;
            q.push(edg[pre][e].v);
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        edg[u].push_back(node(v,w,i));
        edg[v].push_back(node(u,w,i));
    }
    scanf("%d",&u);
    for(int i=1;i<=n;i++) dis[i]=1e16;
    bfs(u);
    //int v[maxn];
    bool vis[maxn]={0};
    queue<int> q;
    q.push(u);
    ll tot=0;
    //int medg[maxn],f[maxn];
    for(int i=1;i<=n;i++) medg[i]=1e9+5;
    //for(int i=1;i<=n;i++) printf("FF %I64d\n",dis[i]);
    vector<int> ans;
    while(!q.empty()) {
        int fre=q.front();
        q.pop();
        for(int e=0;e<edg[fre].size();e++) if(!vis[edg[fre][e].id] && dis[edg[fre][e].v]-dis[fre]==edg[fre][e].w) {
            vis[edg[fre][e].id]=1;
            q.push(edg[fre][e].v);
            if(edg[fre][e].w<medg[edg[fre][e].v]) {
                medg[edg[fre][e].v]=edg[fre][e].w;
                f[edg[fre][e].v]=edg[fre][e].id;
            }
            //tot+=edg[fre][e].w;
            //ans.push_back(edg[fre][e].id);
        }
    }
    for(int i=1;i<=n;i++) if(i!=u) {
           // printf("RR %d %d %d\n",i,medg[i],f[i]);
        tot+=medg[i];
        ans.push_back(f[i]);
    }
    printf("%I64d\n",tot);
    for(int i=0;i<ans.size();i++) {
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
    return 0;
   // for()
}
