//Language: GNU C++11


#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> b;
    vector<bool> a[4000];
    int c[4000];
    for (int i = 0; i < n; ++i)
    {
        a[i].resize(n, false);
        c[i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        b.push_back(make_pair(x, y));
        a[x][y] = true;
        a[y][x] = true;
        c[x]++;
        c[y]++;
    }
    int mm = -1;
    for (auto x : b) // перебираем корневую пару
    {
        for (int i = 0; i < n; ++i)
        {
            int cc = 0;
            if (a[x.first][i] && a[x.second][i])
            {
                cc += c[x.first] - 2;
                cc += c[x.second] - 2;
                cc += c[i] - 2;
                if ((cc < mm) || (mm == -1))
                {
                    mm = cc;
                }
            }
        }
    }
    cout << mm;
    return 0;
}