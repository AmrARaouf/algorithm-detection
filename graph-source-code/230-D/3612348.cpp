//Language: GNU C++


#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 100000000000000
typedef long long ll;
typedef pair<int,int> p;

int n,m;
vector< vector< p > > g;
vector< vector< ll > > k;
vector< ll > d;

struct compar
{
    bool operator ()(int v1, int v2) const
    {
        if(d[v1] != d[v2]) return d[v1] < d[v2];
        else    return v1 < v2;
    }
};

ll Dijkstra() {
    int s=0, f=n-1;
    set<int, compar> q; 
    FOR(i,n) q.insert(i);
    
    while(!q.empty()) {
        int v=*q.begin();
        q.erase(q.begin());

        if(v==f) continue;
        
        vector<ll>::iterator it=lower_bound(k[v].begin(), k[v].end(),d[v]);
        while(it!=k[v].end() && *it == d[v]) 
            d[v]++, ++it;

        FOR(i,g[v].size()) {
            int to=g[v][i].first, c=g[v][i].second;
            set<int,compar>::iterator tmp(q.find(to));
            if(tmp==q.end()) continue;
            
            if(d[v] + c < d[to] ) {
                q.erase(tmp);
                d[to]=d[v]+c;
                q.insert(to);
            }
        }
    }
    return (d[f]==INF ? -1 : d[f]);
}

int main()
{
#ifndef ONLINE_JUDGE 
    freopen("test.txt","r",stdin);
#endif
    scanf("%d %d",&n,&m);
    g.resize(n), d.assign(n,INF);
    FOR(i,m) {
        int a,b,c; scanf("%d %d %d",&a,&b,&c);
        a--,b--;
        g[a].push_back(p(b,c));
        g[b].push_back(p(a,c));
    }
    k.resize(n);
    FOR(i,n) {
        int s; scanf("%d",&s);
        FOR(j,s) {
            ll t; scanf("%I64d",&t);
            k[i].push_back(t);
        }
    }
    d[0]=0;
    printf("%I64d",Dijkstra());
    return 0;
}