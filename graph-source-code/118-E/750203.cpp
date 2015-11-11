//Language: GNU C++


#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace std;


vector<vector<int> > old_graph;
vector<vector<int> > new_graph;

set<pair<int, int> > used;
set<pair<int, int> >::iterator it1, it2;
pair<int, int> p1, p2;


vector<int> visited;
int visited_count = 0;

void dfs (int v)
{
    if (old_graph[v].size () == 0) {
        return;
    }

    while (1) {
        int u = old_graph[v][old_graph[v].size() - 1];
        old_graph[v].pop_back ();


        if (u < v) {
            p1 = make_pair (u, v);
        } else {
            p1 = make_pair (v, u);
        }

        it1 = used.find (p1);

        if (it1 == used.end ()) {
            new_graph[v].push_back (u);
            used.insert (p1);
            dfs (u);
        }
        
        if (old_graph[v].size () == 0)
            return;
    }
}


void dfs_check(int v)
{
    if (visited[v])
        return;
    visited[v] = 1;
    ++visited_count;

    for (int i = 0, sz = old_graph[v].size(); i < sz; ++i) {
        dfs_check(old_graph[v][i]);
    }
}





int main()
{
    int n, m;
    int cnt, a, b;
    int sz;

    cin >> n >> m;

    old_graph.assign (n, vector<int> ());
    new_graph.assign (n, vector<int> ());
    visited.assign (n, 0);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        old_graph[a].push_back(b);
        old_graph[b].push_back(a);
    }

    dfs (0);

    for (int i = 0; i < n; ++i) {
        sz = new_graph[i].size();
        
        for (int j = 0; j < sz; ++j) {
            old_graph[new_graph[i][j]].push_back(i);
        }
    }

    dfs_check(0);

    if (used.size() != m || visited_count != n) {
        printf ("0\n");
    } else {
        for (int i = 0; i < n; ++i) {
            sz = new_graph[i].size();

            for (int j = 0; j < sz; ++j) {
                printf ("%d %d\n", i + 1, new_graph[i][j] + 1);
            }
        }
    }

    return 0;
}
