//Language: GNU C++


///sadiosajfirejgewgrlekgkjewglkrhekghrtkhklrtkhjlrkejhkrejhkjrehkjrekhj
///wfuehfuiwhfuhewuhgiuhewiughewuhgiewu
#include<bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

long long int  wqeqw, b, h, d[299999], s, x, y, wer[300011], INF = 999999999999999999ll, p[300011], ans,i,j;

vector < pair < long long int , pair < long long int, long long int > > > qwe[300011];

set < pair < long long int, long long int > > q;


int main()
{
    scanf("%I64d%I64d", &wqeqw, &b);

    for( i = 1; i <= b; i++ ){

        scanf("%I64d%I64d%I64d", &x, &y, &wer[i]);

        qwe[x].pb(mp(i, mp(y, wer[i])));

        qwe[y].pb(mp(i, mp(x, wer[i])));

    }
    scanf("%I64d", &s);

    for( i = 1; i <= wqeqw; i++ )d[i] = INF;

    d[s] = 0;

    q.insert(mp(d[s], s));

    while( !q.empty() ){

        int x1 = q.begin()->se;

        q.erase(q.begin());

        for( i = 0; i < qwe[x1].size(); i++ ){

            long long int to = qwe[x1][i].se.fi, len = qwe[x1][i].se.se;

            if( d[x1] + len < d[to] || d[x1] + len == d[to] && wer[p[to]] > wer[qwe[x1][i].fi] ){

                q.erase( mp(d[to], to) );

                ans -= wer[p[to]];

                d[to] = d[x1] + len;

                p[to] = qwe[x1][i].fi;

                ans += wer[p[to]];

                q.insert( mp(d[to], to) );

            }

        }

    }

    pr( "%I64d\n", ans );

    for( i = 1; i <= wqeqw; i++ ){

        if( i != s )pr( "%I64d ", p[i] );

    }
    return 0;
}


