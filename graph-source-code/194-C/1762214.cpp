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
#include <assert.h>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define rep(i,n) FOR(i,0,n)
#define ford(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

char b[55][55];
bool used[55][55];
int timer = 0;
int tin[55][55];
int fup[55][55];
int n,m;

bool is_cut_point;
int children;

void dfs(int x, int y, int px = -1, int py = -1)
{
  used[x][y] = true;
  tin[x][y] = fup[x][y] = timer ++;

  for (int dx = -1; dx < 2; ++dx)
    for (int dy = -1; dy < 2; ++dy) {
      if (dx*dx+dy*dy==1) {
        const int xx = x + dx, yy = y + dy;

        if (xx<0 || yy<0 || xx>=n || yy>=m) {
          continue;
        }

        if (b[xx][yy] != '#') {
          continue;
        }

        if (xx==x && yy==y) {
          continue;
        }

        if (used[xx][yy]) {
          fup[x][y] = min(fup[x][y], tin[xx][yy]);
        }
        else {
          dfs(xx, yy, x, y);
          fup[x][y] = min(fup[x][y], fup[xx][yy]);
          if (fup[xx][yy] >= tin[x][y] && px != -1) {
            is_cut_point = true;
          }
          if(px == -1) {
            children ++;
          }
        }
      }
    }

  if (px == -1 && children > 1) {
    is_cut_point = true;
  }
}

int main()
{
#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif


    cin >> n >> m;
    rep(i,n) rep(j,m) cin >> b[i][j];

    int cell = 0;
    rep(i,n) rep(j,m) if(b[i][j]=='#') cell ++;

    if(cell <= 2)
    {
        cout << -1 << endl;
        return 0;
    }

    int startx = -1, starty = -1;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (b[i][j] == '#') {
          startx = i, starty = j;
          break;
        }

    memset(used, 0, sizeof(used));
    memset(tin, 0, sizeof(tin));
    memset(fup, 0, sizeof(fup));
    children = 0;
    is_cut_point = false;
    timer = 0;
    dfs(startx, starty);

    cout << (is_cut_point ? 1 : 2) << endl;

    return 0;
}
