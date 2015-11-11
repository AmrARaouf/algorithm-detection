//Language: GNU C++


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct state {
  int x, y, t;
  vector<vector<char> > b;
  state(int x, int y, int t, vector<vector<char> > b) : x(x), y(y), t(t), b(b) {}
};

typedef pair<int, int> pii;

int main() {
  vector<vector<char> > B(8, vector<char> (8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      B[i][j] = cin.get();
    }
    cin.get(); // \n
  }
  
  bool vis[8][8][8*8];
  memset(vis, false, sizeof(vis));

  string win = "LOSE";
  queue<state> bfs;
  bfs.push(state(7, 0, 0, B));
  int x, y, t, nx, ny, nt;
  vector<vector<char> > b, nb;
  while (!bfs.empty()) {
    x = bfs.front().x;
    y = bfs.front().y;
    t = bfs.front().t;
    b = bfs.front().b;
    bfs.pop();

    if (vis[x][y][t]) continue;
    vis[x][y][t] = true;

    if (b[x][y] == 'A') {
      win = "WIN";
      break;
    }

    nb = b;
    for (int i = 7; i >= 0; i--) {
      for (int j = 0; j < 8; j++) {
	if (b[i][j] == 'S') {
	  nb[i][j] = '.';
	  if (i < 7) nb[i+1][j] = 'S';
	}
      }
    }

    nt = t + 1;

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
	nx = x + i;
	ny = y + j;
	if (nx >= 0 && nx < 8 &&
	    ny >= 0 && ny < 8 &&
	    b[nx][ny] != 'S' &&
	    nb[nx][ny] != 'S' &&
	    !vis[nx][ny][nt]) {
	  bfs.push(state(nx, ny, nt, nb));
	}
      }
    }
  }
  cout << win << endl;
}
