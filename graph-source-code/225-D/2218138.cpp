//Language: GNU C++


#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int NUM = 14745601;
int dist[NUM];

struct P {
  int y, x;
  string s;
  P() {}
  P(int y, int x, const string &s) : y(y),x(x),s(s) {}
  int encode() {
    int res = y*15+x;
    REP(i,s.size()) {
      res = res*4 + (s[i]-'0');
    }
    return res;
  }
};

bool hoge[20][20];
bool check(const string &s) {
  map<pii, bool> mp;
  int y = 10;
  int x = 10;
  hoge[y][x] = 1;
  bool f = 1;
  REP(i,s.size()) {
    y += dy[s[i]-'0'];
    x += dx[s[i]-'0'];
    if (hoge[y][x]) f = 0;
    hoge[y][x] = 1;
  }
  y = 10;
  x = 10;
  REP(i,s.size()) {
    y += dy[s[i]-'0'];
    x += dx[s[i]-'0'];
    hoge[y][x] = 0;
  }
  return f;
}

char ba[15][15];

bool visi[15][15];
int main() {
  int n,m;
  cin >> n >> m;
  REP(i,n) REP(j,m) cin >> ba[i][j];
  P start;
  REP(i,n) {
    REP(j,m) {
      if (ba[i][j] == '1') {
        start.y = i;
        start.x = j;
        queue<pii> Q;
        Q.push(pii(i,j));
        while(!Q.empty()) {
          pii p = Q.front(); Q.pop();
          int y = p.first;
          int x = p.second;
          REP(k,4) {
            int yy = y+dy[k];
            int xx = x+dx[k];
            if (yy<0||yy>=n||xx<0||xx>=m) continue;
            if (visi[yy][xx]) continue;
            if (ba[yy][xx] == ba[y][x] + 1) {
              start.s += '0'+k;
              Q.push(pii(yy,xx));
            }
          }
        }
      }
    }
  }
  queue<P> Q;
  Q.push(start);
  memset(dist,-1,sizeof(dist));
  dist[start.encode()] = 0;
  int ans = -1;
  while(!Q.empty()) {
    P now = Q.front(); Q.pop();
    int y = now.y;
    int x = now.x;
    int d = dist[now.encode()];
    if (ba[y][x] == '@') {
      ans = d;
      break;
    }
    string t = now.s.substr(0,now.s.size()-1);
    REP(k,4) {
      int yy = y + dy[k];
      int xx = x + dx[k];
      if (yy<0||yy>=n||xx<0||xx>=m) continue;
      if (ba[yy][xx] == '#') continue;
      P next;
      next.y = yy;
      next.x = xx;
      next.s = string(1,'0'+(k+2)%4) + t;
      if (!check(next.s)) continue;
      int enc = next.encode();
      assert(enc<NUM);
      if (dist[enc] == -1) {
        dist[enc] = d + 1;
        Q.push(next);
      }
    }
  }
  cout << ans << endl;
}
