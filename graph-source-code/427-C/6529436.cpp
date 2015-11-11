//Language: GNU C++


#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

#define MAXN  100005
#define MOD 1000000007
#define Min(a, b)  ((a) < (b) ? (a) : (b))

vector <int> adj[MAXN], con, idx, lowlink, in_stack;

vector < vector <int> > C;

int cost[MAXN];

stack <int> S;

int indecs;

void tarjan(const int n, const vector <int>* adj)
{
    idx[n] = lowlink[n] = indecs;
    indecs ++;
    S.push(n), in_stack[n] = 1;

    vector <int>::const_iterator it;
    for (it = adj[n].begin(); it != adj[n].end(); ++ it) {
        if (idx[*it] == -1)
            tarjan(*it, adj),
            lowlink[n] = Min(lowlink[n], lowlink[*it]);
        else if (in_stack[*it])
            lowlink[n] = Min(lowlink[n], lowlink[*it]);
    }
    if (idx[n] == lowlink[n]) {
        con.clear();
        int node;
        do {
            con.push_back(node = S.top());
            S.pop(), in_stack[node] = 0;
        }
        while (node != n);
        C.push_back(con);
    }
}

int main(void)
{
    int n;
    int cnt_edges, x, y;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> cost[i];

    for (cin >> cnt_edges; cnt_edges > 0; -- cnt_edges)
        cin >> x >> y,
        adj[x - 1].push_back(y - 1);

    idx.resize(n), lowlink.resize(n), in_stack.resize(n);
    idx.assign(n, -1), in_stack.assign(n, 0);
    for (int i = 0; i < n; ++ i) if (idx[i] == -1)
        tarjan(i, adj);

    long long min_cost = 0, count_all = 1;
    for (size_t i = 0; i < C.size(); ++ i) {
        long long min_partial = cost[C[i][0] + 1], count = 0;
        for (size_t j = 0; j < C[i].size(); ++ j)
            if (cost[C[i][j] + 1] < min_partial)
                min_partial = cost[C[i][j] + 1], count = 1;
            else
                if (cost[C[i][j] + 1] == min_partial)
                    ++count;
        min_cost += min_partial; count_all = (count_all * count) % MOD;
    }

    cout << min_cost << " " << count_all << "\n";
    return 0;
}
