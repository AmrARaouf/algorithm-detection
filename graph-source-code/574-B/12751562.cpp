//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cstdio>
#include <cmath>
#include <iterator>
using namespace std;

#define in cin
#define out cout

#define REP(i,n) for(int i=0; i<n; i++)
#define REPE(i,s,e) for(int i=s; i<=e; i++)
#define REPV(i,s,e) for(int i=s; i>=e; i--)

#define all(v) v.begin(), v.end()
#define pb push_back
#define isin(a,b,c) ((a)<=(c)&&(c)<=(b))
#define maxn(a,b) ((a)>(b)?(a):(b))
#define minn(a,b) ((a)<(b)?(a):(b))

#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>

#define X first
#define Y second

vector<int> k[4444];
int mp[4444][4444];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, m; in >> n >> m;
    vector<pii> v(m);
    REP(i,m)
    {
        in >> v[i].X >> v[i].Y;
        mp[v[i].X][v[i].Y] = 1;
        mp[v[i].Y][v[i].X] = 1;
        k[v[i].X].push_back(v[i].Y);
        k[v[i].Y].push_back(v[i].X);
    }

    int res = 1e9;
    for(int i=1; i<=n; i++)
    {
        if(k[i].size() >= 2)
        {
            for(int j=0; j<k[i].size(); j++)
            {
                for(int m=j+1; m<k[i].size(); m++)
                {
                    if(mp[k[i][j]][k[i][m]] == 0) continue;
                    int s = k[k[i][j]].size() + k[k[i][m]].size() + k[i].size() - 6;
                    if(s < res) res = s;
                }
            }
        }
        else
        {
            continue;
        }

    }

    if(res == 1e9) out << -1 << endl;
    else out << res << endl;


    return 0;
}
