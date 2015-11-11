//Language: GNU C++


#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>

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

int main(void) {
  int n,m;
  vector<pair<int,int> > V;
  long long nas = 0;
  long long p = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int q,w;
    cin >> q >> w;
    V.push_back(make_pair(w,q));
  }
  sort(V.begin(),V.end(),greater<pair<int,int> >());
  for (int i = 1; i <= n; i++) {
    long long need = (i*1LL*(i-1))/2LL;
    if (i-1 >= (int)V.size()) break;
    p += V[i-1].first;
    if (i%2) {
      need++;
    } else {
      need += i/2;
    }
    if (need <= n) {
      nas = max(nas,p);
    }
  }
  cout << nas << endl;
  return 0;
}
