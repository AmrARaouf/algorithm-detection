//Language: GNU C++


#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

char A[2222][2222];
int D[2222][2222];
bool u[2222][2222];

void dfs(int x, int y, int len) {
  //cerr << x << " " << y << " " << len << endl;
  if (u[x][y]) return;
  u[x][y] = 1;
  if (A[x][y] == '#') return;
  D[x][y] = max(D[x][y],len);
  //if (A[x][y] == '>' || !u[x][y-1]) return dfs(x,y-1,len+1);
  //if (A[x][y] == 'v' || !u[x-1][y]) return dfs(x-1,y,len+1);
  //if (A[x][y] == '<' || !u[x][y+1]) return dfs(x,y+1,len+1);
  //if (A[x][y] == '^' || !u[x+1][y]) return dfs(x+1,y,len+1);
  if (A[x][y-1] == '>' && !u[x][y-1]) dfs(x,y-1,len+1);
  if (A[x-1][y] == 'v' && !u[x-1][y]) dfs(x-1,y,len+1);
  if (A[x][y+1] == '<' && !u[x][y+1]) dfs(x,y+1,len+1);
  if (A[x+1][y] == '^' && !u[x+1][y]) dfs(x+1,y,len+1);
}

vector<pair<short,short> > path;
bool ook;

void dfs2(int x, int y) {
  if (A[x][y] == '#') return;
  path.push_back(make_pair(x,y));
  if (A[x][y] == '>') return dfs2(x,y+1);
  if (A[x][y] == 'v') return dfs2(x+1,y);
  if (A[x][y] == '<') return dfs2(x,y-1);
  if (A[x][y] == '^') return dfs2(x-1,y);
}

void dfs3(int x, int y, int tt) {
  if (A[x][y] == '#') return;
  if (path[tt].first == x && path[tt].second == y) {
    ook = false;
    return;
  }
  if (A[x][y] == '>') return dfs3(x,y+1,tt+1);
  if (A[x][y] == 'v') return dfs3(x+1,y,tt+1);
  if (A[x][y] == '<') return dfs3(x,y-1,tt+1);
  if (A[x][y] == '^') return dfs3(x-1,y,tt+1);
}

bool comp(pair<int,int> a, pair<int,int> b) {
  return D[a.first][a.second] > D[b.first][b.second];
}

int main(void) {
  int n,m;
  int ans = 0;
  vector<pair<short,short> > V;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      A[i][j] = s[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] != '#') {
        V.push_back(make_pair(i,j));
        if (A[i][j] == '>' && A[i][j+1] != '#') continue;
        if (A[i][j] == 'v' && A[i+1][j] != '#') continue;
        if (A[i][j] == '<' && A[i][j-1] != '#') continue;
        if (A[i][j] == '^' && A[i-1][j] != '#') continue;
        dfs(i,j,1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] != '#' && !u[i][j]) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
  if (V.size() == 0) {
    cout << "0" << endl;
    return 0;
  }
  sort(V.begin(),V.end(),comp);
  //cerr << V.size() << endl;
  int dd = D[V[0].first][V[0].second];
  //cerr << dd << endl;
  if (dd > 1) {
    ans = max(ans,dd*2-1);
  } else {
    if (dd == 0) {
      cout << "0" << endl;
      return 0;
    } else {
      if (V.size() > 1 && D[V[1].first][V[1].second] == 1) {
        cout << "2" << endl;
      } else {
        cout << "0" << endl;
      }
      return 0;
    }
  }
  for (int i = 0; i < (int)V.size(); i++) {
    int x = V[i].first, y = V[i].second;
    if (D[x][y] < dd) break;
    path.clear();
    dfs2(x,y);
    for (int j = i+1; j < (int)V.size(); j++) {
      int x2 = V[j].first, y2 = V[j].second;
      if (D[x2][y2] < dd) break;
      ook = true;
      dfs3(x2,y2,0);
      if (ook) {
        cout << dd*2 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  TIMESTAMP;
  return 0;
}
