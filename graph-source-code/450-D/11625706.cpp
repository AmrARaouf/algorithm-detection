//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,int>
#define pii pair<int,ll>
#define mp make_pair
#define pb push_back
#define s second
#define f first
vector< pair<int,ll> >adj[100011];
ll dist[100011];
int u1[100011]={0};
ll w1[100011];
vector< pii >tr;
void dijkstra (int V, int s)
{
    for(int i=0;i<=V+1;i++)
        dist[i]=1000000000000000000LL;
    dist[s] = 0;
    priority_queue < ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0LL, s));
    while(!pq.empty())
    {
        ii front = pq.top();
        pq.pop();
        ll d = front.first;
        int u = front.second;
        if (dist[u] == d)
        {
            for (int i = 0; i < adj[u].size(); i++)
            {
                pii v = adj[u][i];
                v.second=abs(v.second);
                if (dist[u] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }

            }
        }
    }
}
int main()
{
    int n,m,k,i,j,u,v;
    ll w;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %lld",&u,&v,&w);
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    int ans=0;
    for(i=1;i<=n;i++)
        w1[i]=1000000000000000000LL;
    for(i=0;i<k;i++)
    {
        scanf("%d %lld",&u,&w);
        adj[1].pb(mp(u,(w)));
        adj[u].pb(mp(1,(w)));
        tr.pb(mp(u,w));
    }
    dijkstra(n,1);
//    for(i=1;i<=n;i++)
//        printf("%lld ",dist[i]);
//    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
            if(abs(adj[i][j].s)+dist[adj[i][j].f]==dist[i])
                u1[i]++;
    }
    for(i=0;i<tr.size();i++)
    {
        if((tr[i].s==dist[tr[i].f]&&u1[tr[i].f]>1))
            u1[tr[i].f]--,ans++;
        if(dist[tr[i].f]<tr[i].s)
            ans++;
        //printf("%d %d %lld\n",ans,tr[i].f,tr[i].s);
    }
    printf("%d\n",ans);
    return 0;
}
