//Language: GNU C++


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 210
#define inf 2100000000
using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 210
#define inf 2100000000
using namespace std;
struct edge
{
    int to;
    int next;
}e[50010];
int box[maxn],cnt;
void init(){
    memset(box,-1,sizeof(box));
    cnt=0;
}
void add(int from,int to){
    e[cnt].to=to;
    e[cnt].next=box[from];
    box[from]=cnt++;
}
int pre[maxn],low[maxn],stack[maxn],sc[maxn];
int cnt0,cnt1,top;
void dfs(int now){
    int v,mi,t;
    mi=pre[now]=low[now]=++cnt0;
    stack[top++]=now;
    for(t=box[now];t!=-1;t=e[t].next){
        v=e[t].to;
        if(!pre[v])dfs(v);
        mi=min(mi,low[v]);
    }
    if(mi<low[now]){
        low[now]=mi;
        return ;
    }
    do{
        sc[(v=stack[--top])]=cnt1;
        low[v]=inf;
    }while(stack[top]!=now);
    cnt1++;
}
int tarjan(int n){
    top=cnt0=cnt1=0;
    memset(sc,-1,sizeof(sc));
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    if(!pre[i])
    dfs(i);
    return cnt1;//返回强连通分量数
}
bool map[maxn][maxn];
int in[maxn],sf[maxn],vis[maxn];
void rebuild(int n){//反向建图
    for(int i=1;i<=2*n;i++){
        for(int t=box[i];t+1;t=e[t].next){
            int v=e[t].to;
            if(sc[v]!=sc[i]&&!map[sc[v]][sc[i]]){
                map[sc[v]][sc[i]]=true;
                in[sc[i]]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        sf[sc[i]]=sc[i+n];
        sf[sc[i+n]]=sc[i];
    }
}
void topsort(){//拓扑排序求解
    top=0;//变量重用 在Tarjan和topsort中重复利用
    memset(vis,0,sizeof(vis));
    for(int i=0;i<cnt1;i++)
    if(!in[i])
    stack[++top]=i;//在Tarjan和topsort中重复利用
    while(top){
        int x = stack[top--];
		if(!vis[x]){
			vis[x]=1;
			vis[sf[x]]=2;
		}
		for(int i=0;i<cnt1;++i)
			if(map[x][i]){
				if(!--in[i])
				stack[++top]=i;
			}
    }
}
int ans[maxn],sum;
void printans(int n)
{
    int sum=0,i;
    for(i=1+n;i<=2*n;i++)
    {
        if(vis[sc[i]]==1)
        {
           ans[++sum]=i-n;
        }
    }
    printf("%d\n",sum);
    for(i=1;i<=sum;i++)
    printf("%d ",ans[i]);
    printf("\n");
}
int main()
{
 //  freopen("dd.txt","r",stdin);
   int n,m,i,j,a,b,c;
   scanf("%d%d",&n,&m);
    init();
   for(i=1;i<=m;i++)
   {
       scanf("%d%d%d",&a,&b,&c);
       if(c==0)
       {
           add(a,b+n);
           add(b+n,a);
           add(b,a+n);
           add(a+n,b);
       }
       else
       {
           add(a,b);
           add(b,a);
           add(a+n,b+n);
           add(b+n,a+n);
       }
   }
   int num=tarjan(n*2);
   for(i=1;i<=n;i++)
   {
       if(sc[i]==sc[i+n])
       {
           printf("Impossible\n");
           return 0;
       }
   }
   rebuild(n);
   topsort();
   printans(n);
   return 0;
}
