//Language: MS C++


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <stack>

using namespace std;

vector < vector < int > > v;
vector < set < int > > vp;

int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    vp.resize ( n );
    for ( int i = 0; i < m; i++ )
    {
        int fr,to;
        cin >> fr >> to;
        fr--; to--;
        vp[fr].insert ( to );
        vp[to].insert ( fr );
    }
    int cnt = 0;
    while ( 1 )
    {
        bitset < 100 > bs;
        for ( int i = 0; i < n; i++ )
            if ( vp[i].size() == 1 )
                bs.set ( i );
        if ( !bs.count() )
            break;
        for ( int i = 0; i < n; i++ )
            if ( vp[i].size() == 1 ) 
                vp[i].clear();
            else if ( vp[i].size() )
            {
                for ( int j = 0; j < n; j++ ) 
                    if ( bs[j] && vp[i].find ( j ) != vp[i].end() )
                        vp[i].erase ( j );
            }
        cnt++;
    }
    cout << cnt;

    return 0;
}