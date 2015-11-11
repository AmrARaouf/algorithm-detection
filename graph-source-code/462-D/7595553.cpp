//Language: GNU C++0x


#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define ll long long
using namespace std;
int const M = 1000000007, N = 150000;
ll dp[N][2];
vector<int> E[N];
int C[N];

void dfs(int i, int rt)
{
  vector<int> son;
  int j;
  for (j = 0; j < E[i].size(); j++)
    if (E[i][j] != rt){
      dfs(E[i][j], i);
      son.push_back(E[i][j]);
    }
  if (C[i]) {
    dp[i][0] = 0;
    dp[i][1] = 1;
    for (j = 0; j < son.size(); j++) dp[i][1] = dp[i][1] * (dp[son[j]][0] + dp[son[j]][1]) % M;
  } else {
    ll sum = 1;
    vector<ll> suml(son.size()), sumr(son.size());
    for (j = 0; j < son.size(); j++) {
      sum = sum * (dp[son[j]][0] + dp[son[j]][1]) % M;
      suml[j] = sum;
    }
    dp[i][0] = sum;
    sum = 1;
    for(j = son.size() - 1; j >= 0; j--) {
      sum = sum * (dp[son[j]][0] + dp[son[j]][1]) % M;
      sumr[j] = sum;
    }
    for (j = 0; j < son.size(); j++)
      dp[i][1] = (dp[i][1] + (j > 0 ? suml[j - 1] : 1) * (j < son.size() - 1 ? sumr[j + 1] : 1) % M * dp[son[j]][1] % M) % M;
  }
}
int main()
{
  int n, i, j;
  cin >> n;
  for (i = 1; i < n; i ++) {
    cin >> j;
    E[j].push_back(i);
    E[i].push_back(j);
  }
  for (i = 0; i < n; i ++) cin >> C[i];
  dfs(0, -1);
  cout << dp[0][1] << endl;
  return 0;
}
