//Language: GNU C++


#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

// TEMPLATE {{{
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;

struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

char tolow(char c) {
  if ('A' <= c && c <= 'Z') c = (char)(c+'a'-'A');
  return c;
}

void tolow(string & s) {
  for (int i = 0; i < (int)s.size(); i++) {
    s[i] = tolow(s[i]);
  }
}

int count(const string & s) {
  int cnt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'r') cnt++;
  }
  return cnt;
}

map<string,int> FF;
vector<string> EE;
int ML[333333];
int MC[333333];
vector<int> G[333333];
bool u[333333];

void dfs(int v) {
  //merr << "in " << v << '\n';
  u[v] = 1;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int vv = G[v][i];
    if (!u[vv]) {
      dfs(vv);
    }
    if (MC[vv] < MC[v] || (MC[vv] == MC[v] && ML[vv] < ML[v])) {
      MC[v] = MC[vv];
      ML[v] = ML[vv];
    }
  }
  //merr << "out " << v << '\n';
}

int main(void) {
  int n,m;
  vector<string> V;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    tolow(s);
    V.push_back(s);
    if (FF.find(s) == FF.end()) {
      FF[s] = (int)EE.size();
      ML[EE.size()] = (int)s.size();
      MC[EE.size()] = count(s);
      EE.push_back(s);
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a,b;
    int aidx, bidx;
    cin >> a >> b;
    tolow(a);
    tolow(b);
    if (FF.find(a) == FF.end()) {
      aidx = (int)EE.size();
      FF[a] = (int)EE.size();
      ML[EE.size()] = (int)a.size();
      MC[EE.size()] = count(a);
      EE.push_back(a);
    } else {
      aidx = FF[a];
    }
    if (FF.find(b) == FF.end()) {
      bidx = (int)EE.size();
      FF[b] = (int)EE.size();
      ML[EE.size()] = (int)b.size();
      MC[EE.size()] = count(b);
      EE.push_back(b);
    } else {
      bidx = FF[b];
    }
    G[aidx].push_back(bidx);
  }
  for (int i = 0; i < (int)EE.size(); i++) {
    dfs(i);
  }
  memset(u,0,sizeof(u));
  for (int i = (int)EE.size()-1; i >= 0; i--) {
    dfs(i);
  }
  long long len = 0, cnt = 0;
  for (int i = 0; i < (int)V.size(); i++) {
    string & s = V[i];
    int idx = FF[s];
    len += ML[idx];
    cnt += MC[idx];
    //merr << ML[idx] << " " << MC[idx] << '\n';
  }
  cout << cnt << " " << len << endl;
  return 0;
}
