//Language: GNU C++


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <queue>

#define FOR(a,b,c) for(long long a = (b); a < (c); a++)
#define FORE(a,b,c) for(long long a = (b); a <= (c); a++)
#define FORD(a,b,c) for(long long a = (b); a > (c); a--)
#define FE(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)
#define REP(a,b) FOR(a,0,b)
#define REPE(a,b) FORE(a,1,b)
#define SZ(c) ((int) c.size())
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

const double eps = 1e-9;
const double pi = 2*acos((double) 0);

int ncity, nedge, dist[505][505], ans[505][505], road[505];
vii adj[505];

int main() {
  ios_base::sync_with_stdio(0);

  int nx, ny, nval;

  cin >> ncity >> nedge;

  REPE(i,ncity) {
    REPE(k,ncity) {
      dist[i][k] = 1e9;
    }

    dist[i][i] = 0;
    adj[i].clear();
  }

  REP(i,nedge) {
    cin >> nx >> ny >> nval;
    adj[nx].push_back(make_pair(ny, nval));
    adj[ny].push_back(make_pair(nx, nval));

    dist[nx][ny] = dist[ny][nx] = nval;
  }

  REPE(m, ncity) REPE(i, ncity) REPE(k, ncity)
    dist[i][k] = min(dist[i][k], dist[i][m] + dist[m][k]);

  REPE(k, ncity) {
    REPE(i, ncity) {
      road[i] = 0;
      FE(it, adj[i]) {
        int adjCity = it->first, adjCost = it->second;
        if(dist[i][k] == adjCost + dist[adjCity][k]) road[i]++;
      }
    }

    FORE(i, 1, k) {
      ans[i][k] = 0;
      REPE(m, ncity) {
        if(dist[i][m] + dist[m][k] == dist[i][k]) ans[i][k] += road[m];
      }
    }
  }

  REPE(i, ncity) FORE(k, i+1, ncity) cout << ans[i][k] << " ";
  cout << endl;

  return 0;
}










