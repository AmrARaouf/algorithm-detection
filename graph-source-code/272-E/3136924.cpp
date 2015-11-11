//Language: MS C++


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX INT_MAX
#define MIN INT_MIN
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define ll long long

const int maxN = 3 * 100000;
bool color[maxN];
vector<int> g[maxN];

void dfs(int i)
{

}

int main()
{
    int n,m;
    cin>>n>>m;

    FOR(i,m)
    {
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    queue<int> q;
    vector<int> t;
    FOR(i,n)
    {
        int c = 0;
        FOR(j,g[i].size())
        {
            if(color[i] == color[g[i][j]]) c++;
        }

        if(c > 1)
        {
            q.push(i);
            t.push_back(i);
        }
    }

    while(!q.empty())
    {
        int v = q.front(), c = 0;
        q.pop();

        FOR(i,g[v].size())
        {
            if(color[v] == color[g[v][i]]) c++;
        }

        if(c > 1)
        {
            color[v] = !color[v];   
            FOR(i,g[v].size())
            {
                if(color[v] == color[g[v][i]])
                    q.push(g[v][i]);
            }
        }       
    }

    FOR(i,n)
    {
        cout<<color[i];
    }

    return 0;
}