//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long n , m;

vector < int > v[100005];

void read (){
    cin >> n >> m;
    int x1 , x2;
    for ( int i = 0; i < m; ++i ) {
        scanf ( "%d%d", &x1 , &x2 );
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }
}

long long used[100005], cnt, ans, cnt1 , cnt2;

void dfs ( int node , int st ) {
    used[node] = st;
    if ( st % 2 == 1 ) cnt1 ++;
    else cnt2 ++;
    long long sz = v[node].size(), num = 0;
    for ( int i = 0; i < sz; ++i ) {
        int u = v[node][i];
        if ( used[u] ) {
            if ( (int)abs(used[u] - st-1) % 2 == 1 && (int)abs(used[u] - st-1) > 1 && st > used[u]) {
                cnt++;
            }
        } else {
            dfs ( u , st+1);
        }
    }

}

void solve () {

    for ( int i = 1; i <= n; ++i )
        if ( !used[i] ){dfs(i,1);
        //cout << cnt1 << ' ' << cnt2 << endl;
        if ( cnt1 + cnt2 > 2 ){
            ans += cnt1*(cnt1-1)/2;
            ans += cnt2*(cnt2-1)/2;
        }
        cnt1 = 0; cnt2 = 0;
    }
    if ( cnt ) {
        cout << 0 << ' ' << 1 << endl;
        return;
    }

    if ( ans ) {
        cout << 1 << ' ' << ans << endl;
    }

    else {
        if ( m == 0 ) cout << 3 << ' ' << (long long)(n*(n-1)*(n-2)/6LL) << endl;
        else cout << 2 << ' ' << m * (n-2) << endl;
    }
}

void print () {
}

int main () {
    read ();
    solve ();
    print ();
}
