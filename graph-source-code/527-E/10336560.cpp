//Language: GNU C++


#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

const int N = 1e5 + 5;
multiset<int> g[N];
int cv[N];

vector<int> euler;
void dfs(int v) {
    while(!g[v].empty()) {
        int to = *g[v].begin();
        g[v].erase(g[v].begin());
        if (to != v)
            g[to].erase(g[to].find(v));
        dfs(to);
    }
    euler.push_back(v);
}

int main() {
    #ifdef CONTEMPLATOR
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    #endif // CONTEMPLATOR
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        if (a != b)
            g[b].insert(a);
        cv[a]++, cv[b]++;
    }
    vector<int> bad;
    for (int i = 0; i < N; i++)
        if (cv[i] & 1)
            bad.push_back(i);
    for (size_t i = 0; i < bad.size(); i += 2) {
        m++;
        g[bad[i]].insert(bad[i+1]);
        g[bad[i+1]].insert(bad[i]);
    }
    if (m & 1) {
        m++;
        g[1].insert(1);
    }
    dfs(1);
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        int a = euler[i];
        int b = euler[i+1];
        if (i & 1) swap(a, b);
        cout << a << " " << b << "\n";
    }

    return 0;
}
