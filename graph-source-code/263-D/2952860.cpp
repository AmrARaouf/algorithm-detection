//Language: GNU C++


#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
  const int MaxN = (int)1e5 + 10;
  vector < int > v[MaxN];
  int k, ST, flag = 0; 
  int way[MaxN];
  bool used[MaxN]; 
void dfs(int vv, int L, int pred) {
  int i;
 // cout << vv << " " << L + 1 << endl;
  used[vv] = 1;
  way[vv] = L;
  for (i = 0; i<v[vv].size(); i++) {
    if (way[vv] - way[v[vv][i]] >= k && !flag && used[v[vv][i]]) {
      cout << way[vv] - way[v[vv][i]]+1 << endl;
      flag = v[vv][i];
      cout << v[vv][i] << " ";
      break;
    }   
    else 
      if (v[vv][i] != pred && !used[v[vv][i]]) {
        dfs(v[vv][i], L + 1, vv);
        if (flag > 0) { 
          if (flag == v[vv][i])
            flag = -1;
          else {
            cout << v[vv][i] << " ";
            break;
          }
        } 
      }
  }
  /*
    if (v[vv][i] != pred && !way[v[vv][i]]) {
      dfs(v[vv][i], L + 1, vv);
      if (flag > 0) { 
            if (flag == v[vv][i])
              flag = -1;
            else {
              cout << v[vv][i] << " ";
              break;
            }
          } 
    }
    */
  
}
int main() {
  int n, m, i, x, y;
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  scanf("%d%d%d\n", &n, &m, &k);
  for (i = 0; i<=n; i++) {
    v[i].clear();
    used[i] = 0;
    way[i] = 0;
  }
  for (i = 1; i<=m; i++) {
    scanf("%d %d\n", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
 // cout << 111 << endl;
  for (i = 1; i<=n; i++)
    if (!used[i]) {
      ST = i;            
      if (flag == 0) dfs(i, 0, 0);
    } 
cin.get(); cin.get();
}
