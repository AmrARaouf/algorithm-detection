//Language: GNU C++


#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define PB push_back
#define MP make_pair

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

int n, k, a[1014][1014], mp, cn;

void mke(int f, int t)
{
  a[f][t] = a[t][f] = 1;
}

int main ()
{
  n = 1000;
  FOR(i, 0, 1014) MM(a[i], 0);
  cn = 301;
  mp = 201;
  FOR(i, 0, 10)
  {
    FOR(j, 0, i)
    {
      FOR(k, 0, 10)
      {
        mke(mp, cn);
        mke(cn, mp + 1);
        ++cn;
      }
      ++mp;
    }
    FOR(j, i + 1, 10)
    {
      mke(mp, cn);
      mke(cn, mp + 1);
      ++cn;
      ++mp;
    }
    mke(2, mp);
    ++mp;
  }
  scanf("%d", &k);
  mp = 100;
  while (k)
  {
    int rem = k % 10;
    k /= 10;
    FOR(i, 1, rem + 1) mke(1, mp + i);
    FOR(i, 1, 11) mke(mp + i, mp + 100 + 1);
    mp += 10;
  }
  printf("%d\n", n);
  FOR(i, 1, n + 1)
  {
    FOR(j, 1, n + 1) printf("%c", a[i][j] ? 'Y' : 'N');
    printf("\n");
  }
  return 0;
}
