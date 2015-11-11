//Language: GNU C++


#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

#define MAXN 200005

int first[MAXN], next[MAXN], u[MAXN], v[MAXN], w[MAXN], edgeidx;
int n, m;
int dist[MAXN];
int cnt[MAXN];
bool vis[MAXN];
int pre[MAXN];

struct cmp
{
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

void addedge(int a, int b, int c)
{
    u[edgeidx] = a;
    v[edgeidx] = b;
    w[edgeidx] = c;
    
    next[edgeidx] = first[a];
    first[a] = edgeidx++;
}

void dij()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    dist[1] = 0;
    q.push(make_pair(0, 1));
    while(!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        int d = p.first;
        int idx = p.second;
        if(vis[idx])
            continue;
        vis[idx] = true;
        
        for(int i = first[idx]; i != -1; i = next[i])
        {
            if(dist[v[i]] > dist[idx] + 1)
            {
                cnt[v[i]] = cnt[idx] + w[i];
                pre[v[i]] = i;
                dist[v[i]] = dist[idx] + 1;
                q.push(make_pair(dist[v[i]], v[i]));
            }
            else if(dist[v[i]] == dist[idx] + 1)
            {
                if(cnt[v[i]] < cnt[idx] + w[i])
                {
                    cnt[v[i]] = cnt[idx] + w[i];
                    pre[v[i]] = i;
                }
            }
        }
    }
    return;
}

int main()
{
    memset(first, -1, sizeof(first));
    memset(dist, 0x3f, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    edgeidx = 0;
    cin>>n>>m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin>>a>>b>>c;
        addedge(a, b, c);
        addedge(b, a, c);
    }
    
    dij();
    
    memset(vis, false, sizeof(vis));
    int edge = pre[n];
    while(edge != -1)
    {
        vis[edge] = true;
        vis[edge^1] = true;
        edge = pre[u[edge]];
    }
    
    vector<int> ansa, ansb, ansc;
    for(int i = 0; i < edgeidx; i+=2)
    {
        if(vis[i] && w[i] == 0)
        {
            ansa.push_back(u[i]);
            ansb.push_back(v[i]);
            ansc.push_back(1);
        }
        
        if(!vis[i] && w[i] == 1)
        {
            ansa.push_back(u[i]);
            ansb.push_back(v[i]);
            ansc.push_back(0);
        }
    }
    
    cout<<ansa.size()<<endl;
    for(int i = 0; i < ansa.size(); ++i)
    {
        cout<<ansa[i]<<" "<<ansb[i]<<" "<<ansc[i]<<endl;
    }
    return 0;
}