//Language: GNU C++


//In the name of God
#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair < int , int > pii;

const int maxn = 100 * 1000 + 10;
bool mark[maxn];
vector< int > v[maxn];
bool ok = false;
int d[maxn];
vector< pii >edge;

inline int dfs( int id )
{
    mark[id]=1;
    int ret = d[id];
    for(int i=0;i<v[id].size();++i) {
        int x = v[id][i];
        if( mark[x] == 0 )  {
            d[x]=d[id]+1;
            ret = min( ret , dfs(x) );
            edge.pb( pii(id,x) );
        }
        else
            if(d[x]!=d[id]-1)
                ret = min( ret , d[x] );
    }
    for(int i=0;i<v[id].size();++i) {
        int x = v[id][i];
        if(d[x]!=d[id]+1 && d[x]>d[id])
            edge.pb(pii(x,id));
    }
    if( ret >= d[id] && d[id] != 0 )
        ok = true;
    return ret ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n , m ;
    cin >> n >> m ;
    while( m --> 0 )
    {
        int fi , se;
        cin >> fi >> se ;
        v[fi].pb(se);
        v[se].pb(fi);
    }

    int t = dfs( 1 );

    if( ok )    {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0 ;i<edge.size();++i)   {
        cout << edge[i].F << ' ' << edge[i].S << endl;
    }

    return 0;
}
