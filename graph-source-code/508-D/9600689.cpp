//Language: GNU C++


#include <bits/stdc++.h>

#define MAXN 200005
#define M 256

using namespace std;

int n, sinp[M][M], sout[M][M];
stack<pair<int, int> > a[M][M], st, res;

int main() {
  //freopen(NameTask".inp", "r", stdin);
  //freopen(NameTask".out", "w", stdout);
  ios_base :: sync_with_stdio(0);

  cin >> n;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    a[s[0]][s[1]].push(make_pair(s[1], s[2]));
    sinp[s[1]][s[2]]++;
    sout[s[0]][s[1]]++;
  }

  int c1 = 0;
  int c2 = 0;
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++) {
      if (abs(sinp[i][j] - sout[i][j]) > 1) {
        cout << "NO";
        return 0;
      }
      if (sinp[i][j] > sout[i][j]) c1++;
      if (sinp[i][j] < sout[i][j]) c2++;
    }

  if (c1 != c2 || c1 > 1) {
    cout << "NO";
    return 0;
  }

  int x, y, ok = 0;
  for (int i = 0; i < M && ok == 0; i++)
    for (int j = 0; j < M && ok == 0; j++)
      if (sinp[i][j] < sout[i][j] || (c2 == 0 && sinp[i][j] > 0)) {
        x = i;
        y = j;
        ok = 1;
      }

  st.push(make_pair(x, y));
  while (!st.empty()) {
    x = st.top().first;
    y = st.top().second;
    if (a[x][y].empty()) {
      res.push(st.top());
      st.pop();
    }
    else {
      st.push(a[x][y].top());
      a[x][y].pop();
    }
  }

  if (res.size() != n + 1)
    cout << "NO";
  else {
    cout << "YES\n" << char(res.top().first) << char(res.top().second);
    for (int i = 0; i < n; i++) {
      res.pop();
      cout << char(res.top().second);
    }
  }
}
