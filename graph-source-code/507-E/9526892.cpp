//Language: GNU C++0x


#include <iostream>
#include <bitset>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
#include <utility>
#include <ctype.h>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <fstream>
#include <deque>
#include <functional>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define TRAV(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

const int MAXN = 100005;
const int INF = 1001001001;

vector< vector< pair<int,int> > > pov;
vector< vector< pair<int,int> > > pov_rev;

int n,m;

int dist[MAXN], X[MAXN], Y[MAXN], Z[MAXN];
int nxt[MAXN];
int val[MAXN];
bool was[MAXN];

int main()
{
    //freopen("test.txt", "r", stdin);

    cin >> n >> m;
    int x,y,z;

    pov.resize(n+5);
    pov_rev.resize(n+5);
    FOR(i,m) {
        cin >> x >> y >> z;
        pov[x].push_back( make_pair(y,z) );
        pov[y].push_back( make_pair(x,z) );
    }

    for(int i=1; i<=n; i++) {
        dist[i] = INF;
        val[i] = INF;
    }
    dist[1] = 0;
    val[n] = 0;

    //cout << "-" << endl;

    queue<int> Q;
    Q.push(1);
    while(!Q.empty()) {
        x = Q.front();
        Q.pop();
        TRAV(pov[x], it) {
            int v = it->first;
            if(dist[v] == INF) {
                dist[v] = dist[x] + 1;
                Q.push(v);
            }
        }
    }
    //cout << "-" << endl;

    priority_queue<pair<int,int> > A;
    A.push( make_pair(0,n) );
    while(!A.empty()) {
        int d = A.top().first;
        x = A.top().second;
        A.pop();
        if(d != val[x]) continue;

        TRAV(pov[x], it) {
            int v = it->first;
            int r = it->second;
            if(dist[v]+1 != dist[x]) continue;

            int cost = val[x]+(r==0);
            if(cost < val[v]) {
                val[v] = cost;
                nxt[v] = x;
                A.push( make_pair(val[v], v) );
            }
        }
    }

    //cout << "-" << endl;

    //for(int i=1; i<=n; i++)
    //    cout << i << " -> " << dist[i] << " " << nxt[i] << endl;

    set< pair<int,int> > visited;
    int p = 1;
    while(p != n) {
        int v = nxt[p];

        int a = v;
        int b = p;
        if(a > b) swap(a,b);
        visited.insert( make_pair(a, b) );

        p = v;
    }
    p = 0;
    for(int i=1; i<=n; i++) {
        TRAV(pov[i], it) {
            int v = it->first;
            int r = it->second;

            if(v < i) continue;

            if(visited.count( make_pair(i, v) )) {
                if(r == 0) {
                    X[p] = i;
                    Y[p] = v;
                    Z[p++] = 1-r;
                }
            } else {
                if(r == 1) {
                    X[p] = i;
                    Y[p] = v;
                    Z[p++] = 1-r;
                }
             }
        }
    }

    cout << p << endl;
    FOR(i,p) cout << X[i] << " " << Y[i] << " " << Z[i] << endl;

    return 0;
}

