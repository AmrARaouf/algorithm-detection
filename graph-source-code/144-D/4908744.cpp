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

const int maxn = 200200;
vector<pip> g[maxn];
int d[maxn];

int main() {
  int n,m,s; cin >> n >> m >> s; s--;
  for (int i = 0; i < m; i++) {
    int x,y,z; scanf("%d%d%d",&x,&y,&z); x--; y--;
    g[x].push_back(pip(y,z));
    g[y].push_back(pip(x,z));
  }
  int l; cin >> l;
  memset(d,0x3f,sizeof(d));
  d[s] = 0;
  // d1 + x == d2+z-x
  // 2x == d2-d1+z
  // x = (d2-d1+z)/2
  set<pip> q;
  q.insert(pip(d[s],s));
  for (;q.size();){
    int v = q.begin()->second;
    q.erase(q.begin());
    for (auto t : g[v]) {
      int p = t.first;
      int tmp = d[v] + t.second;
      if (tmp < d[p]) {
        q.erase(pip(d[p],p));
        d[p] = tmp;
        q.insert(pip(d[p],p));
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) if (d[i] == l) {
    Eo(i);
    cnt++;
  }
  for (int i = 0; i < n; i++) {
    for (auto t : g[i]) {
      int p = t.first;
      if (d[i] > d[p]) continue;
      if (d[i] == d[p] && i>p) continue;
      if (d[p] == l && d[i]+t.second==d[p]) continue;
      Eo(pip(i,p));
      Eo(pip(d[i],d[p]));
      if (d[i] >= l) continue;
      int mx2 = d[p]+d[i]+t.second;
      Eo(make_pair(make_pair(make_pair(pip(i,d[i]),pip(p,d[p])),t.second),mx2*0.5));
      if (mx2 < 2*l) continue;
      if (mx2 == 2*l) {
        Eo("!");
        cnt++;
        continue;
      }
        Eo("@");
      cnt++;
      if (d[p] < l) {
        Eo("@");
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
