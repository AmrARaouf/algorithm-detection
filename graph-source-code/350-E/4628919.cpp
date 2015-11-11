//Language: GNU C++


#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)
 
int a[500];
int is_marked[500];
char conn[500][500];

int main() {
    int n, m, k;
    
    cin >> n >> m >> k;
    
    memset(is_marked, 0, sizeof(is_marked));
    memset(conn, 0, sizeof(conn));
    
    REP(i,k) { cin >> a[i]; is_marked[a[i]] = 1; }
    
    int n_unmarked = n-k, maxedges = (n-1)*(n-2)/2+n_unmarked;
    
    if (m > maxedges || n_unmarked == 0) cout << -1 << endl;
    else {
        int outnode = a[0], first = outnode==1?2:1, next;
        REP (i,n-2) {
            next = first+1;
            if (next == outnode) ++next;
            cout << first << " " << next << endl;
            conn[first][next] = conn[next][first] = 1;
            --m; first = next; 
        }
        REP(i,n) if (i+1 != outnode && is_marked[i+1] == 0 && m > 0){
            cout << outnode << " " << i+1 << endl;
            conn[i+1][outnode] = conn[outnode][i+1] = 1;
            --m;
        }
        
        REP(i,n) if (i+1 != outnode) {
            FOR(j,i+1,n) if (j+1 != outnode) {
                if (m <= 0) goto out;
                if (conn[i+1][j+1] == 0) {
                    conn[i+1][j+1] = conn[j+1][i+1] = 1;
                    cout << j+1 << " " << i+1 << endl;
                    --m;
                }
            }
        }
        out:;
    }


    return 0;
} 