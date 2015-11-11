//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define LL long long
int n,m;
int f[100005];
void ini()
{
    for(int i=1;i<=n;i++)   f[i]=i;
}
int find(int x)
{
    if(x==f[x]) return x;
    else return f[x]=find(f[x]);
}
vector<int>g[100005];
vector<pair<int,int> >d;
vector<pair<int,int> >q;
int dep[100005];
int dp[100005][20];

void dfs(int root,int h)
{
    dep[root]=h;
    int t=0;
    while(dp[root][t])
    {
        dp[root][t+1]=dp[dp[root][t]][t];
        t++;
    }
    for(int i=0;i<g[root].size();i++)
    {
        int now=g[root][i];
        dp[now][0]=root;
        dfs(now,h+1);
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])   swap(u,v);
    for(int i=19;i>=0;i--)  if(dep[dp[u][i]]>=dep[v])   u=dp[u][i];
    if(u==v)    return u;
    for(int i=19;i>=0;i--)  if(dp[u][i]^dp[v][i])   u=dp[u][i],v=dp[v][i];
    return dp[u][0];
}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    ini();
    for(int i=0;i<m;i++)
    {
        int sign;
        scanf("%d",&sign);
        if(sign==1)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[b].push_back(a);
            int fa=find(a);
            int fb=find(b);
            f[fa]=fb;
        }
        else if(sign==2)
        {
            int a;
            scanf("%d",&a);
            int fa=find(a);
            d.push_back(make_pair(a,fa));
        }
        else
        {
            int a,b;
            scanf("%d%d",&a,&b);
            q.push_back(make_pair(a,b));
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]!=i) continue;
        dp[i][0]=0;
        dfs(i,1);
    }
    for(int i=0;i<q.size();i++)
    {
        int fidx=find(q[i].first);
        int now=q[i].second;
        int fidx2=find(d[now-1].first);
        if(fidx!=fidx2) printf("NO\n");
        else
        {
            if(lca(q[i].first,d[now-1].first)!=q[i].first)  printf("NO\n");
            else if(lca(q[i].first,d[now-1].second)!=d[now-1].second)   printf("NO\n");
            else printf("YES\n");
        }
    }
}

				 			 			 	  			  				 				