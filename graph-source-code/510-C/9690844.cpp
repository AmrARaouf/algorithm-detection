//Language: GNU C++0x


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <deque>
#include <cassert>
#include <algorithm>

using namespace std;

bool g[256][256]={0};
bool vis[256] = {0};
deque<int> top;

void dfs(int u)
{
    vis[u]=true;
    for (int i='z'; i>='a'; i--)
    {
        if (u==i) continue;
        if (!g[u][i]) continue;
        if (vis[i]) continue;
        dfs(i);
    }
    top.push_front(u);
}

int main()
{
    int n;
    cin>>n;
    vector<string> d(n);
    int mx=0;
    for (int i=0; i<n; i++)
    {
        cin>>d[i];
        mx = max(mx,(int)d[i].size());
    }

    bool imp = false;
    for (int i=0; i<n; i++)
    {
        //for (int j=i+1; j<n; j++)
        int j=i+1;
        if (j<n)
        {
            bool found = false;
            for (int k=0; k<min(d[i].size(),d[j].size()); k++)
            {
                if (d[i][k]==d[j][k]) continue;
                g[d[i][k]][d[j][k]] = true;
                found = true;
                break;
            }
            if (!found && d[i].size()>d[j].size())
            {
                imp=true;
                break;
            }
        }
    }

    /*for (int i='a'; i<='z'; i++)
    {
        //cout<<(char)i<<"==>>"<<endl;
        //for (int j='a'; j<='z'; j++) if(g[i][j]) cout<<(char)j;cout<<endl;
    }*/

    bool fw [256][256] = {0};
    for (int k='a'; k<='z'; k++)
    {
        if (imp) break;
        for (int i='a'; i<='z'; i++)
        {
            for (int j='a'; j<='z'; j++)
            {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }

    for (int i='a'; i<='z'; i++)
    {
        if (imp) break;
        for (int j='a'; j<='z'; j++)
        {
            if (g[i][j] && g[j][i])
            {
                imp = true;
                break;
            }
        }
        if (imp) break;
    }

    if (imp)
    {
        cout<<"Impossible"<<endl;
    }
    else
    {
        for (int i='z'; i>='a'; i--)
        {
            if (vis[i]) continue;
            dfs(i);
        }

        assert(top.size()==26);
        for (int i=0; i<top.size(); i++)
        {
            cout<<(char)top[i];
        }
        cout<<endl;
    }

    return 0;
}
