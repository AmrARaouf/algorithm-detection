//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define ull long long

int n, r1, r2;

vector<int> g;
vector<vector<int> > gr;
vector<int> used;
vector<int> neww;

void dfs(int u)
{
//    cout << "in " << u << endl;
    used[u] = 1;
    for(int v = 0; v < gr[u].size(); ++v)
        if(!used[gr[u][v]])
        {
            neww[gr[u][v]] = u;
            dfs(gr[u][v]);
        }
//    cout << "out " << u << endl;
};


int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);

    cin >> n >> r1 >> r2;
    used.resize(n+1, 0);
    neww.resize(n+1, 0);
    gr.resize(n+1);

    g.resize(n+1);
    for(int i = 1; i <= n; ++i)
    {
        if(i == r1)
            g[i] = 0;
        else
        {
            cin >> g[i];
            gr[i].push_back(g[i]);
            gr[g[i]].push_back(i);
        }
    }

//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 0; j < gr[i].size(); ++j)
//        {
//            cout << gr[i][j] << ' ';
//        }
//        cout << endl;
//    }

    dfs(r2);

    for(int i = 1; i <= n; ++i)
    {
        if(i != r2)
        {
            cout << neww[i] << ' ';
        }
    }

    return 0;
}
