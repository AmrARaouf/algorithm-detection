//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

typedef pair<int,int> pii;
const int MN=1000+10;
vector<pair<int,int> > GG[MN];
vector<pair<int,int> > G[MN];
long long dis[MN];
set<pii> A;
long long INF=(long long)1e14;
int n;

inline void update(int v)
{
     for(int i=0;i<(int)G[v].size();i++)
     {
        int u=G[v][i].first;
        int w=G[v][i].second;
        if(dis[v]+w < dis[u])
        {
           A.erase(pii(dis[u],u));
           dis[u]=dis[v]+w;
           A.insert(pii(dis[u],u));
        }
     }
}

inline void update2(int v)
{
     for(int i=0;i<(int)GG[v].size();i++)
     {
        int u=GG[v][i].first;
        int w=GG[v][i].second;
        if(dis[v]+w < dis[u])
        {
           A.erase(pii(dis[u],u));
           dis[u]=dis[v]+w;
           A.insert(pii(dis[u],u));
        }
     }
}

inline void dij(int st)
{
     for(int i=1;i<=n;i++)
        dis[i]=INF;
     dis[st]=0;
     A.clear();
     for(int i=1;i<=n;i++)
        A.insert(pii(dis[i],i));
     while(!A.empty())
     {
        int v=A.begin()->second;
        A.erase(pii(dis[v],v));
        update(v);
     }
}

inline void dij2(int st)
{
     for(int i=1;i<=n;i++)
        dis[i]=INF;
     dis[st]=0;
     A.clear();
     for(int i=1;i<=n;i++)
        A.insert(pii(dis[i],i));
     while(!A.empty())
     {
        int v=A.begin()->second;
        A.erase(pii(dis[v],v));
        update2(v);
     }
}

int main()
{
    int m;
    int x,y;
    cin>>n>>m;
    cin>>x>>y;
    while(m--)
    {
       int u,v,w;
       cin>>u>>v>>w;
       GG[u].push_back(pii(v,w));
       GG[v].push_back(pii(u,w));
    }
    for(int i=1;i<=n;i++)
    {
       int t,c;
       cin>>t>>c;
       dij2(i);
       for(int j=1;j<=n;j++)
          if(dis[j]<=t)
             G[i].push_back(pii(j,c));
    }
    dij(x);
    if(dis[y]>=INF)
       cout<<-1<<endl;
    else
       cout<<dis[y]<<endl;
    return 0;
}
