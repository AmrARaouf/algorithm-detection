//Language: GNU C++0x


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>

#define MP make_pair
#define MT make_tuple
#define PB push_back
#define FI first
#define SE second
#define INPUT "/Users/manuelalejandrovergaradiaz/Documents/Manu/Programation/Programation/Programation/autocomplete.txt"
#define OUTPUT "/Users/manuelalejandrovergaradiaz/Documents/Manu/Programation/Programation/Programation/output"
#define FILE 0

#define MAX (1<<20)
#define MAXN 1000
#define INF -1
#define EPS 0.0000001
#define MOD 1000000007
#define PI acos(-1)
#define sbit(a) a&(-a)
#define gauss(a) a*(a+1)/2
#define Node pair<int, int>

typedef long long ll;

using namespace std;

int n, m, a, b, c, q, u, v;
vector< pair<int, int> > graph[MAXN];
bool visited[MAXN];

int dfs(int node, int cur) {
    if(visited[node]) return 0;
    if(node == v) return 1;
    visited[node] = true;
    int ans = 0;
    for(int i = 0; i < graph[node].size() && ans == 0; i++)
        if(graph[node][i].SE == cur)
            ans = max(ans, dfs(graph[node][i].FI, cur));
    visited[node] = false;
    return ans;
}

int main() {
    
    if(FILE) {
        freopen(INPUT, "r", stdin);
        freopen(OUTPUT, "w", stdout);
    }
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].PB(MP(b,c));
        graph[b].PB(MP(a,c));
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> u >> v;
        int ans = 0;
        for(int i = 1; i <= m; i++)
            ans += dfs(u, i);
        cout << ans << endl;
    }
    
    return 0;
}
