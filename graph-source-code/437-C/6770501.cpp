//Language: GNU C++0x


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
using namespace std;


#define REP(i, l, r) for(decltype(l) i = (l), __r = (r); i < __r; ++i)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SZ(c) c.size()
#define ALL(c) c.begin(), c.end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;

int main() {
    int n, m;
    cin>>n>>m;
    vector< vector<int> > nei(n);
    vector<int> w(n);
    for (auto& ww : w) cin>>ww;
    REP(i, 0, m) {
        int u, v;
        cin>>u>>v;
        --u, --v;
        nei[u].PB(v);
        nei[v].PB(u);
    }
    vector<int> order(n); 
    REP(i, 0, n) order[i] = i;
    auto cmp = [&](int u, int v) {
        return w[u] > w[v];
    };
    sort(ALL(order), cmp);

    int ans = 0;
    for (auto& u : order) {
        for (auto& v : nei[u]) {
            ans += w[v]; 
        }
        w[u] = 0;
    }
    cout<<ans<<endl;

    return 0;
}

