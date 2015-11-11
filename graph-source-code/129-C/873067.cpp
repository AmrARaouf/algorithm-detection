//Language: MS C++


#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector< int > VI;
typedef vector< string > VS;
typedef pair< int, int > II;
typedef long long LL;
#define FOR(i,b,e) for(int (i)=(int)(b);(i)<(int)(e);++(i))
#define FORIT(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define INF 987654321

int di[] = {-1,-1,0,1,1,1,0,-1,0};
int dj[] = {0,1,1,1,0,-1,-1,-1,0};
int vis[8][8][1000];
VS grid;
vector< VS > changedGrid;

int win(int i, int j, int k)
{   
    if (changedGrid[k][i][j] == 'S') return 0;
    if (i == 0) return 1;
    if (k > 100) return 1;
    vis[i][j][k] = 1;   
    int ans = 0;
    FOR(s, 0, 9) {
        int i2 = i+di[s], j2 = j+dj[s];
        if (0 <= i2 && i2 < 8 && 0 <= j2 && j2 < 8 && vis[i2][j2][k+1] == 0) {
            if (k > 8) return 1;
            else if (changedGrid[k][i2][j2] != 'S') ans |= win(i2, j2, k+1);
        }
    }
    return ans;
}

int main()
{
    VS tmp(8);
    FOR(i, 0, 8)
        cin >> tmp[i];
    grid = tmp; 
    FOR(k, 0, 10) {
        VS tmp2(8, string(8, '.'));
        FOR(i, 0, 8)
            FOR(j, 0, 8)
                if (tmp[i][j] == 'S' && i+1 < 8) tmp2[i+1][j] = 'S';
        //FOR(p, 0, 8) { FOR(q, 0, 8) cout << tmp[p][q]; cout << endl; } cout << endl;
        changedGrid.push_back(tmp);
        tmp = tmp2;     
    }
    memset(vis, 0, sizeof(vis));
    int ans = win(7,0,0);
    cout << (ans == 1 ? "WIN" : "LOSE") << endl;
    return 0;
}