//Language: GNU C++0x


#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool pairCompare(const std::pair<int,set<int> > & x, const std::pair<int,set<int> > & y) {
    return x.second.size() < y.second.size();
}

void solve(istream &in, ostream &out)
{
  int n, m;
  in >> n >> m;
  vector<int> c(n);
  map<int, set<int> > cl;
  for (int i = 0; i < n; ++i) {
    in >> c[i];
    cl[c[i]] = set<int>();
  }

  for (int i = 0; i < m; ++i) {
    int from, to;
    in >> from >> to;
    --from, --to;

    if (c[from] != c[to]) {
      cl[c[from]].insert(c[to]);
      cl[c[to]].insert(c[from]);
    }
  }
  
  out << max_element(cl.begin(), cl.end(), pairCompare)->first;
}

int main() {
  solve(cin, cout);
  return 0;
}
