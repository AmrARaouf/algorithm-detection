//Language: GNU C++


#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;


#define onlylove "My Sky"
#define mysky "TT"

#define X first
#define Y second
#define Size(A) int(A.size())

typedef long long ll;
typedef pair<int , int> pt;

const int maxv = 256*256+256;
int n;
string str;
bool added[maxv];
int deg_in[maxv] , deg_out[maxv] , start , finish , tour[maxv] , time;
vector<int> V;
multiset<int> B[maxv];

void dfs(int u)
{
    while (!B[u].empty())
    {
        multiset<int>::iterator it;
        it = B[u].begin();
        int v = *it;
        B[u].erase(it);
        dfs(v);

    }
    tour[++time] = u;
}

int main()
{
    std ::ios::sync_with_stdio(false);
    //freopen("input.inp","r",stdin);

    memset(added,false , sizeof(added));

    cin >> n;
    for (int i=1;i<=n;++i)
    {
        cin >> str;
        int v1 = (str[0]*255 + str[1]);
        int v2 = (str[1]*255 + str[2]);
        if (!added[v1])
        {
            V.push_back(v1);
            added[v1] =true;
        }
        if (!added[v2])
        {
            V.push_back(v2);
            added[v2] =true;
        }
        B[v1].insert(v2);
       // int u = v1 , v = v2;
      //   cout << char(u / 255) << char(u%255) << " " << char(v / 255) << char(v %255) << "\n";
        deg_in[v2]++;
        deg_out[v1]++;
    }
    if (Size(V) == 1)
    {
        bool ok = (str.substr(0,2) == str.substr(1,3));
        if (ok)
        {
            cout << "YES" << "\n";
            cout << str;
            for (int i=2;i<=n;++i)
                cout << str[2];
            return 0;
        } else
        {
            cout << "NO\n";
            return 0;
        }
    }
    int cnt = 0;
    for (int i=0;i<V.size();++i)
    {
        if (cnt > 2)
        {
            cout << "NO\n";
            return 0;
        }
        int u = V[i];
        if (deg_in[u] - deg_out[u] == 1)
        {
            cnt++;
            finish = u;
        } else
        if (deg_in[u] - deg_out[u] == -1)
        {
            cnt++;
            start = u;
        } else
        if (deg_in[u] != deg_out[u])
        {
                cout << "NO\n";
                return 0;
        }
    }
    time = 0;
    if (cnt == 0) start = V[1];
    //cout << char(start / 255) << char(start % 255) << "\n";
    dfs(start);
    //cout << time << endl;
    if (time != n+1)
    {
        cout << "NO\n";return 0;
    }
    //cout << tour[time] << endl;
    cout << "YES\n";
    cout << char(tour[time] / 255) << char(tour[time]%255);
    for (int i=time-1;i>=1;--i)
    {
        cout << char(tour[i] % 255);
    }

    return 0;
}
