//Language: GNU C++


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i,n) for(i=0;i<n;++i)
#define Max 3001
vector<int> a[Max];
int d[Max][Max];
int n, e;
int z[2][3];
int main()
{
    int i, j;
    int x, y;
    cin >> n >> e;
    rep(i, e)
    {
        cin >> x >> y;
        x--; y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int t;
    rep(i, 2)rep(j, 3)
    {
        cin >> z[i][j];
        if(j!=2)z[i][j]--;
    }
    /*rep(i, 2)
    {
        rep(j, 3)
            cout << z[i][j] << " ";
        cout << endl;
    }*/
    rep(i, n)rep(j, n)d[i][j] = Max;
    rep(i, n)
    {
        d[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            t = q.front();
            q.pop();
            int s = a[t].size();
            rep(j, s)
            {
                if (d[i][t] + 1 < d[i][a[t][j]])
                {
                    d[i][a[t][j]] = d[i][t] + 1;
                    q.push(a[t][j]);
                }
            }
        }
    }
    /*rep(i,n)
    {
        rep(j, n)
            cout << d[i][j] << " ";
        cout << endl;
    }*/
    int l, r;
    int mn = Max + 2;
    int k;
    rep(k, 2)
    {
        swap(z[0][0], z[0][1]);
        rep(i, n)rep(j, n)
        {
            l = d[ z[0][0] ][i] + d[i][j] + d[j][ z[0][1] ];
            r = d[ z[1][0] ][i] + d[i][j] + d[j][ z[1][1] ];
            if (l <= z[0][2] && r <= z[1][2])
            {
                if (l + r - d[i][j]<mn)mn = l + r - d[i][j];
            }
        }
    }
    l = d[z[0][0]][z[0][1]];
    r = d[z[1][0]][z[1][1]];
    if (l<=z[0][2] && r<=z[1][2])
    if (l + r<mn)mn = l + r;
    cout << (mn<Max?e-mn:-1) << endl;
    return 0;
}