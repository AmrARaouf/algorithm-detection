//Language: GNU C++


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
//#include "print.hpp"

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;

class UnionFind{
public:
  UnionFind(int _n):n(_n){
    par.resize(n);
    for(int i = 0;i<n;i++){
      par[i] = i;
    }
    rank.resize(n, 0);
  }

  int find(int x){
    if(par[x] == x){
      return x;
    }else{
      return par[x] = find(par[x]);
    }
  }

  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(rank[x] < rank[y]){
      par[x] = y;
    }else{
      par[y] = x;
    }
    if(rank[x] == rank[y]) rank[x]++;
  }
  bool same(int x, int y){
    return find(x) == find(y);
  }

private:
  int n;
  vector<int> par;
  vector<int> rank;

};

int main(){
  int n, m;
  while(cin >> n >> m) {
    vector<int> from(m);
    vector<int> to(m);
    vector<char> charge(m);
    rep(i, m) {
      cin >> from[i] >> to[i] >> charge[i];
      from[i]--; to[i]--;
    }

    vector<int> ans;
    UnionFind santa(n);
    UnionFind both(n);
    rep(i, m) {
      if(charge[i] == 'S') {
	santa.unite(from[i], to[i]);
      }
    }

    int s = (n-1)/2;
    int e = (n-1)/2;

    if(s + e < n -1 ) {
      cout << -1 << endl;
      continue;
    }

    rep(i, m) {
      if(charge[i] == 'M') {
	if(!santa.same(from[i], to[i])) {
	  both.unite(from[i], to[i]);
	  santa.unite(from[i], to[i]);
	  ans.pb(i);
	  e--;
	}
      }
    }

    if(e < 0) {
      cout << -1 << endl;
      continue;
    }

    rep(i, m) {
      if(e == 0) {
	break;
      }
      if(charge[i] == 'M') {
	if(!both.same(from[i], to[i])) {
	  both.unite(from[i], to[i]);
	  e--;
	  ans.pb(i);
	}
      }
    }

    rep(i, m) {
      if(s == 0) {
	break;
      }
      if(charge[i] == 'S') {
	if(!both.same(from[i], to[i])) {
	  both.unite(from[i], to[i]);
	  s--;
	  ans.pb(i);
	}
      }
    }

    if(s != 0 || e != 0) {
      cout << -1 << endl;
    }else {
      cout << ans.size() << endl;
      for(int i = 0; i < ans.size(); i++) {
	cout << ans[i]+1 << " ";
      }
      cout << endl;
    }

  }
  return 0;
}
