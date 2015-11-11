//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for((i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;

const double EPS = 1e-10;
const int INF = 1e+9;

const int N = 10000;
int n, m;
int dp[N*2+10];

void dfs(int i, int cnt) {

  if (dp[i] == -1)
    dp[i] = cnt;
  else {
    if (dp[i] <= cnt)
      return;
    else
      dp[i] = cnt;
  } 

  if (i == m)
    return;

  if (i>0 && i<m)
    dfs(i*2, cnt+1);
  if (i>0)
    dfs(i-1, cnt+1);

  return;
}

int main() {
  for (int i=0; i<=N; i++) dp[i] = -1;
  scanf("%d%d ", &n, &m);
  dfs(n, 0);

  printf("%d\n", dp[m]);

  return 0;
}
