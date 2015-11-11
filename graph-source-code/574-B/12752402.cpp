//Language: GNU C++11


#include <bits/stdc++.h>
//#define int long long
using namespace std;
vector<int> v[10002];
int x[10001], y[10001];
bool used[4001][4001];
main()
{
    int n, m, i, j;
    cin >> n >> m;
    for(i = 1; i <= m; i ++)
    {
        cin >> x[i] >> y[i];
        if(x[i] > y[i])
            swap(x[i], y[i]);
        used[x[i]][y[i]] = 1;
        used[y[i]][x[i]] = 1;
        v[x[i]].push_back(y[i]);
        v[y[i]].push_back(x[i]);
    }
    int ans = 1e7;
    for(i = 1; i <= m; i ++)
    {
        for(j = i + 1; j <= m; j ++)
        {
            if(x[i] == x[j] && used[y[i]][y[j]])
                ans = min(ans, (int)v[x[i]].size() + (int)v[y[j]].size() + (int)v[y[i]].size() - 6);
            if(x[i] == y[j] && used[y[i]][x[j]])
                ans = min(ans, (int)v[x[i]].size() + (int)v[x[j]].size() + (int)v[y[i]].size() - 6);
            if(x[j] == y[i] && used[y[j]][x[i]])
                ans = min(ans, (int)v[x[i]].size() + (int)v[x[j]].size() + (int)v[y[j]].size() - 6);
            if(y[i] == x[j] && used[x[i]][y[j]])
                ans = min(ans, (int)v[x[i]].size() + (int)v[x[j]].size() + (int)v[y[j]].size() - 6);
        }
    }
    if(ans < 0)
        ans = 0;
    if(ans == 1e7)
        ans = -1;
    cout << ans;
}
