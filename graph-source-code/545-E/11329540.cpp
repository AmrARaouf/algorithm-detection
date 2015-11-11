//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define maxi 1e15
struct edge
{
    int start;
    int end;
    int weight;
    int index;
} edge[2*300010];
int n,m,a,b,c,cnt=0;
int head[300010],visited[300010],parent[300010],yo[300010];
long long sum[300010];
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
    {
        sum[i]=maxi;
        visited[i]=0;
    }
    queue<int> q;
    q.push(s);
    sum[s]=0;
    visited[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        visited[u]=0;
        q.pop();
        for(int i=head[u];~i;i=edge[i].start)
        {
            int v=edge[i].end;
            int wt=edge[i].weight;
            if(sum[u]+wt<sum[v])
            {
                sum[v]=sum[u]+wt;
                parent[v]=edge[i].index;
                if(!visited[v])
                {
                    visited[v]=1;
                    q.push(v);
                }
            }
            else if(sum[u]+wt==sum[v]&&wt<yo[parent[v]])
            {
                parent[v]=edge[i].index;
                if(!visited[v])
                {
                    visited[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    memset(visited,0,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        yo[i]=c;
        edge[cnt].weight=c;
        edge[cnt].start=head[a];
        edge[cnt].end=b;
        edge[cnt].index=i;
        head[a]=cnt++;
        edge[cnt].weight=c;
        edge[cnt].start=head[b];
        edge[cnt].end=a;
        edge[cnt].index=i;
        head[b]=cnt++;  
    }
    scanf("%d",&a);
    dijkstra(a);
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(parent[i]>0) ans=ans+yo[parent[i]];
    printf("%I64d\n",ans);
    for(int i=1;i<=n;i++)
        if(parent[i]>0) printf("%d ",parent[i]);
    printf("\n");
    return 0;
}
