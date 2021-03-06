//Language: MS C++


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF (1<<29)

int X,Y,K;
int x[10],y[10];
int a[110][110];
int dp[110][110][(1<<7)],path[110][110][(1<<7)][3]; // 0: shortest path, 1: dp
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
string ans[110];

void shortest(int mask){
    int iter,i,j,k;
    
    REP(iter,X*Y){
        REP(i,X) REP(j,Y) REP(k,4){
            int x2 = i + dx[k], y2 = j + dy[k];
            if(x2 >= 0 && x2 < X && y2 >= 0 && y2 < Y){
                int tmp = dp[i][j][mask] + a[x2][y2];
                if(tmp < dp[x2][y2][mask]){
                    dp[x2][y2][mask] = tmp;
                    path[x2][y2][mask][0] = 0;
                    path[x2][y2][mask][1] = i;
                    path[x2][y2][mask][2] = j;
                }
            }
        }
    }
}

void print(int x2, int y2, int mask){
    ans[x2][y2] = 'X';
    if(path[x2][y2][mask][0] == 0) print(path[x2][y2][mask][1], path[x2][y2][mask][2], mask);
    if(path[x2][y2][mask][0] == 1){
        print(x2, y2, path[x2][y2][mask][1]);
        print(x2, y2, path[x2][y2][mask][2]);
    }
}

int main(void){
    int i,j,k,mask;
    
    cin >> X >> Y >> K;
    REP(i,X) REP(j,Y) cin >> a[i][j];
    REP(i,K) {cin >> x[i] >> y[i]; x[i]--; y[i]--;}
    
    REP(i,X) REP(j,Y) REP(mask,(1<<K)) dp[i][j][mask] = INF;
    REP(i,K){
        dp[x[i]][y[i]][(1<<i)] = a[x[i]][y[i]];
        path[x[i]][y[i]][(1<<i)][0] = 2;
    }
    
    REP(mask,(1<<K)){
        REP(i,X) REP(j,Y){
            int mask2;
            for(mask2=mask;mask2>0;mask2=(mask&(mask2-1))){
                int tmp = dp[i][j][mask2] + dp[i][j][mask^mask2] - a[i][j];
                if(tmp < dp[i][j][mask]){
                    dp[i][j][mask] = tmp;
                    path[i][j][mask][0] = 1;
                    path[i][j][mask][1] = mask2;
                    path[i][j][mask][2] = (mask^mask2);
                }
            }
        }
        shortest(mask);
    }
    
    int best = INF;
    REP(i,X) REP(j,Y) best = min(best,dp[i][j][(1<<K)-1]);
    cout << best << endl;
    
    REP(i,X) REP(j,Y) ans[i] += '.';
    REP(i,X) REP(j,Y) if(dp[i][j][(1<<K)-1] == best){
        print(i,j,(1<<K)-1);
        REP(k,X) cout << ans[k] << endl;
        return 0;
    }
    
    return 0;
}

