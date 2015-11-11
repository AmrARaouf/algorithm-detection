//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int Maxn=210,INF=0x3f3f3f3f;
struct Edge
{
    int to,next;
    Edge(){}
    Edge(int to,int next):
    to(to),next(next){}
}edge[Maxn*Maxn];
int box[Maxn],size;
void add(int from,int to)
{
    edge[size]=Edge(to,box[from]);
    box[from]=size++;
}
int n,m;
int dp1[Maxn],dp2[Maxn];
int que[Maxn];
double cnt1[Maxn];
double cnt2[Maxn];
void bfs(int s,int dp[],double cnt[])
{
    memset(dp,INF,(n+1)*sizeof(int));
    int in=0,out=0;
    que[in++]=s;
    cnt[s]=1;
    dp[s]=0;
    while(in>out)
    {
        int x=que[out++];
        for(int i=box[x];i!=-1;i=edge[i].next)
        {
            int x1=edge[i].to;
            if(dp[x1]>dp[x]+1)
            {
                dp[x1]=dp[x]+1;
                que[in++]=x1;
                cnt[x1]=cnt[x];
            }
            else if(dp[x1]==dp[x]+1)
            {
                cnt[x1]+=cnt[x];
            }
        }
    }
}

int main()
{
   // freopen("in.txt","r", stdin);
    scanf("%d%d",&n,&m);
    memset(box,-1,sizeof(box));size=0;
    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
    }
    bfs(1,dp1,cnt1);
    bfs(n,dp2,cnt2);
    double ans=0;
    for(int i=2;i<n;++i)
    {
        if(dp1[i]+dp2[i]!=dp1[n])continue;
        if(ans<cnt1[i]/cnt1[n]*cnt2[i])ans=cnt1[i]/cnt1[n]*cnt2[i];
    }
    printf("%.12f\n",max(1.0,ans*2));
    return 0;
}
