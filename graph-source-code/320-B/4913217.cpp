//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 110

typedef vector<int> vii;
vector<vii> ke;
int n, sl=0, a[MAXN], b[MAXN];
bool tham[MAXN];

void lam()
{
  for (int i=1; i<sl; i++)
    {
      if ((a[sl]<a[i] && a[i]<b[sl]) || (a[sl]<b[i] && b[i]<b[sl]))
        {
          ke[i].push_back(sl);
        }
      if ((a[i]<a[sl] && a[sl]<b[i]) || (a[i]<b[sl] && b[sl]<b[i])) ke[sl].push_back(i);
    }
}

void dfs(int u)
{
  tham[u]=true;
  for (int i=0; i<ke[u].size(); i++)
    {
      int v=ke[u][i];
      if (!tham[v]) dfs(v);
    }
}

void nhap()
{
  scanf("%d\n", &n);
  sl=0;
  ke.assign(n+1, vii());
  for (int i=1; i<=n; i++)
    {
      int k, x, y;
      scanf("%d%d%d\n", &k, &x, &y);
      if (k==1)
        {
          sl++;
          a[sl]=x;
          b[sl]=y;
          lam();
        }
      else
        {
          memset(tham, 0, sizeof(tham));
          dfs(x);
          if (tham[y]) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;

        }
    }
}

int main()
{
  //freopen("320B.inp", "r", stdin);
  nhap();
}
