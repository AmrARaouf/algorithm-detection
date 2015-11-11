//Language: GNU C++0x


#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <functional>
#include <bitset>
#include <deque>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> pii;

#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define FORD(i, x, y) for (ll i = x; i >= y; --i)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REPD(i, n) for(ll i = n - 1; i >= 0; --i) 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQ(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define SZ(c) (int)(c).size()
#define CONTAINS(s,obj) (s.find(obj)!=s.end())

#define CLEAR(x) memset(x,0,sizeof x)
#define COPY(from,to) memcpy(to, from, sizeof to)

#define sq(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

const double eps = 1.0e-11;
const double pi = acos(-1.0);
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string d[550];
bool used[550][550];
vector<pair<char, pii> > res;

void dfs(int x, int y, int root = true) {
  used[x][y] = true;
  res.push_back(mp('B', mp(x, y)));

  REP(dir, 4) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny] && d[nx][ny] == '.') dfs(nx, ny, false);
  }

  if (!root) {
    res.push_back(mp('D', mp(x, y)));
    res.push_back(mp('R', mp(x, y)));
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  REP(i, n) cin >> d[i];

  REP(i, n) REP(j, m) {
    if (d[i][j] == '.' && !used[i][j]) dfs(i, j);
  }

  cout << SZ(res) << endl;
  for (auto x : res) cout << x.X << " " << x.Y.X + 1 << " " << x.Y.Y + 1 << "\n";
  return 0;
}