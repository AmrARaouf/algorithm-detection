//Language: GNU C++0x


#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int LIM = 501;

enum class color {
  RED, BLUE, WHITE, BLACK
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
color a[LIM][LIM];
char g[LIM][LIM];
bool used[LIM][LIM];
vector< tuple<char, int, int> > ans;

void dfs(int x, int y, bool p = false) {
  used[x][y] = true;
  for (int k = 0; k < 4; ++k) {
    int x1 = x + dx[k], y1 = y + dy[k];
    if (x1 < 0 || y1 < 0 || x1 == n || y1 == m)
      continue;
    if (used[x1][y1])
      continue;
    if (a[x1][y1] == color::BLACK)
      continue;
    dfs(x1, y1, true);
  }
  if (p) {
    ans.push_back(make_tuple('D', x + 1, y + 1));
    ans.push_back(make_tuple('R', x + 1, y + 1));
    a[x][y] = color::RED;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> g[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (g[i][j] == '#') {
        a[i][j] = color::BLACK;
      } else {
        ans.push_back(make_tuple('B', i + 1, j + 1));
        a[i][j] = color::BLUE;
      }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] != color::BLACK && !used[i][j])
        dfs(i, j);
  cout << ans.size() << '\n';
  for (auto t : ans)
    cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
#ifdef LOCAL
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (g[i][j] == '#')
        cout << g[i][j];
      else if (a[i][j] == color::RED)
        cout << 'R';
      else
        cout << 'B';
    }
    cout << '\n';
  }
#endif
  return 0;
}
