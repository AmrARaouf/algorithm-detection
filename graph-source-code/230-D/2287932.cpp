//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits.h>

using namespace std;

#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SIZE(v) (int)v.size()
typedef long long ll;
typedef pair<ll,int> PII;

const ll INF=(1ll<<50);

int n,m;
vector< pair<int,int> > adj[100001];
map<int,int>::iterator it;
set<ll> ts[100001];
ll dis[100001];

priority_queue<PII> q;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(MP(b,c));
        adj[b].push_back(MP(a,c));
    }
    for(int i=1;i<=n;++i)
    {
        int k; scanf("%d",&k);
        for(int j=0;j<k;++j) {
            ll t; scanf("%I64d",&t);
            ts[i].insert(t);
        }
    }
    for(int i=1;i<=n;++i) dis[i]=INF;
    dis[1]=0;
    q.push(MP(-dis[1],1));

    while(!q.empty())
    {
        int v=q.top().second; 
        ll t=-(q.top().first);
        q.pop();

        while(ts[v].find(t)!=ts[v].end()) t++;

        for(int i=0;i<adj[v].size();++i)
        {
            int u=adj[v][i].first;
            ll d=t+adj[v][i].second;

            if(dis[u]>d) {
                dis[u]=d;
                q.push(MP(-dis[u],u));
            }
        }
    }

    if(dis[n]==INF) printf("-1");
    else printf("%I64d",dis[n]);

    return 0;
}