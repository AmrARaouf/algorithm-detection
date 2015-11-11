//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <functional>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <queue>
#include <time.h>
#include <list>

#define forn(iii,sss,nnn) for(ll iii=sss;iii<nnn;++iii)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pl(aa) cout << aa << endl;
#define ps(aa) cout << aa << ' ';
#define show(aa) forn(iii,0,aa.size()) { ps(aa[iii]); } cout << endl;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MAX = 10000000000000000LL;
const ll MOD = 1e9+7;
const ld EPS = 1e-5;
const ld PI = 3.14159265358979323846;

map<pair<int,int>,int> m;
vector<vector<int> > g;
set<int> ans;
vector<int> used;
void dfs(int v, bool need)
{
    used[v] = 1;
    if (g[v].size() == 1 && need)
    {
        ans.insert(v);
    }

    int c = ans.size();
    forn(i,0,g[v].size())
    {
        if(!used[g[v][i]])
        {
            bool nd = false;
            if (m[mp(g[v][i],v)] == 2)
            {
                nd = true;
                need = false;
            }
            dfs(g[v][i], nd);
        }
    }
    if(c == ans.size() && need)
        ans.insert(v);
}

bool comp(const int &a, const int &b)
{
    return g[a].size() > g[b].size();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

     int n;
     cin >> n;
     g.resize(n, vector<int>());
     used.resize(n,0);
     forn(i,0,n-1)
     {
         int x,y,t;
         cin >> x >> y >> t;
         x--,y--;
         g[x].pb(y);
         g[y].pb(x);
         m[mp(x,y)] = t;
         m[mp(y,x)] = t;
     }
     forn(i,0,n)
     {
         sort(g[i].begin(), g[i].end(), comp);
     }

     dfs(0, false);
     cout << ans.size() << endl;
     for(set<int>::iterator i = ans.begin(); i!=ans.end();++i)
     {
         cout << *i+1 << ' ';
     }
    return 0;

}














