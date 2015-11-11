//Language: GNU C++0x


#pragma comment(linker, "/STACK:16777216")
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifndef ONLINE_JUDGE
#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#else
#define Eo(x)
#endif

typedef long long int64;
const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
typedef double real;
const real eps = 1e-6;
typedef pair<int64,int64> pip;

int64 gcd(int64 a, int64 b) {
  return a ? gcd(b%a,a) : b;
}

template <typename A,typename B>
ostream& operator<<(ostream& os, const pair<A,B>& p) {
                 return os << p.first << "," << p.second;
}

template <typename A>
ostream& operator<<(ostream& os, const vector<A>& v) {
                 for (int i = 0; i < v.size(); i++) {
                   os << v[i] << ";";
                 }
                 return os;
}

template <typename A>
ostream& operator<<(ostream& os, const set<A>& v) {
                 for (typename set<A>::const_iterator it = v.begin(); it != v.end(); ++it) {
                   os << *it << ";";
                 }
                 return os;
}

template <typename A, typename B>
ostream& operator<<(ostream& os, const map<A,B>& v) {
                 for (typename map<A,B>::const_iterator it = v.begin(); it != v.end(); ++it) {
                   os << it->first << "=" << it->second << ";";
                 }
                 return os;
}

inline int64 bit(int64 k) {
  return int64(1)<<k;
}

int SolveSquareEquation(real a, real b, real c, real& x1, real& x2) {
  real desc = b*b-4*a*c;
  if (desc<0) return 0;
  real sqrt_desc = sqrt(desc);
  x1 = (-b+sqrt_desc)/(2*a);
  x2 = (-b-sqrt_desc)/(2*a);
  if (desc<eps) {
    return 1;
  }
  return 2;
}

int SolveSquareEquationInt(int64 a, int64 b, int64 c, int64& x1, int64& x2) {
  int64 desc = b*b-4*a*c;
  if (desc<0) return 0;
  real sqrt_desc_r = sqrt(real(desc));
  int64 sqrt_desc = sqrt_desc_r;
  for (;sqrt_desc*sqrt_desc<desc; sqrt_desc++);
  for (;sqrt_desc*sqrt_desc>desc; sqrt_desc--);
  if (sqrt_desc*sqrt_desc != desc) {
    return 0;
  }
  int64 u1 = -b+sqrt_desc;
  int64 u2 = -b-sqrt_desc;
  int64 a2 = a*2;
  vector<int64> res;
  if (!(u1%a2)) {
    res.push_back(u1/a2);
  }
  if (!(u2%a2)) {
    res.push_back(u2/a2);
  }
  int oldsize = res.size();
  res.resize(2);
  x1=res[0];
  x2=res[1];
  return oldsize;
}

const int maxn = 110;
vector<int> g[maxn];
int was[maxn];
pip a[maxn];

int main() {
  int n; cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x,y,z; scanf("%d%d%d",&x,&y,&z);
    if (x==2) {
      y--;z--;
      memset(was,0,sizeof(was));
      was[y]=1;
      queue<int> q;
      q.push(y);
      for (;q.size();){
        int v = q.front();
        q.pop();
        for (int j = 0; j < g[v].size(); j++) {
          int p = g[v][j];
          if (!was[p]) {
            was[p]=1;
            q.push(p);
          }
        }
      }
      puts(was[z] ? "YES" : "NO");
    } else if (x==1) {
      a[cnt] = pip(y,z);
      for (int j = 0; j < cnt; j++) {
        if ((a[j].first > y && a[j].first < z) || (a[j].second > y && a[j].second < z)) {
          g[j].push_back(cnt);
        }
        if ((a[j].first < y && y < a[j].second) || (a[j].first < z && z < a[j].second)) {
          g[cnt].push_back(j);
        }
      }
      cnt++;
    } else {
      assert(0);
    }
  }
  return 0;
}
