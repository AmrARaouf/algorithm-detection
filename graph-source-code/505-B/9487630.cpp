//Language: GNU C++


#include<iostream>
#include<vector>
#include<utility>
#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int, int> >connection[200];
int n, m;
bool v[200];
using namespace std;
void dfs(int s, int c)
{
    if (v[s])
        return;
    v[s] = true;
    for (int i = 0; i < connection[s].size(); i++)
    if (connection[s][i].second == c)
        dfs(connection[s][i].first, c);
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        x--;
        y--;
        connection[x].push_back(make_pair(y, t));
        connection[y].push_back(make_pair(x, t));
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        s--;
        e--;
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int i = 0; i < n; i++)
                v[i] = false;
            dfs(s, i);
            count = count + v[e];
        }
        printf("%d\n", count);
    }
    return 0;
}