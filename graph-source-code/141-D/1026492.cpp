//Language: GNU C++


// D. Take-off Ramps
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN    100010

struct edge {
    int v, w, label;
    edge(int v, int w, int l = 0) { this->v = v; this->w = w; label = l; }
};

int main(int argc, char *argv[])
{
    int n, L, c = 0;
    cin >> n >> L;

    static int x[MAXN], d[MAXN], t[MAXN], p[MAXN], m[MAXN * 2];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> d[i] >> t[i] >> p[i];
        if (x[i] - p[i] >= 0 && x[i] + d[i] <= L) {
            m[c++] = x[i] - p[i];
            m[c++] = x[i] + d[i];
        }
    }
    m[c++] = 0;
    m[c++] = L;

    sort(m, m + c);
    c = unique(m, m + c) - m;

    vector<vector<edge> > e(c);
    for (int i = 1; i < c; i++) {
        int dist = m[i] - m[i - 1];
        e[i - 1].push_back(edge(i, dist));
        e[i].push_back(edge(i - 1, dist));
    }
    for (int i = 0; i < n; i++)
        if (x[i] - p[i] >= 0 && x[i] + d[i] <= L && t[i] < d[i]) {
            int src = lower_bound(m, m + c, x[i] - p[i]) - m;
            int dst = lower_bound(m, m + c, x[i] + d[i]) - m;
            e[src].push_back(edge(dst, p[i] + t[i], i + 1));
        }

    vector<pair<int, int> > pa(c);
    vector<int> dist(c, -1);
    vector<char> vi(c, 0);
    multimap<int, int> q;
    dist[0] = 0;
    q.insert(make_pair(0, 0));
    while (!q.empty()) {
        int u = q.begin()->second;
        vi[u] = 1;
        q.erase(q.begin());
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].v;
            if (vi[v]) continue;
            int d = e[u][i].w + dist[u];
            if (dist[v] < 0 || d < dist[v]) {
                pa[v] = make_pair(u, e[u][i].label);
                dist[v] = d;
                q.insert(make_pair(d, v));
            }
        }
    }

    cout << dist[c - 1] << endl;
    vector<int> r;
    for (int u = c - 1; u > 0; u = pa[u].first)
        if (pa[u].second) r.push_back(pa[u].second);
    cout << r.size() << endl;
    for (int i = r.size() - 1; i >= 0; i--)
        cout << r[i] << ' ';
    cout << endl;

    return 0;
}
