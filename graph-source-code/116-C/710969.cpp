//Language: MS C++


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

vector< vector<int> > g;

vector<int> mas;

int dfs(int n)
{
    int res = 0;
    for(int i = 0; i < g[n].size(); ++i)
    {
        res = max(res, dfs(g[n][i]));
    }
    return res + 1;
}

int main()
{
    int n;
    cin >> n;
    
    mas.resize(n);
    g.resize(n, vector<int>());

    for(int i = 0; i < n; ++i)
    {
        cin >> mas[i];
        if(mas[i]!=-1)
        {
            mas[i]--;
        }
    }
    
    for(int i=0; i<n; ++i)
    {
        if(mas[i] != -1)
        {
            g[mas[i]].push_back(i);
        }
    }

    int res=0;
    for(int i=0; i<n; ++i)
    {
        if(mas[i] == -1)
        {
            res = max(res, dfs(i));
        }
    }

    cout << res << endl;


    return 0;
}