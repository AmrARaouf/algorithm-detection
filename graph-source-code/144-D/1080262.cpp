//Language: GNU C++


#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fs first
#define sc second
#define sz(x) (int((x).size()))
#define all(x) ((x).begin()),((x).end())
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define fab(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fba(i,b,a) for(int (i)=(b);(i)>=(a);(i)--)
#define MAX(a,x) a=max(a,x)
#define MIN(a,x) a=min(a,x)

using namespace std;

const double eps = 1e-10, inf = 1e10;
typedef long long ll;

int n, m, s, dd[100010], L, ans = 0;
vector< pair<int,int> > adj[100010];
vector< pair< int, pair<int,int> > > archi;
priority_queue< pair<int,int> > q;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    scanf("%d%d%d", &n, &m, &s);
    int a, b, c;
    rep(i, m)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
        archi.pb(mp(c,mp(a,b)));
    }
    scanf("%d", &L);

    fab(u, 1, n) dd[u] = numeric_limits<int>::max();

    dd[s] = 0;
    q.push(mp(0, s));
    while (!q.empty())
    {
        pair<int,int> t = q.top();
        q.pop();
        int u = t.sc, w = -t.fs, v;
        if (w > dd[u]) continue;
        rep(i, sz(adj[u]))
        {
            v = adj[u][i].fs;
            if (dd[v] > dd[u] + adj[u][i].sc)
            {
                dd[v] = dd[u] + adj[u][i].sc;
                q.push(mp(-dd[v], v));
            }
        }
    }

    fab(u, 1, n) if (dd[u] == L) ans ++;

    rep(i, sz(archi))
    {
        int u = archi[i].sc.fs, v = archi[i].sc.sc, w = archi[i].fs;
        int rem1, rem2;
        // aa
        if (L > dd[u])
        {
            rem1 = w - L + dd[u];
            if (rem1 > 0)
            {
                rem1 = L - dd[u];
                rem2 = w - rem1;
                if (rem1 + dd[u] <= rem2 + dd[v])
                {
                    ans ++;
                }
            }
        }
        // bb
        if (L > dd[v])
        {
            rem2 = w - L + dd[v];
            if (rem2 > 0)
            {
                rem2 = L - dd[v];
                rem1 = w - rem2;
                if (rem2 + dd[v] < rem1 + dd[u])
                {
                    ans ++;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
