//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cctype>
#include <bitset>
#include <ctime>
#include <cassert>
#include <fstream>
#include <complex>
#include <iomanip>
using namespace std;

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define ff first
#define ss second
#define ei else if
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const ld EPS = 1e-7;
const ld PI  = 3.141592653589793;

const int MAX_N = 112345, MAX_M = 312345, MOD = int(1e9)+7;
int  N, M, C[MAX_N], tsort[MAX_N], tsort_p = 0, cc[MAX_N], used[MAX_N];
int ch[MAX_N], m[MAX_N];
vector<int> g[MAX_N], rev[MAX_N];

void input() {
  cin >> N;
  for(int i = 0; i < N; ++i) {
    int num; cin >> num;
    C[i] = num;
  }

  cin >> M;
  for(int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    g[a].pb(b); rev[b].pb(a);
  }
}

void dfs_ts(int v) {
  used[v] = 1;
  for(int i = 0; i < g[v].size(); ++i)
    if(!used[g[v][i]])
      dfs_ts(g[v][i]);
  tsort[tsort_p++] = v;
}

int c = 0;
void dfs2(int v) {
  used[v] = 1;
  cc[v] = c;
  for(int i = 0; i < rev[v].size(); ++i)
    if(!used[rev[v][i]]) dfs2(rev[v][i]);
}

void compress() {
  for(int i = 0; i < N; ++i)
    if(!used[i]) dfs_ts(i);
  memset(used, 0, sizeof(used));
  
  /*
  for(int i = 0; i < N; ++i)
    cout << tsort[i] << ' ';
  cout << '\n';
  */

  for(int i = tsort_p - 1; i >= 0; --i) {
    int v = tsort[i];
    if(!used[v]) {
      dfs2(v);
      c++;
    }
  }
  /*
  for(int i = 0; i < N; ++i)
    cout << cc[i] << ' ';
  cout << '\n';
  */
}

void calc() {
  for(int i = 0; i < N; ++i) m[i] = INT_MAX;
  for(int i = 0; i < N; ++i) {
    m[cc[i]] = MIN(m[cc[i]], C[i]);
  }
  for(int i = 0; i < N; ++i)
    if(C[i] == m[cc[i]]) ch[cc[i]]++;
  
  ull sum = 0, prod = 1;
  for(int i = 0; i < c; ++i) {
    sum += m[i];
    prod = (prod * ch[i]) % MOD;
  }
  cout << sum << ' ' << prod % MOD << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  
  input();
  compress();
  calc();

  return 0;
}
