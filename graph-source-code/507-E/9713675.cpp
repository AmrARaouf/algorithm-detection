//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))

using namespace std;

struct edge
{
    int to;
    bool s;

    edge(int y, bool z)
    {
        to = y, s = z;
    }
};

vector<vector<edge > > graph(100005);
int D1[100005], DN[100005], MaxOp[100005], parent[100005], path[100005];
int from[100005], to[100005];
bool opened[100005], visited[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, counter = 0;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> from[i] >> to[i] >> opened[i];
        graph[from[i]].pb(edge(to[i], opened[i]));
        graph[to[i]].pb(edge(from[i], opened[i]));
        counter+=opened[i];
    }
    setdp(D1);
    setdp(DN);
    setdp(MaxOp);
    queue<int> q;
    q.push(1);
    D1[1] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++)
        {
            edge e = graph[node][i];
            if(D1[e.to] != -1) continue;
            D1[e.to] = D1[node] + 1;
            q.push(e.to);
        }
    }
    q.push(n);
    DN[n] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++)
        {
            edge e = graph[node][i];
            if(DN[e.to] != -1) continue;
            DN[e.to] = DN[node] + 1;
            q.push(e.to);
        }
    }
    int d = D1[n];
    q.push(1);
    MaxOp[1] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(visited[node]) continue;
        visited[node] = true;
        for(int i=0;i<graph[node].size();i++)
        {
            edge e = graph[node][i];
            if(D1[e.to] + DN[e.to] != d || D1[node] + 1 + DN[e.to] != d || visited[e.to]) continue;
            if(MaxOp[e.to] != -1 && MaxOp[e.to] >= MaxOp[node] + e.s) continue;
            q.push(e.to);
            parent[e.to] = node;
            MaxOp[e.to] = MaxOp[node] + e.s;
        }
    }
    int node = n;
    while(node != 1)
    {
        path[node] = parent[node];
        node = path[node];
    }
    cout << counter + d - 2 * MaxOp[n] << '\n';
    for(int i=0;i<m;i++)
    {
        if(path[from[i]] == to[i] || path[to[i]] == from[i])
        {
            if(!opened[i]) cout << from[i] << " " << to[i] << " 1" << '\n';
        }
        else if(opened[i]) cout << from[i] << " " << to[i] << " 0" << '\n';
    }
    return 0;
}
