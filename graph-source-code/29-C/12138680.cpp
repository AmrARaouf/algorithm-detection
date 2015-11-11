//Language: GNU C++11


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <string.h>
using namespace std;

map<int, pair<int,int> > vals;
set<int> vis;

vector<int> out;
void dfs(int idx)
{
    vis.insert(idx);
    while (idx != 0)
    {
        out.push_back(idx);
        if (vals[idx].first != 0 && vis.count(vals[idx].first) == 0)
            idx = vals[idx].first;
        else if (vals[idx].second != 0 && vis.count(vals[idx].second) == 0)
            idx = vals[idx].second;
        else
            idx = 0;

        vis.insert(idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
#pragma warning (disable : 4996)
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (vals[a].first == 0)
            vals[a] = make_pair(b, 0);
        else
            vals[a] = make_pair(vals[a].first, b);

        if (vals[b].first == 0)
            vals[b] = make_pair(a, 0);
        else
            vals[b] = make_pair(vals[b].first, a);

        if (vis.count(a) == 0)
            vis.insert(a);
        else
            vis.erase(a);

        if (vis.count(b) == 0)
            vis.insert(b);
        else
            vis.erase(b);
    }

    int st = *vis.begin();
    vis.clear();
    dfs(st);
    
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << " ";
}