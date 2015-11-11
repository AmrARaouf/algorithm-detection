//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

const int maxn = 600, maxm = 10010;

struct state
{
    int first, sec;
    bool lastM;
    state(int f = 0, int s = 0, bool l = 0)
    {
        first = f;
        sec = s;
        lastM = l;
    }
};

int n, m;
vector <int> nei[maxn], one, two;
queue <state> que;
int dis[maxn][maxn][2];
bool mark[maxn][maxn][2];
state par[maxn][maxn][2];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
}

void bfs()
{
    state first(0, n - 1, 1);
    que.push(first);
    mark[0][n - 1][1] = true;
    while (!que.empty())
    {
        state u = que.front();
        //cerr << u.first << " " << u.sec << " " << u.lastM << endl;
        que.pop();
        if (u.lastM == 1)
            for (int i = 0; i < (int)nei[u.first].size(); i++)
            {
                int uu = nei[u.first][i];
                if (!mark[uu][u.sec][0])
                {
                    dis[uu][u.sec][0] = dis[u.first][u.sec][1];
                    mark[uu][u.sec][0] = true;
                    state v(uu, u.sec, 0);
                    par[uu][u.sec][0] = u;
                    que.push(v);        
                }
            }
        else
            for (int i = 0; i < (int)nei[u.sec].size(); i++)
            {
                int uu = nei[u.sec][i];
                if (uu == u.first)
                    continue;
                if (!mark[u.first][uu][1])
                {
                    dis[u.first][uu][1] = dis[u.first][u.sec][0] + 1;
                    mark[u.first][uu][1] = true;
                    state v(u.first, uu, 1);
                    par[u.first][uu][1] = u;
                    que.push(v);
                }
            }
    }
}

void find_path(int ans)
{
    one.push_back(n - 1);
    two.push_back(0);
    int a = n - 1, b = 0;
    for (int i = 0; i < ans; i++)
    {
        state gh = par[a][b][1];
        b = gh.sec;
        gh = par[a][b][0];
        a = gh.first;
        one.push_back(a);
        two.push_back(b);
    }
}

void output()
{
    if (!mark[n - 1][0][1])
        cout << "-1" << endl;
    else
    {
        int ans = dis[n - 1][0][1];
        find_path(ans);
        cout << ans << endl;
        for (int i = one.size() - 1; i >= 0; i--)
            cout << one[i] + 1 << " ";
        cout << endl;
        for (int i = two.size() - 1; i >= 0; i--)
            cout << two[i] + 1 << " ";
        cout << endl;   
    }   
}

int main()
{
    input();
    bfs();
    output();
    return 0;
}
