//Language: GNU C++


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <list>
#include <set>
#include <deque>
#include <cstring>
using namespace std;

int comp[100001];

int find(int ver)
{
  if(comp[ver] != ver) comp[ver] = find(comp[ver]);
  return comp[ver];
}

int main()
{
  int n,m,a,b;
  const int mod = 1000000009;
  cin >> n >> m;
  long kol = 1;
  for(int i = 1; i<=n; i++) comp[i] = i;
  for(int i = 0; i < m; i++)
  {
    scanf("%d%d",&a, &b);
    a = find(a);
    b = find(b);
    if (a == b) kol=(kol*2)%mod;
    else
    {
      comp[b] = a;
    }
    printf("%d\n", (kol - 1)%mod);
  }
  //system("PAUSE");
}

