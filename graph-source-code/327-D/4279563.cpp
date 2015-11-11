//Language: GNU C++


#include <cstdio>
#define rep(i,n) for(int _n=n,i=0;i<_n;++i)
char grid[500][501];
int n, m, moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, nc, nr, res;

void dfs(int r, int c, int first, int counting) {
  if (counting) res += 1; else
    printf("B %d %d\n", r + 1, c + 1);
  grid[r][c] = 'C';
  rep(i, 4) {
    nr = r + moves[i][0];
    nc = c + moves[i][1];
    if (nr < 0 || nr >= n) continue;
    if (nc < 0 || nc >= m) continue;
    if (grid[nr][nc] != '.') continue;
    dfs(nr, nc, 0, counting);
  }
  if (!first) {
    if (counting) res += 2; else {
      printf("D %d %d\n", r + 1, c + 1);
      printf("R %d %d\n", r + 1, c + 1);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  rep(i, n) scanf("%s", grid[i]);
  rep(i, n) rep(j, m)
    if (grid[i][j] == '.')
      dfs(i, j, 1, 1);
  rep(i, n) rep(j, m)
    if (grid[i][j] == 'C') grid[i][j] = '.';
  printf("%d\n", res);  
  rep(i, n) rep(j, m)
    if (grid[i][j] == '.')
      dfs(i, j, 1, 0);
  return 0;
}
