//Language: GNU C++0x


#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, int> triple;
typedef pair<pii, pii> quad;

#define F first
#define S second

priority_queue<quad> pq;
vector<triple> ans;
vector<pii> nei[110000];
int vis[110000];
int pre[110000];
int mark[110000];

int main()
{
  int i;
  int n, m;
  scanf("%d %d", &n, &m);

  for (i = 0; i < m; i++)
  {
    int fr, to, tp;
    scanf("%d %d %d", &fr, &to, &tp);
    fr--, to--;
    nei[fr].push_back(pii(to, tp));
    nei[to].push_back(pii(fr, tp));
  }

  memset(mark, 0, sizeof mark);
  pq.push(quad(pii(0, 0), pii(0, -1)));

  while (!pq.empty())
  {
    quad nx = pq.top();
    pq.pop();
    
    if (vis[nx.S.F])
        continue;
    vis[nx.S.F] = 1;
    pre[nx.S.F] = nx.S.S;

    for (auto it : nei[nx.S.F])
      pq.push(quad(pii(nx.F.F - 1, nx.F.S - 1 + it.S), pii(it.F, nx.S.F)));
  }

  int cur = n - 1, prev = -1;
  while (1)
  {
    for (auto it : nei[cur])
    {
      if (it.F != prev && it.F != pre[cur])
      {
        if (it.S)
          ans.push_back(triple(pii(min(cur, it.F), max(cur, it.F)), 0));
      }
      else
      {
        if (!it.S)
          ans.push_back(triple(pii(min(cur, it.F), max(cur, it.F)), 1));
      }
    }

    mark[cur] = 1;
    if (cur == 0)
      break;
    prev = cur;
    cur = pre[cur];
  }

  for (i = 0; i < n; i++)
    if (!mark[i])
      for (auto it : nei[i])
        if (it.S)
          ans.push_back(triple(pii(min(i, it.F), max(i, it.F)), 0));

  sort(ans.begin(), ans.end());
  auto tmp = unique(ans.begin(), ans.end());
  ans.resize(distance(ans.begin(), tmp));

  printf("%d\n", (int)ans.size());
  for (auto it : ans)
    printf("%d %d %d\n", it.F.F + 1, it.F.S + 1, it.S);
  
  return 0;
}
