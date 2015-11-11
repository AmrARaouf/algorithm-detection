//Language: GNU C++


#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <iomanip>

using namespace std;

#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).size())
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define rep(i,n) FOR(i,0,n)
#define ford(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ll long long
#define VI vector<int>
#define mp make_pair
#define pii pair<int,int>
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

struct tripple
{
    int a, b, c;

    tripple(int _a=0, int _b=0, int _c=0)
    {
        a=_a; b=_b; c=_c;
    }
};

bool operator == (const tripple &x, const tripple &y)
{
    return x.a==y.a && x.b==y.b && x.c == y.c;
}

bool operator != (const tripple &x, const tripple &y)
{
    return !(x==y);
}

int cmp(const tripple &x, const tripple &y)
{
    if(x.a < y.a) return 1;
    if(x.a==y.a && x.b < y.b) return 1;
    if(x.a == y.a && x.b==y.b && x.c < y.c) return 1;
    return 0;
}

bool operator < (const tripple &x, const tripple &y)
{
    return cmp(x,y);
}

ostream& operator<<(ostream &out, const tripple &x)
{
    out << x.a << ' ' << x.b << ' ' << x.c;
    return out;
}

VI e[3000];
map< pii, pii > prev;

int main()
{
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w+", stdout);

    for(int i = 0; i < 3000; ++i)
        e[i].resize(0);

    int n,m,k;

    cin >> n >> m >> k;

    rep(i,m)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        e[x].pb(y);
        e[y].pb(x);
    }

    vector<tripple> K;

    rep(i,k)
    {
        tripple x;
        cin >> x.a >> x.b >> x.c;
        --x.a, --x.b, --x.c;
        K.pb(x);
    }

    sort(all(K), cmp);
    K.erase(unique(all(K)),K.end());

    set<tripple> trpl(all(K));

    queue < pii > q;
    tripple tr;

    for(int i = 0; i < L(e[0]); ++i)
    {
        q.push(mp(0,e[0][i]));
        prev[mp(0,e[0][i])] = mp(-1,0);
    }

    pii lastEdge = mp(-1,-1);

    while(!q.empty())
    {
        pii edge = q.front();
        q.pop();

        //cout << "edge " << edge.X << ' ' << edge.Y << endl;

        if(edge.Y == n-1)
        {
            lastEdge = edge;
            break;
        }  // we have found end point

        for(int i = 0; i < L(e[edge.Y]); ++i)
        {
            tr.a = edge.X, tr.b = edge.Y, tr.c = e[edge.Y][i];

            //vector<tripple>::iterator iter = lower_bound(all(K), tr,cmp);
            //bool isNotForbiden = iter == K.end() || *iter != tr;
            bool isNotForbiden = trpl.find(tr) == trpl.end();

            if(isNotForbiden)
            {
                pii next = mp(edge.Y, e[edge.Y][i]);
                if(prev.find(next) == prev.end())
                {
                    q.push(next);
                    prev[next] = edge;
                }
            }
        }
    }

    if(lastEdge.X==-1)
    {
        cout << -1 << endl;
    }
    else
    {
        VI ans;
        int dist=0;
        for(; lastEdge.X != -1; lastEdge = prev[lastEdge])
        {
            //cout << "res edge " << lastEdge.X +1 << ' ' << lastEdge.Y+1 << endl;
            ++dist;
            ans.pb(lastEdge.Y);
        }
        cout << dist << endl;

        reverse(all(ans));
        cout << 1 ;
        for(int i = 0; i < L(ans); ++i)
            cout << " " << ans[i]+1;
        cout << endl;
    }

    return 0;
}
