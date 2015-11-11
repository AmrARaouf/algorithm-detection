//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif


#define maxn 201000
#define maxe 701000
struct Edge{
    int from,to,next;
}edge[maxe];
int head[maxn];
int n,m,cnt;
void add(int q,int h) {
    edge[cnt].from=q;
    edge[cnt].to=h;
    edge[cnt].next=head[q];
    head[q]=cnt;
    cnt++;
}
void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}

int str[maxn];
int mod = 1000000007;


stack<int>Stack;
int dfn[maxn],low[maxn],towhere[maxn];
int gro_num[maxn],Dindex,id;
bool instack[maxn];
void tarjan(int s) {
    dfn[s]=low[s]=++Dindex;
    Stack.push(s);
    instack[s]=true;
    int to;
    for(int i=head[s]; i!=-1; i=edge[i].next){
        to=edge[i].to;
        if(dfn[to]==0){
            tarjan(to);
            low[s]=min(low[to],low[s]);
        }else if(instack[to])
            low[s]=min(dfn[to],low[s]);
    }
    if(low[s]==dfn[s]) {
        id++;
        while(1) {
            int t=Stack.top();
            Stack.pop();
            towhere[t]=id;
            instack[t]=false;
            gro_num[id]++;
            if(t==s)break;
        }
    }
    return;
}

void solve(){
    memset(instack,0,sizeof(instack));
    memset(towhere,-1,sizeof(towhere));
    memset(gro_num,0,sizeof(gro_num));
    memset(dfn,0,sizeof(dfn));
    Dindex=0;
    id=0;
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjan(i);
        }
    }
}

int ms[maxn];
int c[maxn];

int main(){
    int i,j,k;
    int q,h;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d",&str[i]);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&q,&h);
            add(q,h);
        }
        solve();

//        printf("---%d\n",id);
        memset(ms,inf,sizeof ms);
        for(int i=1;i<=n;i++){
            int to = towhere[i];
            int tmp = str[i];
            if(tmp<ms[to]){
                ms[to]=tmp;
                c[to]=1;
            }else if(tmp==ms[to]){
                c[to]++;
            }
        }
        LL ans=1;
        LL mm=0;
        for(int i=1;i<=id;i++){
            mm+=(LL)ms[i];
            ans*=(LL)c[i];
            ans%=mod;
        }
        printf("%lld %lld\n",mm,ans);
    }
    return 0;
}
